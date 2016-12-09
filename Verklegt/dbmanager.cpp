#include "dbmanager.h"

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../verkefni2.sqlite"); // spurning hvort það sé nóg að hafa bara nafnið á file-num
    db.open();

    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

QSqlError DbManager::lastError()
{

    return db.lastError();

}

bool DbManager::addPerson(Persons person)
{
    bool success = false;
    int id;
    QSqlQuery query;

    query.prepare("INSERT INTO Scientists (name, gender, YearOfBirth, YearOfDeath) "
                  "VALUES (:name, :gender, :YearOfBirth, :YearOfDeath)");

    QString qName = QString::fromStdString(person.getName());
    QString qGender = QString::fromStdString(person.getGender());
    QString qBirth = QString::fromStdString(person.getYearOfBirth());
    QString qDeath = QString::fromStdString(person.getYearOfDeath());

    query.bindValue(":name", qName);
    query.bindValue(":gender", qGender);
    query.bindValue(":YearOfBirth", qBirth);
    query.bindValue(":YearOfDeath", qDeath);


    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Error adding scientist: " << query.exec() <<endl;
    }


    return success;

}

bool DbManager::addComputer(Computers computer)
{
    bool success = false;
    int id;
    QSqlQuery query;

    query.prepare("INSERT INTO Computers (name, YearBuilt, Type, Built) "
                  "VALUES (:name, :YearBuilt, :Type, :Built)");

    QString qCompName = QString::fromStdString(computer.getCompName());
    QString qCompYearBuilt = QString::fromStdString(computer.getCompYearBuild());
    QString qCompType = QString::fromStdString(computer.getCompType());
    QString qCompBuilt= QString::number(computer.getCompBuilt()); // number fyrir bool breytu
    //QString qCompMemory = QString::fromStdString(computer.getCompMemory());
    //QString qCompClockSpeed = QString::fromStdString(computer.getCompClockSpeed());


    //cout << person.getName() << "!!!" <<endl;

    query.bindValue(":name", qCompName);
    query.bindValue(":YearBuilt", qCompYearBuilt);
    query.bindValue(":Type", qCompType);
    query.bindValue(":Built", qCompBuilt);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Error adding scientist: " << query.exec() <<endl;
    }
    return success;

}

bool DbManager::removeScientist(int ID)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Scientists WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool DbManager::removeComputer(int ID)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Computers WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<Persons> DbManager::readPersons(QSqlQuery query)
{
    Persons _persons;
    vector<Persons> printPersonsData;

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        string YearOfBirth = query.value("YearOfBirth").toString().toStdString();
        string YearOfDeath = query.value("YearOfDeath").toString().toStdString();

        _persons.setPersons(id, name, gender, YearOfBirth, YearOfDeath);

        printPersonsData.push_back(_persons);
    }

    return printPersonsData;
}

vector<Computers> DbManager::readComputers(QSqlQuery query)
{
    Computers _computer;
    vector<Computers> printComputersData;

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string yearBuilt = query.value("yearBuilt").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        bool built  = query.value("built").toBool();

        _computer.setComputers(id, name, yearBuilt, type, built);

        printComputersData.push_back(_computer);
    }

    return printComputersData;
}

vector<Persons>DbManager::getSinglePerson(int ID)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Scientists WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {

    }
    else
    {
        qDebug() << db.lastError() << " in function getSinglePerson" << endl;
    }
    vector<Persons> person = readPersons(query);

    return person;
}

vector<Computers>DbManager::getSingleComputer(int ID)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Computers WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {

    }
    else
    {
        qDebug() << db.lastError() << " in function getSingleComputer" << endl;
    }
    vector<Computers> computer = readComputers(query);

    return computer;
}

vector<string> DbManager::readComputersTypes()
{
   QSqlQuery query(db);
   vector<string> types;
   query.exec("SELECT DISTINCT Type FROM Computers");
   while(query.next())
   {
       string type = query.value("Type").toString().toStdString();
       types.push_back(type);
   }

   return types;
}

vector<Persons> DbManager::printAllPersons()
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM Scientists");

    return readPersons(query);
}

vector<Computers> DbManager::printAllComputers()
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM Computers");

    return readComputers(query);
}



vector<Persons> DbManager::printPersonsResults(string searchTerm, string text, int gender)
{
    QSqlQuery query;
    QString qText = QString::fromStdString(text);
    QString qSearchTerm = QString::fromStdString(searchTerm);

    if(gender != 1)
    {
        query.exec("SELECT * FROM Scientists WHERE " + qText + " LIKE '%" + qSearchTerm + "%'");
    }
    else
    {
        query.exec("SELECT * FROM Scientists WHERE " + qText + " LIKE '" + qSearchTerm + "'");
    }

    return readPersons(query);
}

vector<Computers> DbManager::printComputersResults(string searchTerm, string text)
{
    QSqlQuery query;
    QString qText = QString::fromStdString(text);
    QString qSearchTerm = QString::fromStdString(searchTerm);

    query.exec("SELECT * FROM Computers WHERE " + qText + " LIKE '%" + qSearchTerm + "%'");

    return readComputers(query);
}

vector<Persons> DbManager::sortScientistsByValue(string value, string order)
{
    QSqlQuery query(db);

    QString qValue = QString::fromStdString(value);
    QString qOrder = QString::fromStdString(order);

    if(query.exec("SELECT * FROM Scientists ORDER BY " + qValue + " " + qOrder))
    {
        cout << "Works!" << endl;
    }
    else
    {
        qDebug() << db.lastError() << endl;
    }
    return readPersons(query);
}

vector<Computers> DbManager::sortComputersByValue(string value, string order)
{
    QSqlQuery query(db);

    QString qValue = QString::fromStdString(value);
    QString qOrder = QString::fromStdString(order);

    if(query.exec("SELECT * FROM Computers ORDER BY " + qValue + " " + qOrder))
    {
        cout << "Works!" << endl;
    }
    else
    {
        qDebug() << db.lastError() << endl;
    }
    return readComputers(query);
}

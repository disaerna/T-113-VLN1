
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
    QSqlQuery query;

    query.prepare("INSERT INTO Computers (name, YearBuilt, Type, Built) "
                  "VALUES (:name, :YearBuilt, :Type, :Built)");

    QString qCompName = QString::fromStdString(computer.getCompName());
    QString qCompYearBuilt = QString::fromStdString(computer.getCompYearBuild());
    QString qCompType = QString::fromStdString(computer.getCompType());
    QString qCompBuilt= QString::number(computer.getCompBuilt()); // number fyrir bool breytu
    //QString qCompMemory = QString::fromStdString(computer.getCompMemory());
    //QString qCompClockSpeed = QString::fromStdString(computer.getCompClockSpeed());


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

void DbManager::connectComputersAndScientists(int scientistID, int computerID)
{
    int id;
    QSqlQuery query;

    query.prepare("INSERT INTO ScientistsAndComputers (ScientistID, ComputerID) "
                  "VALUES (:sID, :cID)");

    query.bindValue(":sID", scientistID);
    query.bindValue(":cID", computerID);

    if(!query.exec())
    {
        qDebug() << db.lastError() << " in connectComputersAndScientists " << endl;
    }

}

bool DbManager::removeScientist(int ID)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM Scientists WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        success = false;
    }

    return success;
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
vector<string> DbManager::readComputersAndPersons(int input)
{
    QSqlQuery query(db);
    string compName;
    string scieName;

    if( input == 2 )
    {
        vector<string> printComputersAndAllPersons;

        query.prepare("SELECT c.Name AS cname, s.Name AS sname "
                      "FROM ScientistsAndComputers sc "
                      "INNER JOIN Scientists s ON s.ID = sc.ScientistID "
                      "INNER JOIN Computers c ON c.ID = sc.ComputerID "
                      "ORDER BY c.Name ASC");
        query.exec();
        while(query.next())
        {

            compName = query.value("cname").toString().toStdString();
            scieName = query.value("sname").toString().toStdString();

            printComputersAndAllPersons.push_back(compName);
            printComputersAndAllPersons.push_back(scieName);
        }
        return printComputersAndAllPersons;
    }
    if( input == 1 )
    {
        vector<string> printPersonsAndAllComputers;
\
        query.prepare("SELECT s.Name AS sname, c.Name AS cname "
                      "FROM ScientistsAndComputers sc "
                      "INNER JOIN Scientists s ON s.ID = sc.ScientistID "
                      "INNER JOIN Computers c ON c.ID = sc.ComputerID "
                      "ORDER BY s.Name ASC");
        query.exec();

        while(query.next())
        {
            scieName = query.value("sname").toString().toStdString();
            compName = query.value("cname").toString().toStdString();

            printPersonsAndAllComputers.push_back(scieName);
            printPersonsAndAllComputers.push_back(compName);

        }

        return printPersonsAndAllComputers;
    }
}
vector<int> DbManager::getComputerToScientist(int ID)
{
    vector<int> scientistId;
    QSqlQuery query(db);
    query.prepare("SELECT ScientistID FROM ScientistsAndComputers WHERE ComputerID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        while(query.next())
        {
            scientistId.push_back(query.value("ScientistID").toUInt());
        }
    }
    else
    {
        qDebug() << db.lastError() << " in function getComputerToScientist" << endl;
    }
    return scientistId;
}
vector<int> DbManager::getScientistToComputer(int ID)
{
    vector<int> computerId;
    QSqlQuery query(db);
    query.prepare("SELECT ComputerID FROM ScientistsAndComputers WHERE ScientistID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        while(query.next())
        {
            computerId.push_back(query.value("ComputerID").toUInt());
        }
    }
    else
    {
        qDebug() << db.lastError() << " in function getScientistToComputer" << endl;
    }
    return computerId;
}
vector<int> DbManager::getIDs(string table)
{
    vector<int> IDs;

    QSqlQuery query(db);

    QString qTable = QString::fromStdString(table);

    query.prepare("SELECT ID FROM " + qTable);

    if(query.exec())
    {
        while(query.next())
        {

            IDs.push_back(query.value("ID").toUInt());
        }

    }

    return IDs;
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

vector<Persons> DbManager::getSinglePerson(int ID)
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
vector<Computers> DbManager::getSingleComputer(int ID)
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

    query.exec("SELECT * FROM Scientists ORDER BY " + qValue + " " + qOrder);

    return readPersons(query);
}

vector<Computers> DbManager::sortComputersByValue(string value, string order)
{
    QSqlQuery query(db);

    QString qValue = QString::fromStdString(value);
    QString qOrder = QString::fromStdString(order);

    query.exec("SELECT * FROM Computers ORDER BY " + qValue + " " + qOrder);

    return readComputers(query);
}
bool DbManager::updateScientist(int ID, string updateChoice, string newRecord)
{
    QSqlQuery query(db);
    QString qUpdateChoice = QString::fromStdString(updateChoice);
    QString qNewRecord = QString::fromStdString(newRecord);

    qDebug() << qUpdateChoice << " update choice" << endl;
    qDebug() << qNewRecord << " update record" << endl;
    qDebug() << ID << " id" << endl;

    query.prepare("UPDATE Scientists SET " + qUpdateChoice + " = '" + qNewRecord + "' WHERE id = :ID");
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
bool DbManager::updateComputer(int ID, string updateChoice, string newRecord)
{
    QSqlQuery query(db);
    QString qUpdateChoice = QString::fromStdString(updateChoice);
    QString qNewRecord = QString::fromStdString(newRecord);

    qDebug() << qUpdateChoice << " update choice" << endl;
    qDebug() << qNewRecord << " update record" << endl;
    qDebug() << ID << " id" << endl;

    query.prepare("UPDATE Computers SET " + qUpdateChoice + " = '" + qNewRecord + "' WHERE id = :ID");
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

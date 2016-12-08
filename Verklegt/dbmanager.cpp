#include "dbmanager.h"
#include <iostream>
#include <QSqlQuery>
#include <iostream>
#include "persons.h"
#include <QVariant>

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../verkefni2.sqlite"); // spurning hvort það sé nóg að hafa bara nafnið á file-num
    db.open();

    if (!db.open())
    {
        // qDebug() << db.lastError();
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

//QSqlQuery query;
//query exec(//hvað á að gera?)

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

    //cout << person.getName() << "!!!" <<endl;

    query.bindValue(":id", id);
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

    query.bindValue(":id", id);
    query.bindValue(":name", qCompName);
    query.bindValue(":YearBuilt", qCompYearBuilt);
    query.bindValue(":Type", qCompType);
    query.bindValue(":Built", qCompBuilt);
    //query.bindValue(":", id);

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

vector<string> DbManager::readComputersAndPersons(int input)
{
    if( input == 1 )
    {
        vector<string> printComputersAndAllPersons;

        query.prepare("SELECT c.Name, s.Name"
                      "FROM ScientistsAndComputers sc"
                      "INNER JOIN Scientists s ON s.ID = sc.ScientistID"
                      "INNER JOIN Computers c ON c.ID = sc.ComputerID"
                      "ORDER BY c.Name ASC")

        while (query.next())
        {
            string cname = query.value("c.Name").toString().toStdString();
            string sname = query.value("s.Name").toString().toStdString();

            printComputersAndAllPersons.push_back(cname);
            printComputersAndAllPersons.push_back(sname);
        }

        return printComputersAndAllPersons;
    }
    if( input == 2 )
    {
        vector<string> printPersonsAndAllComputers;

        query.prepare("SELECT s.Name, c.Name"
                      "FROM ScientistsAndComputers sc"
                      "INNER JOIN Scientists s ON s.ID = sc.ScientistID"
                      "INNER JOIN Computers c ON c.ID = sc.ComputerID"
                      "ORDER BY s.Name ASC")

        while (query.next())
        {
            string sname = query.value("s.Name").toString().toStdString();
            string cname = query.value("c.Name").toString().toStdString();

            printComputersAndAllPersons.push_back(sname);
            printComputersAndAllPersons.push_back(cname);
        }

        return printComputersAndAllPersons;
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

        //cout << "===" << id << name << "\t" << gender << "\t" << YearOfBirth << "\t" << YearOfDeath << "\t" << endl;
        //printPersonsData.push_back();
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

        //cout << "===" << id << name << "\t" << gender << "\t" << YearOfBirth << "\t" << YearOfDeath << "\t" << endl;
        //printPersonsData.push_back();
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

vector<Persons> DbManager::printPersonsResults(string searchTerm, int userChoice)
{
    QSqlQuery query;
    QString text1 = "";


    if(userChoice == 1) {
        text1 = "Name";
    }
    else if(userChoice == 2) {
        text1 = "Gender";
        if(searchTerm == "M" || searchTerm == "m") {
            searchTerm = "Male";
        }
        else if(searchTerm == "F" || searchTerm == "f") {
            searchTerm = "Female";
        }
    }
    else if(userChoice == 3) {
        text1 = "YearOfBirth";
    }
    else if(userChoice == 4) {
        text1 = "YearOfDeath";
    }



    QString qSearchTerm = QString::fromStdString(searchTerm);

    query.exec("SELECT * FROM Scientists WHERE " + text1 + " LIKE '%" + qSearchTerm + "%'");

    return readPersons(query);
}

vector<Computers> DbManager::printComputersResults(string searchTerm, int userChoice)
{
    QSqlQuery query;
    QString text1 = "";


    if(userChoice == 1)
    {
        text1 = "Name";
    }
    else if(userChoice == 2)
    {
        text1 = "YearBuilt";
    }
    else if(userChoice == 3)
    {
        text1 = "Type";
    }
    else if(userChoice == 4)
    {
        text1 = "Built";
    }

    QString qSearchTerm = QString::fromStdString(searchTerm);

    qDebug() << "qSearch: " << qSearchTerm <<endl;
    qDebug() << "text1: " << text1 <<endl;

    query.exec("SELECT * FROM Computers WHERE " + text1 + " LIKE '%" + qSearchTerm + "%'");

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

/*
void DbManager::ifExist()
{
}

void DbManager::deleteAllPersons()
{

}
*/

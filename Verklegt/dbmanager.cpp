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


bool DbManager::addPersonToScientists(Persons person)
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

bool DbManager::newComputer(Computers computer)
{
    bool success = false;
    int id;
    QSqlQuery query;

    query.prepare("INSERT INTO Computers (name, YearBuilt, Type, Built) "
                  "VALUES (:name, :YearBuilt, :Type, :Built)");

    QString qCompName = QString::fromStdString(computer.getCompName());
    QString qCompYearBuilt = QString::fromStdString(computer.getCompYearBuild());
    QString qCompType = QString::fromStdString(computer.getCompType());
    QString qCompBuilt= QString::fromStdString(computer.getCompBuilt());
    //QString qCompMemory = QString::fromStdString(computer.getCompMemory());
    //QString qCompClockSpeed = QString::fromStdString(computer.getCompClockSpeed());


    //cout << person.getName() << "!!!" <<endl;

    query.bindValue(":id", id);
    query.bindValue(":Computer name", qCompName);
    query.bindValue(":Year of building", qCompYearBuilt);
    query.bindValue(":Type", qCompType);
    query.bindValue(":Was is the build succsessfull", qCompBuilt);
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

vector<Persons> DbManager::printAllPersons()
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM Scientists");

    return readPersons(query);
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

/*
void DbManager::ifExist()
{
}

void DbManager::deleteAllPersons()
{

}
*/

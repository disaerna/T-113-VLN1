#include "dbmanager.h"
#include <iostream>
#include <QSqlQuery>
#include <iostream>
#include "persons.h"
#include <QVariant>

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkefni2.sqlite"); // spurning hvort það sé nóg að hafa bara nafnið á file-num
    db.open();

    /*QSqlQuery query;
    query.exec("create table person"
               "(id integer primary key, "
               "firstname varchar(20), "
               "lastname varchar(30), "
               "age integer)");
    */
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

void DbManager::setValues(string name, string gender, string birth, string death)
{
    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
}
//QSqlQuery query;
//query exec(//hvað á að gera?)


bool DbManager::addPersonToScientists()
{
    bool success = false;
    int id;
    QSqlQuery query;

    query.prepare("INSERT INTO Scientists (name, gender, YearOfBirth, YearOfDeath) "
                  "VALUES (:name, :gender, :YearOfBirth, :YearOfDeath)");

    QString qName = QString::fromStdString(_name);
    QString qGender = QString::fromStdString(_gender);
    QString qBirth = QString::fromStdString(_birth);
    QString qDeath = QString::fromStdString(_death);

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



/*void DbManager::removeFromScientist()
{

}

void DbManager::printAllPerson()
{

}

void DbManager::ifExist()
{

}

void DbManager::deleteAllPersons()
{

}
*/

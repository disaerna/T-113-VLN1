#include "dbmanager.h"
#include <iostream>
#include <QSqlQuery>

#include "persons.h"
#include <QVariant>

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkefni2.sqlite"); // spurning hvort það sé nóg að hafa bara nafnið á file-num
    //db.open();

    if (!db.open())
    {
        qDebug() << db.lastError();
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


void DbManager::addPersonToScientists()
{
       QSqlQuery query;
       query.prepare("INSERT INTO Scientists (name, gender, YearOfBirth, YearOfDeath) "
                     "VALUES (:name, :gender, :YearOfBirth, :YearOfDeath)");

       string name = _persons.getName();
       string gender = _persons.getGender();
       string birth = _persons.getYearOfBirth();
       string death = _persons.getYearOfDeath();

       QString qName = QString::fromStdString(name);
       QString qGender = QString::fromStdString(gender);
       QString qBirth = QString::fromStdString(birth);
       QString qDeath = QString::fromStdString(death);
       
       int id;

       query.bindValue(":id", id);
       query.bindValue(":name", qName);
       query.bindValue(":gender", qGender);
       query.bindValue(":YearOfBirth", qBirth);
       query.bindValue(":YearOfDeath", qDeath);

       qDebug() << query.exec() <<endl;

       query.exec();

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

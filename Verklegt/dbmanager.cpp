#include "dbmanager.h"
#include <iostream>
#include <QSqlQuery>

#include "persons.h"
#include <QVariant>

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkefni2(1).sqlite"); // spurning hvort það sé nóg að hafa bara nafnið á file-num
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

       string name = "vikak";
       //query.bindValue(":id", id);
       query.bindValue(":name", name);
       //query.bindValue(":gender", _persons.getGender());
       //query.bindValue(":YearOfBirth", _persons.getYearOfBirth());
      // query.bindValue(":YearOfDeath", _persons.getYearOfDeath());

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

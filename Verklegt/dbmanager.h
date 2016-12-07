#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "persons.h"
#include "computers.h"+
#include <QtSql>
#include <QSqlDatabase>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

using namespace std;


class DbManager
{
public:
    DbManager();
    QSqlError lastError();
    bool addPersonToScientists(Persons person);
    vector<Persons> printAllPersons();
    vector<Persons> readPersons(QSqlQuery query);
    vector<Persons> sortScientistsByValue(string value, string order);
    bool removeScientist(int ID);
    vector<Persons> getSinglePerson(int ID);

    //Computer Functions
    bool newComputer (Computers computer);


private:
    QSqlDatabase db;
    QSqlQuery query;

};

#endif // DBMANAGER_H

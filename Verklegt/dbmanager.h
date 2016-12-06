#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "persons.h"
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
    bool addPersonToScientists();
    void setValues(string name, string gender, string birth, string death);

private:
    QSqlDatabase db;
    QSqlQuery query;

    Persons _persons;

    string _name;
    string _gender;
    string _birth;
    string _death;

};

#endif // DBMANAGER_H

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
    void addPersonToScientists();

private:
    QSqlDatabase db;
    QSqlQuery query;

    Persons _persons;
};

#endif // DBMANAGER_H

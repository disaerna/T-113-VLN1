#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "persons.h"
#include "computers.h"
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

    //Person Functions
    bool addPerson(Persons person);
    vector<Persons> printAllPersons();
    vector<Persons> readPersons(QSqlQuery query);
    vector<Persons> sortScientistsByValue(string value, string order);
    bool removeScientist(int ID);
    vector<Persons> getSinglePerson(int ID);
    vector<Persons> printPersonsResults(string searchTerm, int userChoice);

    //Computer Functions
    bool addComputer(Computers computer);
    vector<Computers> printAllComputers();
    vector<Computers> readComputers(QSqlQuery query);
    vector<Computers> sortComputersByValue(string value, string order);
    bool removeComputer(int ID);
    vector<Computers> getSingleComputer(int ID);
    vector<Computers> printComputersResults(string searchTerm, int userChoice);


private:
    QSqlDatabase db;
    QSqlQuery query;

};

#endif // DBMANAGER_H

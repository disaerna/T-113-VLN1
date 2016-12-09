#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "persons.h"
#include "computers.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include <QSqlQuery>
#include <vector>

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
    vector<Persons> printPersonsResults(string searchTerm, string text, int gender);
    vector<int> getScientistToComputer(int ID);




    //Computer Functions
    bool addComputer(Computers computer);
    vector<Computers> printAllComputers();
    vector<Computers> readComputers(QSqlQuery query);
    vector<Computers> sortComputersByValue(string value, string order);
    bool removeComputer(int ID);
    vector<Computers> getSingleComputer(int ID);
    vector<Computers> printComputersResults(string searchTerm, string text);
    vector<string> readComputersAndPersons(int input);
    vector<string> readComputersTypes();
    vector<int> getComputerToScientist(int ID);

    void connectComputersAndScientists(int scientistID, int computerID);
    bool updateScientist(int ID, string updateChoice, string newRecord);
    bool updateComputer(int ID, string updateChoice, string newRecord);



private:
    QSqlDatabase db;
    QSqlQuery query;

};

#endif // DBMANAGER_H

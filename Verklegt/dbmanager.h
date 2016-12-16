#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "persons.h"
#include "computers.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QVariant>
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
    int addPerson(Persons person);
    vector<Persons> printAllPersons();
    vector<Persons> readPersons(QSqlQuery query);
    bool removeScientist(int ID);
    vector<Persons> getSinglePerson(int ID);
    vector<Persons> printPersonsResults(string searchTerm, int gender);
    vector<int> getScientistToComputer(int ID);


    //Computer Functions
    int addComputer(Computers computer);
    vector<Computers> printAllComputers();
    vector<Computers> readComputers(QSqlQuery query);
    bool removeComputer(int ID);
    vector<Computers> getSingleComputer(int ID);
    vector<Computers> printComputersResults(string searchTerm, bool trueOrFalse, int type);
    vector<string> readComputersAndPersons(int input);
    vector<string> readComputersTypes();
    vector<int> getComputerToScientist(int ID);
    void updateRelations(int oldScientist,int oldComputer,int newScientist,int newComputer);
    void removeRelation(int sciId, int compId);

    void connectComputersAndScientists(int scientistID, int computerID);
    bool removeConnections(string column, int removeID);


    vector<int> getIDs(string table);

    bool updateScientist(int ID, string name, string gender, string yob, string yod);
    bool updateComputer(int ID,string name, string yearbuilt, string type, bool built);



private:
    QSqlDatabase db;
    QSqlQuery query;

};

#endif // DBMANAGER_H

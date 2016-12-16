#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctime>

#include "persons.h"
#include "computers.h"
#include "dbmanager.h"

using namespace std;

class Domain
{

public:

    Domain();

    // Functions for computers class
    vector<Computers> getComputers();
    int addComputer (Computers computer);
    bool deleteComputerFromDatabase(int ID);
    Computers getSingleComputer(int ID);
    vector<string> getComputersTypes();
    vector<Computers> getComputersSearch(string searchTerm);
    bool updateComputer(int ID,string name, string yearbuilt, string type, bool built);

    // Functions for persons class
    int addPersons(Persons person);
    bool deletePersonFromFile(int ID);
    vector<Persons> getPersons();
    Persons getSinglePerson(int ID);
    vector<Persons> getPersonsSearch(string searchTerm);
    bool updatePerson(int id, string name, string gender, string yob, string yod);


    // Functions for connecting
    vector<Computers> getScientistToComputer(int ID);
    vector<Persons> getComputerToScientist(int ID);
    void connectComputersAndScientists(int scientistID, int computerID);
    bool deleteConnections(string column, int ID);
    void updateRelations(int oldScientist,int oldComputer,int newScientist,int newComputer);
    void removeRelation(int sciId, int compId);


    // Functions for error checking input
    bool validNameCheck(string name);
    bool validComputerNameCheck(string name);
    bool validYearCheck(string year);
    bool validDeathYearCheck(string birth, string death);
    string currentYear(); // Gets current year

private:

    DbManager _DbManager;
    Persons person;

};

#endif // DOMAIN_H

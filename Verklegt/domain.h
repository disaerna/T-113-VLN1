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
    bool validDeleteOfComputer(int number);
    bool deleteComputerFromDatabase(int ID);
    int wasBuiltCheck (string answer);
    Computers getSingleComputer(int ID);
    vector<string> getComputersTypes();
    vector<Computers> getComputersSearch(string searchTerm);
    bool updateComputer(int ID,string name, string yearbuilt, string type, bool built);
    string changeComputerUpdateChoice(string x);

    // Functions for persons class
    int addPersons(Persons person);
    bool deletePersonFromFile(int ID);
    vector<Persons> getPersons();
    Persons getSinglePerson(int ID);
    vector<Persons> getPersonsSearch(string searchTerm);
    bool updatePerson(int id, string name, string gender, string yob, string yod);
    string changePersonUpdateChoice(string x);


    // Functions for connecting
    vector<string> getComputerAndPersons(int input);
    vector<Computers> getScientistToComputer(int ID);
    vector<Persons> getComputerToScientist(int ID);
    void connectComputersAndScientists(int scientistID, int computerID);
    bool deleteConnections(string column, int ID);
    void updateRelations(int oldScientist,int oldComputer,int newScientist,int newComputer);
    void removeRelation(int sciId, int compId);


    // Functions for error checking input
    bool validNameCheck(string name);
    bool validGenderCheck(string gender);
    bool validYearCheck(string year);
    int yesOrNoCheck(string answer); // Three option for this function. Checks if input is digit, yes or no
    bool validDeathYearCheck(string birth, string death);
    bool validID(int function, int inputID);
    string setGender(string gender); // Sets input from user M/F to Male/Female
    string currentYear(); // Gets current year
    bool validPersonUpdateChoice(string x);
    bool validUpdateGender(string x);
    bool validComputerUpdateChoice(string x);
    bool emptyStringCheck(string x);
    bool typeCheck(string x);

private:

    DbManager _DbManager;
    Persons person;

};

#endif // DOMAIN_H

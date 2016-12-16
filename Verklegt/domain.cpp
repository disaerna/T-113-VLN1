#include "domain.h"

using namespace std;

Domain::Domain()
{

}

int Domain::addPersons(Persons person)
{ 
    return _DbManager.addPerson(person);
}
int Domain::addComputer(Computers computer)
{
    return _DbManager.addComputer(computer);
}

void Domain::connectComputersAndScientists(int scientistID, int computerID)
{
    return _DbManager.connectComputersAndScientists(scientistID, computerID);
}

// Gets all persons from file, deletes person that matches input from user then rewrites.
bool Domain::deletePersonFromFile(int ID)
{
    return _DbManager.removeScientist(ID);
}

// Gets all computers from file, deletes computer that matches input from user then rewrites.
bool Domain::deleteComputerFromDatabase(int ID)
{
    return _DbManager.removeComputer(ID);
}

bool Domain::deleteConnections(string column, int ID)
{
    return _DbManager.removeConnections(column, ID);
}

vector<Persons> Domain::getPersons()
{
    return _DbManager.printAllPersons();
}

Persons Domain::getSinglePerson(int ID)
{
    vector<Persons> person = _DbManager.getSinglePerson(ID);
    if(person.size() > 0)
    {
        return person[0];
    }
    else
    {
        Persons fakePerson;
        fakePerson.setPersons(0, " ", " ", " ", " ");
        return fakePerson;
    }
}
Computers Domain::getSingleComputer(int ID)
{
    vector<Computers> computer = _DbManager.getSingleComputer(ID);
    if(computer.size() > 0)
    {
        return computer[0];
    }
    else
    {
        Computers fakeComputer;
        fakeComputer.setComputers(0, " ", " ", " ", 0);
        return fakeComputer;
    }
}

vector<Computers> Domain::getComputers()
{
    return _DbManager.printAllComputers();
}

vector<string> Domain::getComputersTypes()
{
    return _DbManager.readComputersTypes();
}

vector<Persons> Domain::getPersonsSearch(string searchTerm)
{
    int gender = 0;
    if(searchTerm == "Male" || searchTerm == "male" || searchTerm == "Female" || searchTerm == "female")
    {
        gender = 1;
    }
    else
    {
        gender = 2;
    }

    return _DbManager.printPersonsResults(searchTerm, gender);
}

vector<Computers> Domain::getComputersSearch(string searchTerm)
{
    bool trueOrFalse = 0;
    int type = 2;

    if(searchTerm == "true"|| searchTerm == "True" || searchTerm == "TRUE")
    {
        trueOrFalse = 1; // true
        type = 1;
    }
    else if(searchTerm == "false" || searchTerm == "False" || searchTerm == "FALSE")
    {
        trueOrFalse = 0; // false
        type = 1;
    }
    else
    {
        type = 2;
    }

    return _DbManager.printComputersResults(searchTerm, trueOrFalse, type);
}

vector<Computers> Domain::getScientistToComputer(int ID)
{
    vector<int> computerIDs = _DbManager.getScientistToComputer(ID);
    vector<Computers> computer;
    for(unsigned int i=0; i<computerIDs.size(); i++)
    {
        computer.push_back(_DbManager.getSingleComputer(computerIDs[i])[0]);
    }

    return computer;
}

vector<Persons> Domain::getComputerToScientist(int ID)
{
    vector<int> scientistIDs = _DbManager.getComputerToScientist(ID);
    vector<Persons> person;
    for(unsigned int i=0; i<scientistIDs.size(); i++)
    {
        person.push_back(_DbManager.getSinglePerson(scientistIDs[i])[0]);
    }

    return person;
}

// Gets current year.
string Domain::currentYear()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    string year = std::to_string(timePtr->tm_year + 1900);

    return year;
}

// Checks if input is all characters, space or -.
bool Domain::validNameCheck(string name)
{
    return (name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM -.") != std::string::npos);
}

// Checks if input is only space
bool Domain::validComputerNameCheck(string name)
{
    return (name.find_first_not_of(" ") == std::string::npos);
}

// Checks if input is all digits.
bool Domain::validYearCheck(string year)
{
    return (year.find_first_not_of("0123456789")!= std::string::npos || year.length() != 4) || year > currentYear();
}

// Checks if input is digits, if 4 digits, if death year is lower than birth year and if current year is lower than death year.
bool Domain::validDeathYearCheck(string birth, string death)
{
    if  (death.find_first_not_of("0123456789")!= std::string::npos || death.length() != 4 || death < birth || currentYear() < death )
    {
        return true;
    }
    return false;
}

bool Domain::updatePerson(int id, string name, string gender, string yob, string yod)
{
    return _DbManager.updateScientist(id, name, gender, yob, yod);
}

void Domain::updateRelations(int oldScientist,int oldComputer,int newScientist,int newComputer)
{
    return _DbManager.updateRelations(oldScientist,oldComputer,newScientist,newComputer);
}

void Domain::removeRelation(int sciId, int compId)
{
    return _DbManager.removeRelation(sciId,compId);
}

bool Domain::updateComputer(int ID,string name, string yearbuilt, string type, bool built)
{
    return _DbManager.updateComputer(ID, name, yearbuilt, type, built);
}

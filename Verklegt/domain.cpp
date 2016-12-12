#include "domain.h"

// Structs used for sorting

using namespace std;

Domain::Domain()
{
}

void Domain::addPersons(Persons person)
{
    _DbManager.addPerson(person);
}
void Domain::addComputer(Computers computer)
{
    _DbManager.addComputer(computer);
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

vector<Persons> Domain::getPersonsSearch(string searchTerm, int userChoice)
{
    string text = "";
    int gender = 0;
    if(userChoice == 1) {
        text = "Name";
    }
    else if(userChoice == 2) {
        text = "Gender";
        gender = 1;
        if(searchTerm == "m") {
            searchTerm = "Male";
        }
        else if(searchTerm == "f") {
            searchTerm = "Female";
        }
    }
    else if(userChoice == 3) {
        text = "YearOfBirth";
    }
    else if(userChoice == 4) {
        text = "YearOfDeath";
    }
    return _DbManager.printPersonsResults(searchTerm, text, gender);
}

vector<Computers> Domain::getComputersSearch(string searchTerm, int userChoice)
{
    string text = "";
    if(userChoice == 1)
    {
        text = "Name";
    }
    else if(userChoice == 2)
    {
        text = "YearBuilt";
    }
    else if(userChoice == 3)
    {
        text = "Type";
    }
    else if(userChoice == 4)
    {
        text = "Built";
    }
    return _DbManager.printComputersResults(searchTerm, text);
}

vector<Computers> Domain::getScientistToComputer(int ID)
{
    vector<int> computerIDs = _DbManager.getScientistToComputer(ID);
    vector<Computers> computer;
    for(size_t i=0; i<computerIDs.size(); i++)
    {
        computer.push_back(_DbManager.getSingleComputer(computerIDs[i])[0]);
    }

    return computer;
}

vector<Persons> Domain::getComputerToScientist(int ID)
{
    vector<int> scientistIDs = _DbManager.getComputerToScientist(ID);
    vector<Persons> person;
    for(size_t i=0; i<scientistIDs.size(); i++)
    {
        person.push_back(_DbManager.getSinglePerson(scientistIDs[i])[0]);
    }

    return person;
}

vector<Persons> Domain::sortPersons(int viewInput)
{
    vector<Persons> getPerson;

    switch(viewInput)
    {

    case 1:

        // Views default
        break;

    case 2:

        // Sort name ascending
        getPerson = _DbManager.sortScientistsByValue("Name","asc");

        break;

    case 3:

        // Sort name descending
        getPerson = _DbManager.sortScientistsByValue("Name","desc");

        break;

    case 4:

        // Sort gender ascending
        getPerson = _DbManager.sortScientistsByValue("Gender","asc");

        break;

    case 5:

        // Sort gender descending
        getPerson = _DbManager.sortScientistsByValue("Gender","desc");

        break;

    case 6:

        // Sort birth year ascending
        getPerson = _DbManager.sortScientistsByValue("YearOfBirth","asc");

        break;

    case 7:

        // Sort birth year descending
        getPerson = _DbManager.sortScientistsByValue("YearOfBirth","desc");

        break;

    case 8:

        // Sort death year ascending
        getPerson = _DbManager.sortScientistsByValue("YearOfDeath","asc");

        break;

    case 9:

        // sort death year descending
        getPerson = _DbManager.sortScientistsByValue("YearOfDeath","desc");

        break;

    default:

        getPerson = _DbManager.printAllPersons(); // returns the whole database
    }

    return getPerson;
}
vector<Computers> Domain::sortComputers(int viewInput)
{
    vector<Computers> getComputer;

    switch(viewInput)
    {

    case 1:

        // Views default
        break;

    case 2:

        // Sort name descending
        getComputer = _DbManager.sortComputersByValue("Name","asc");

        break;

    case 3:

        // Sort name ascending
        getComputer = _DbManager.sortComputersByValue("Name","desc");

        break;

    case 4:

        // Sort by when built descending
        getComputer = _DbManager.sortComputersByValue("YearBuilt","asc");

        break;

    case 5:

        // Sort by when built ascending
        getComputer = _DbManager.sortComputersByValue("YearBuilt","desc");

        break;

    case 6:

        // Sort by type descending
        getComputer = _DbManager.sortComputersByValue("Type","desc");

        break;

    case 7:

        // Sort by type ascending
        getComputer = _DbManager.sortComputersByValue("Type","asc");

        break;

    case 8:

        // Sort by built successful YES
        getComputer = _DbManager.sortComputersByValue("1","desc");

        break;

    case 9:

        // Sort by built successful NO
        getComputer = _DbManager.sortComputersByValue("0","asc");

        break;

    default:

        getComputer = _DbManager.printAllComputers(); // returns the whole database
    }

    return getComputer;
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



// Checks if input is M/m or F/f.
bool Domain::validGenderCheck(string gender)
{
    if(gender == "M" || gender == "m")
    {
        return true;
    }
    if(gender == "F" || gender == "f")
    {
        return  true;
    }

    return false;
}

// Sets M/m to Male and F/f to Female.
string Domain::setGender(string gender)
{
    string fixedGender = " ";

    if(gender == "M" || gender == "m")
    {
        fixedGender = "Male  ";
    }
    if(gender == "F" || gender == "f")
    {
        fixedGender = "Female";
    }
    return fixedGender;
}

// Checks if input is all digits.
bool Domain::validYearCheck(string year)
{
    return (year.find_first_not_of("0123456789")!= std::string::npos || year.length() != 4) || year > currentYear();
}

// Chekcs input for is input a digit, is it Y or N.
int Domain::yesOrNoCheck(string answer)
{
    for(size_t i=0; i<answer.length(); i++)
    {
        if(isdigit(answer[i]) == false)
        {
            if(answer == "Y" || answer == "y")
            {
                return 1;
            }
            if(answer == "N" || answer == "n")
            {
                return 0;
            }
        }
    }
    return 2;
}

bool Domain::validID(int function, int inputID)
{
    string table;
    bool legalID = false;
    if(function == 1)
    {
        table = "Scientists";
    }
    if(function == 2)
    {
        table = "Computers";
    }

    vector<int> IDs = _DbManager.getIDs(table);

    if(!legalID)
    {

        for(size_t i=0; i<IDs.size(); i++)
        {
            if( IDs[i] == inputID)
            {
                legalID = true;
            }

        }
    }

    return legalID;

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

bool Domain::updatePerson(int ID, string updateChoice, string newRecord)
{
    return _DbManager.updateScientist(ID, updateChoice, newRecord);
}

bool Domain::validPersonUpdateChoice(string x)
{
    if(x == "n" || x == "N" || x == "g" || x == "G" || x == "b" || x == "B" || x == "d" || x == "D")
    {
        return true;
    }
    return false;
}

string Domain::changePersonUpdateChoice(string x)
{
    string y = "";
    if(x == "n" || x == "N")
    {
        y = "Name";
    }
    else if(x == "g" || x == "G")
    {
        y = "Gender";
    }
    else if(x == "b" || x == "B")
    {
        y = "YearOfBirth";
    }
    else if(x == "d" || x == "D")
    {
        y = "YearOfDeath";
    }
    return y;
}

bool Domain::validUpdateGender(string x)
{
    if(x == "Female" || x == "Male")
    {
        return true;
    }
    return false;
}

bool Domain::updateComputer(int ID, string updateChoice, string newRecord)
{
    if(updateChoice == "Built")
    {
        if(getSingleComputer(ID).getCompBuilt())
        {
            newRecord = "0";
        }
        if(!getSingleComputer(ID).getCompBuilt())
        {
            newRecord = "1";
        }
    }
    return _DbManager.updateComputer(ID, updateChoice, newRecord);
}

bool Domain::validComputerUpdateChoice(string x)
{
    if(x == "n" || x == "N" || x == "y" || x == "Y" || x == "t" || x == "T" || x == "b" || x == "B")
    {
        return true;
    }
    return false;
}

string Domain::changeComputerUpdateChoice(string x)
{
    string y = "";
    if(x == "n" || x == "N")
    {
        y = "Name";
    }
    else if(x == "y" || x == "Y")
    {
        y = "YearBuilt";
    }
    else if(x == "t" || x == "T")
    {
        y = "Type";
    }
    else if(x == "b" || x == "B")
    {
        y = "Built";
    }
    return y;
}

bool Domain::emptyStringCheck(string x)
{
    if(x != " ")
    {
        return true;
    }
    return false;
}

bool Domain::typeCheck(string x)
{
    if(x == "Micro" || x == "Mechatronic" || x == "Electronic" || x == "Analog")
    {
        return true;
    }
    return false;
}

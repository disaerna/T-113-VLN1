#include "domain.h"
#include "persons.h"
#include "computers.h"
#include "dbmanager.h"
#include <iostream>

// Structs used for sorting

using namespace std;

void Domain::printPerson()
{
    _DbManager.printAllPersons();
}

Domain::Domain()
{
}

void Domain::addPersons(Persons person)
{
    //_data.addPersonsToFile(person);
    cout << person.getName() << endl;
    if(_DbManager.addPersonToScientists(person))
    {
        cout << "Add person to dbMan success" << endl;
    }
}
void Domain::addComputer(Computers computer)
{
    //_data.addComputerToDatabase(computer);
}

// Gets all persons from file, deletes person that matches input from user then rewrites.
bool Domain::deletePersonFromFile(int ID)
{
    // passa að eyða öllun tengslum á milli tölvu og scientists ÁÐUR en eytt er úr scientists/computers töflu
    return _DbManager.removeScientist(ID);
}

// Gets all computers from file, deletes computer that matches input from user then rewrites.
/*string Domain::deleteComputerFromDatabase(int numberOfComputer)
{
    /*vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();

    string deletedPerson = getPersonFromFile[numberOfPerson-1].getName();

    getPersonFromFile.erase(getPersonFromFile.begin()+numberOfPerson - 1);

    _data.addPersonsAfterDelete(getPersonFromFile);

    return deletedPerson;*/

/*vector<úr computer klasa> getComputerFromDatabase
    getComputerFromDatabase = _data.lesa tölvur úr database

    string deleteComputer = getComputerFromDatabase[numberOfComputer-1].get fall();

    getComputerFromDatabase.erase(getComputerFromDatabase.begin()+numberOfComputer - 1);

    _data. fall adda manneskju eftir hún var eydd(getComputerFromDatabase);

    return deleteComputer

    string tempRet;
    return tempRet;

}*/


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

vector<Computers> Domain::getComputers()
{
    // return _data.readComputersFromDatabase();
    vector<Computers> tempRet;
    return tempRet;
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

        // Sort name descending
        getPerson = _DbManager.sortScientistsByValue("Name","desc");

        break;

    case 3:

        // Sort name ascending
        getPerson = _DbManager.sortScientistsByValue("Name","asc");

        break;

    case 4:

        // Sort gender descending
        getPerson = _DbManager.sortScientistsByValue("Gender","desc");

        break;

    case 5:

        // Sort gender ascending
        getPerson = _DbManager.sortScientistsByValue("Gender","asc");

        break;

    case 6:

        // Sort birth year descending
        getPerson = _DbManager.sortScientistsByValue("YearOfBirth","desc");

        break;

    case 7:

        // Sort birth year ascending
        getPerson = _DbManager.sortScientistsByValue("YearOfBirth","asc");

        break;

    case 8:

        // Sort death year descending
        getPerson = _DbManager.sortScientistsByValue("YearOfDeath","desc");

        break;

    case 9:

        // sort death yearascending
        getPerson = _DbManager.sortScientistsByValue("YearOfDeath","asc");

        break;

    default:

        cout << "Please enter a valid number!" << endl; // villutékk
    }

    return getPerson;
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
    return (name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM -") != std::string::npos);
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
    for(int i=0; i<answer.length(); i++)
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

// Chekcs input for is input a digit, is it Y or N.
int Domain::wasBuiltCheck(string answer)
{
    for(int i=0; i<answer.length(); i++)
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

// Checks if input is digits, if 4 digits, if death year is lower than birth year and if current year is lower than death year.
bool Domain::validDeathYearCheck(string birth, string death)
{
    if  (death.find_first_not_of("0123456789")!= std::string::npos || death.length() != 4 || death < birth || currentYear() < death )
    {
        return true;
    }
    return false;
}


// Checks input from user for delete function in presentation class.
/*bool Domain::validDeleteOfComputer(int number)
{
    if(number > 0 && number <= //get fall frá computer klasa().size())
    {
        return true;
    }
    return false;
}*/

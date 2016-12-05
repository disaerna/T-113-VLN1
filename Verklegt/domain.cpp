#include "domain.h"
#include "persons.h"
#include "computers.h"

// Structs used for sorting

struct PersonsNameSortingDesc {
    bool operator() (Persons i, Persons j) { return (i.getName() < j.getName() ); }
};

struct PersonsNameSortingAsc {
    bool operator() (Persons i, Persons j) { return (i.getName() > j.getName() ); }
};

struct PersonsGenderSortingDesc {
    bool operator() (Persons i, Persons j) { return (i.getGender() < j.getGender() ); }
};

struct PersonsGenderSortingAsc {
    bool operator() (Persons i, Persons j) { return (i.getGender() > j.getGender() ); }
};

struct PersonsDOBSortingDesc {
    bool operator() (Persons i, Persons j) { return (i.getYearOfBirth() < j.getYearOfBirth() ); }
};

struct PersonsDOBSortingAsc {
    bool operator() (Persons i, Persons j) { return (i.getYearOfBirth() > j.getYearOfBirth() ); }
};

struct PersonsDODSortingDesc {
    bool operator() (Persons i, Persons j) { return (i.getYearOfDeath() < j.getYearOfDeath() ); }
};

struct PersonsDODSortingAsc {
    bool operator() (Persons i, Persons j) { return (i.getYearOfDeath() > j.getYearOfDeath() ); }
};

Domain::Domain()
{
}

void Domain::addPersons(Persons person)
{
    _data.addPersonsToFile(person);
}
void Domain::addComputer(Computers computer)
{
    //_data.addComputerToDatabase(computer);
}

// Gets all persons from file, deletes person that matches input from user then rewrites.
string Domain::deletePersonFromFile(int numberOfPerson)
{
    vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();

    string deletedPerson = getPersonFromFile[numberOfPerson-1].getName();

    getPersonFromFile.erase(getPersonFromFile.begin()+numberOfPerson - 1);

    _data.addPersonsAfterDelete(getPersonFromFile);

    return deletedPerson;
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
    return _data.readPersonsFromFile();
}

vector<Computers> Domain::getComputers()
{
   // return _data.readComputersFromDatabase();
    vector<Computers> tempRet;
    return tempRet;
}

vector<Persons> Domain:: sortPersons(int viewInput)
{
    vector<Persons> getPerson = getPersons();

    switch(viewInput)
    {

    case 1:

        // Views default
        break;

    case 2:

        // Sort name descending
        PersonsNameSortingDesc des;
        std::sort(getPerson.begin(), getPerson.end(), des);
        break;

    case 3:

        // Sort name ascending
        PersonsNameSortingAsc asc;
        std::sort(getPerson.begin(), getPerson.end(), asc);
        break;

    case 4:

        // Sort gender descending
        PersonsGenderSortingDesc Gend;
        std::sort(getPerson.begin(), getPerson.end(), Gend);
        break;

    case 5:

        // Sort gender ascending
        PersonsGenderSortingAsc GendAs;
        std::sort(getPerson.begin(), getPerson.end(), GendAs);
        break;

    case 6:

        // Sort birth year descending
        PersonsDOBSortingDesc Dob;
        std::sort(getPerson.begin(), getPerson.end(), Dob);
        break;

    case 7:

        // Sort birth year ascending
        PersonsDOBSortingAsc DobAs;
        std::sort(getPerson.begin(), getPerson.end(), DobAs);
        break;

    case 8:

        // Sort death year descending
        PersonsDODSortingDesc Dod;
        std::sort(getPerson.begin(), getPerson.end(), Dod);
        break;

    case 9:

        // sort death yearascending
        PersonsDODSortingAsc DodAs;
        std::sort(getPerson.begin(), getPerson.end(), DodAs);
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

// Searches vector by name.
vector<Persons> Domain::searchName(string input)
{
    vector<Persons> vec = getPersons();
    vector<Persons> results;

    for(size_t i = 0; i < vec.size(); i++)
    {
        string str = vec[i].getName(); // str gets the string in the vector
        transform(str.begin(), str.end(), str.begin(), ::tolower); // the str string gets transformed into lower case
        transform(input.begin(), input.end(), input.begin(), ::tolower); // the input string gets transformed into lower case
        if(str.find(input) != string::npos)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
}

// Searches vector by gender.
vector<Persons> Domain::searchGender(string input)
{
    vector<Persons> vec = getPersons();
    vector<Persons> results;

    if(input == "M" || input == "m")
    {
        input = "Male  ";
    }
    if(input == "F" || input == "f")
    {
        input = "Female";
    }
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getGender() == input)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
}

// Searches vector by birth year.
vector<Persons> Domain::searchBirthYear(string input)
{
    vector<Persons> vec = getPersons();
    vector<Persons> results;

    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfBirth() == input)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
}

// Searches vector by death year.
vector<Persons> Domain::searchDeathYear(string input)
{
    vector<Persons> vec = getPersons();
    vector<Persons> results;

    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfDeath() == input)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
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
    return (year.find_first_not_of("0123456789")!= std::string::npos || year.length() != 4);
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
/*int Domain::wasBuiltCheck(string answer)
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
}*/




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
bool Domain::validDeleteOfPerson(int number)
{
    if(number > 0 && number <= getPersons().size())
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

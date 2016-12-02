#include "domain.h"
#include "persons.h"



//Raða í lista eftir því hvað notandi hefur valið.

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

void Domain::addPersons(Persons person)     //Kalla á addPersonToFile.
{
    _data.addPersonsToFile(person);
}

string Domain::deletePersonFromFile(int numberOfPerson)        //Aðgerð til að eyða manneskju úr data.txt skrá.
{
    vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();

    string deletedPerson = getPersonFromFile[numberOfPerson-1].getName();

    getPersonFromFile.erase(getPersonFromFile.begin()+numberOfPerson - 1);

    _data.addPersonsAfterDelete(getPersonFromFile);

    return deletedPerson;
}

vector<Persons> Domain::getPersons()            //Kalla á readPersonFromFile.
{
    return _data.readPersonsFromFile();
}

vector<Persons> Domain:: SortPersons(vector<Persons> getPerson, int viewInput)
{

    switch(viewInput) // fallegra að hafa switch case i þessu dæmi
    {

    case 1:
        // viewar default
        break;

    case 2:
        // sort name descending
        // hæsta fyrst
        // byrja að overwrite operator ><
        PersonsNameSortingDesc des;
        std::sort(getPerson.begin(), getPerson.end(), des);
        break;

    case 3:
        // sort name ascending
        // lægsta fyrst
        PersonsNameSortingAsc asc;
        std::sort(getPerson.begin(), getPerson.end(), asc);
        break;

     case 4:
        // sort gender descending
        PersonsGenderSortingDesc Gend;
        std::sort(getPerson.begin(), getPerson.end(), Gend);
        break;

    case 5:
        // sort gender ascending
        PersonsGenderSortingAsc GendAs;
        std::sort(getPerson.begin(), getPerson.end(), GendAs);
        break;

    case 6:
        // sort birth year desc
        PersonsDOBSortingDesc Dob;
        std::sort(getPerson.begin(), getPerson.end(), Dob);
        break;

    case 7:
        // sort birth year asc.
        PersonsDOBSortingAsc DobAs;
        std::sort(getPerson.begin(), getPerson.end(), DobAs);
        break;

    case 8:
        // sort death desc.
        PersonsDODSortingDesc Dod;
        std::sort(getPerson.begin(), getPerson.end(), Dod);
        break;

    case 9:
        // sort death asc.
        PersonsDODSortingAsc DodAs;
        std::sort(getPerson.begin(), getPerson.end(), DodAs);
        break;

    default:
        cout << "Please enter a valid number!" << endl; // villutékk
    }

    return getPerson;
}
// function that returns current year
string Domain::currentYear()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    string year = std::to_string(timePtr->tm_year + 1900);

    return year;
}

// function for searching through the name column of the vector


vector<Persons> Domain::searchGender(vector<Persons> vec, string input)    //Fall til að leita eftir kyni.
{
    vector<Persons> results;
    if(input == "M" || input == "m")
    {
        input = "Male";
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

vector<Persons> Domain::searchBirthYear(vector<Persons> vec, string byInput)      //Fall til að leita eftir fæðingarári.
{
    vector<Persons> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfBirth() == byInput)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
}

vector<Persons> Domain::searchDeathYear(vector<Persons> vec, string dyInput)      //Fall til að leita eftir dánarári.
{
    vector<Persons> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfDeath() == dyInput)
        {
            results.push_back(vec[i]);
        }
    }
    return results;
}

bool Domain::validNameCheck(string name)
{
    return (name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos);
}

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
string Domain::setGender(string gender)
{
    string fixedGender = " ";

    if(gender == "M" || gender == "m")
    {
        fixedGender = "Male";
    }
    if(gender == "F" || gender == "f")
    {
        fixedGender = "Female";
    }

    return fixedGender;
}

bool Domain::validBirthYearCheck(string year)
{
    return (year.find_first_not_of("0123456789")!= std::string::npos || year.length() != 4);
}
bool Domain::isDeadCheck(string answer)
{
    if(answer == "Y" || answer == "y")
    {
        return true;
    }
    if(answer == "N" || answer == "n")
    {
        return false;
    }
    return false;
}
int Domain::validDeathYearCheck(string birth, string death)
{
    if  (death.find_first_not_of("0123456789")!= std::string::npos || death.length() != 4 || death < birth || currentYear() < death )
    {
        return true;
    }
        return false;
}
bool Domain::validDeleteOfPerson(int number)
{
    if(number > 0 && number <= getPersons().size())
    {
        return true;
    }
    return false;
}



void Domain::setSearchInput(string input) {
    _searchInput = input;
}

string Domain::getSearchInput() {
    return _searchInput;
}

void Domain::setCommandInput(string input) {
    _commandInput = input;
}

string Domain::getCommandInput() {
    return _commandInput;
}

void Domain::setUserInput(int input) {
    _userInput = input;
}

int Domain::getUserInput() {
    return _userInput;
}

vector<Persons> Domain::searchAlgo()
{
    //vector<int> results;
    vector<Persons> results;
    vector<Persons> vec;
    vec = _data.readPersonsFromFile();

    int userChoice = getUserInput();


    string str = Domain::getSearchInput();
    string input = Domain::getSearchInput();

    for(size_t i = 0; i < vec.size(); i++)
    {
        if(userChoice == 1) {
            string str = vec[i].getName(); // str gets the string in the vector
        }
        else if(userChoice == 2) {
            string str = vec[i].getGender();
        }
        else if(userChoice == 3) {
             string str = vec[i].getYearOfBirth();
        }
        else if(userChoice == 4) {
             string str = vec[i].getYearOfDeath();
        }


        transform(str.begin(), str.end(), str.begin(), ::tolower); // the str string gets transformed into lower case
        transform(input.begin(), input.end(), input.begin(), ::tolower); // the input string gets transformed into lower case
        if(str.find(input) != string::npos)
        { // if a name matches, then the index number will be pushed back
            results.push_back(vec[i]);
        }
    }
    return results;
}






























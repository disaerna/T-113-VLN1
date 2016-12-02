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
// function that return if found
bool Domain::returnIfFound(bool isFound)
{
    if(isFound == true)
    {
        return true;
    }
    return false;
}
// give private _results vector a value
/*void Domain::setResults(vector<int> results)
{
    _results = results;
}

// get the values from results vector
vector<int> Domain::getResults()
{
    return _results;
}

// clean the vector.. return indexes in results to 0
void Domain::cleanVector(vector<int> results)
{
    results.clear();
    _results = results;
}
*/

// function for searching through the name column of the vector
vector<Persons> Domain::searchName(vector<Persons> vec, string input)
{
    //vector<int> results;
    vector<Persons> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        string str = vec[i].getName(); // str gets the string in the vector
        transform(str.begin(), str.end(), str.begin(), ::tolower); // the str string gets transformed into lower case
        transform(input.begin(), input.end(), input.begin(), ::tolower); // the input string gets transformed into lower case
        if(str.find(input) != string::npos)
        { // if a name matches, then the index number will be pushed back
            results.push_back(vec[i]);
            isFound = true;
           returnIfFound(isFound);
        }
    }
    //setResults(results); // give the results vector the values
    return results;
}

vector<Persons> Domain::searchGender(vector<Persons> vec, string input)    //Fall til að leita eftir kyni.
{
    //vector<int> results;
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
            isFound = true;
            returnIfFound(isFound);
        }
    }
    //setResults(results);
    return results;
}

vector<Persons> Domain::searchBirthYear(vector<Persons> vec, string byInput)      //Fall til að leita eftir fæðingarári.
{
    //vector<int> results;
    vector<Persons> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfBirth() == byInput)
        {
            results.push_back(vec[i]);
            isFound = true;
            returnIfFound(isFound);


        }
    }
    //setResults(results);
    return results;
}

vector<Persons> Domain::searchDeathYear(vector<Persons> vec, string dyInput)      //Fall til að leita eftir dánarári.
{
    //vector<int> results;
    vector<Persons> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfDeath() == dyInput)
        {
            results.push_back(vec[i]);
            isFound = true;
            returnIfFound(isFound);

        }
    }
    //setResults(results);
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
        fixedGender = "Male  ";
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
int Domain::isDeadCheck(string answer)
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

#include "domain.h"
#include "persons.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
                                //Rearranging the list after the order of the user.
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

void Domain::addPersons(Persons person)     //Calling addPersonToFile function.
{
    _data.addPersonsToFile(person);
}

void Domain::deletePersonFromFile(int numberOfPerson)        //Function to delete a Person from the data.txt file.
{
    vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();

    cout << getPersonFromFile.size() << endl;
    getPersonFromFile.erase(getPersonFromFile.begin()+numberOfPerson - 1);
    cout << "Order erased!" << endl;
    cout << getPersonFromFile.size() << endl;

    _data.addPersonsAfterDelete(getPersonFromFile);
}

vector<Persons> Domain::getPersons()            //Calling eadPersonFromFile function.
{
    return _data.readPersonsFromFile();
}

vector<Persons> Domain:: SortPersons(vector<Persons> getPerson, int viewInput)
{

    switch(viewInput) //Works better to have a switchcase.
    {

    case 1:
        // views default
        break;

    case 2:
        // sorts name descending.
        // highest first.
        // starts to overwrite operator ><
        PersonsNameSortingDesc des;
        std::sort(getPerson.begin(), getPerson.end(), des);
        break;

    case 3:
        // sorts names ascending.
        // lighest first.
        PersonsNameSortingAsc asc;
        std::sort(getPerson.begin(), getPerson.end(), asc);
        break;

     case 4:
        // sorts gender descending
        PersonsGenderSortingDesc Gend;
        std::sort(getPerson.begin(), getPerson.end(), Gend);
        break;

    case 5:
        // sorts gender ascending
        PersonsGenderSortingAsc GendAs;
        std::sort(getPerson.begin(), getPerson.end(), GendAs);
        break;

    case 6:
        // sorts birth year desc
        PersonsDOBSortingDesc Dob;
        std::sort(getPerson.begin(), getPerson.end(), Dob);
        break;

    case 7:
        // sorts birth year asc.
        PersonsDOBSortingAsc DobAs;
        std::sort(getPerson.begin(), getPerson.end(), DobAs);
        break;

    case 8:
        // sorts death desc.
        PersonsDODSortingDesc Dod;
        std::sort(getPerson.begin(), getPerson.end(), Dod);
        break;

    case 9:
        // sorts death asc.
        PersonsDODSortingAsc DodAs;
        std::sort(getPerson.begin(), getPerson.end(), DodAs);
        break;

    default:
        cout << "Please enter a valid number!" << endl; // Error Check
    }

    return getPerson;
}




// give private _results vector a value
void Domain::setResults(vector<int> results)
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


// function for searching through the name column of the vector
void Domain::searchName(vector<Persons> vec, string input)
{
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getName() == input)
        { // if a name matches, then the index number will be pushed back
            results.push_back(i);
        }
    }
    setResults(results); // give the results vector the values
}

void Domain::searchGender(vector<Persons> vec, string input)    //Function to search by gender.
{
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getGender() == input)
        {
            results.push_back(i);
        }
    }
    setResults(results);
}

void Domain::searchBirthYear(vector<Persons> vec, string byInput)      //Function to search by year of birth.
{
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfBirth() == byInput)
        {
            results.push_back(i);
        }
    }
    setResults(results);
}

void Domain::searchDeathYear(vector<Persons> vec, string dyInput)      //Function to search after year of death.
{
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i].getYearOfDeath() == dyInput)
        {
            results.push_back(i);
        }
    }

    setResults(results);
}


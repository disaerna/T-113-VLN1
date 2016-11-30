#include "domain.h"
#include "persons.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

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

void Domain::deletePersonFromFile(int numberOfPerson)
{
    vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();
    //for(unsigned int i = 0; i < getPersonFromFile.size(); i++)
    //{
    cout << getPersonFromFile.size() << endl;
    getPersonFromFile.erase(getPersonFromFile.begin()+numberOfPerson - 1);
    cout << "Order erased!" << endl;
    cout << getPersonFromFile.size() << endl;
    //}

    _data.addPersonsAfterDelete(getPersonFromFile);

}

vector<Persons> Domain::getPersons()
{
    return _data.readPersonsFromFile();
}

vector<Persons> Domain:: SortPersons(vector<Persons> getPerson, int viewInput)
{

    switch(viewInput) // fallegra að hafa switch case i þessu dæmi
    {

    case 1:

        return getPerson;

        break;
    case 2:
        // sort name descending
        // hæsta fyrst
        // byrja að overwrite operator ><
        PersonsNameSortingDesc des;
        std::sort(getPerson.begin(), getPerson.end(), des);

        return getPerson;
    break;
    case 3:
        // sort name ascending
        // lægsta fyrst
     PersonsNameSortingAsc asc;
     std::sort(getPerson.begin(), getPerson.end(), asc);
     return getPerson;

     break;
     case 4:
        // sort gender descending
        PersonsGenderSortingDesc Gend;
        std::sort(getPerson.begin(), getPerson.end(), Gend);
        return getPerson;
    break;
    case 5:
        // sort gender ascending
        PersonsGenderSortingAsc GendAs;
        std::sort(getPerson.begin(), getPerson.end(), GendAs);
        return getPerson;
    break;

    case 6:
        // sort birth year desc
        PersonsDOBSortingDesc Dob;
        std::sort(getPerson.begin(), getPerson.end(), Dob);
        return getPerson;
    break;

    case 7:
        // sort birth year asc.
        PersonsDOBSortingAsc DobAs;
        std::sort(getPerson.begin(), getPerson.end(), DobAs);
        return getPerson;
    break;

    case 8:
        // sort death desc.
        PersonsDODSortingDesc Dod;
        std::sort(getPerson.begin(), getPerson.end(), Dod);
        return getPerson;
    case 9:
        // sort death asc.
        PersonsDODSortingAsc DodAs;
        std::sort(getPerson.begin(), getPerson.end(), DodAs);
        return getPerson;
    break;

    default:
        cout << "Please enter a valid number!" << endl; // villutékk

    }


}


/*
 * **** Search Function

// give private _results vector a value
void Domain::setResults(vector<int> results) {
    _results = results;
}

// get the values from results vector
vector<int> Domain::getResults() {
    return _results;
}

// clean the vector.. return indexes in results to 0
void Domain::cleanVector(vector<int> results) {
    results.clear();
    _results = results;
}


// function for searching through the name column of the vector
void Domain::searchName(vector<Persons> vec, string input) {
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getName() == input) { // if a name matches, then the index number will be pushed back
            results.push_back(i);
        }
     }
    Domain::setResults(results); // give the results vector the values
}



void Domain::searchGender(vector<Persons> vec, string input) {
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getGender() == input) {
            results.push_back(i);
        }
    }
    Domain::setResults(results);
}

void Domain::searchBirthYear(vector<Persons> vec, string byInput) {
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getYearOfBirth() == byInput) {
            results.push_back(i);
        }
    }
    Domain::setResults(results);
}



void Domain::searchDeathYear(vector<Persons> vec, string dyInput) {
    vector<int> results;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getYearOfDeath() == dyInput) {
            results.push_back(i);
        }
    }
    Domain::setResults(results);
}

*/

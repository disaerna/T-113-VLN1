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

vector<Persons> Domain::getPersons()
{
    return _data.readPersonsFromFile();
}

vector<Persons> Domain:: SortPersons(vector<Persons> getPerson, int viewInput)
{
    switch(viewInput) // fallegra að hafa switch case i þessu dæmi
    {

    case '1':
        displayVector(getPerson);
        break;
    case '2':
        // sort name descending
        // hæsta fyrst
        // byrja að overwrite operator ><
        PersonsNameSortingDesc des;
        std::sort(getPerson.begin(), getPerson.end(), des);
    break;
    case '3' :
        // sort name ascending
        // lægsta fyrst
     PersonsNameSortingAsc asc;
     std::sort(getPerson.begin(), getPerson.end(), asc);
     break;
     case '4':
        // sort gender descending
        PersonsGenderSortingDesc Gend;
        std::sort(getPerson.begin(), getPerson.end(), Gend);
    break;
    case '5' :
        // sort gender ascending
        PersonsGenderSortingAsc GendAs;
        std::sort(getPerson.begin(), getPerson.end(), GendAs);
    break;

    case '6':
        // sort birth year desc
        PersonsDOBSortingDesc Dob;
        std::sort(getPerson.begin(), getPerson.end(), Dob);
    break;

    case '7' :
        // sort birth year asc.
        PersonsDOBSortingAsc DobAs
        std::sort(getPerson.begin(), getPerson.end(), DobAs);
    break;

    case '8':
        // sort death desc.
        PersonsDODSortingDesc Dod;
        std::sort(getPerson.begin(), getPerson.end(), Dod);
    case '9' :
        // sort death asc.
        PersonsDODSortingAsc DodAs;
        std::sort(getPerson.begin(), getPerson.end(), DodAs);
    break;

    default:
        cout << "Please enter a valid number!" << endl; // villutékk

    }


}


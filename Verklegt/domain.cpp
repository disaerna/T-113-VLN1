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

void Domain::deletePersonFromFile(Persons person, int numberOfPerson)
{
    vector<Persons> getPersonFromFile;
    getPersonFromFile = _data.readPersonsFromFile();
    for(unsigned int i = 0; i < getPersonFromFile.size(); i++)
    {
        getPersonFromFile.erase(getPersonFromFile.begin() + numberOfPerson-1);
        cout << "Order erased!" << endl;
    }

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

void Domain::searchName(vector<Persons>& vec, vector<int> results, int naInput) {
    for(size_t i = 0; i < vec.size(); i++) {
            if(vec[i].getGender() == naInput) {
                results.push_back(i);
            }
        }
}

void Domain::searchGender(vector<Persons>& vec, vector<int>& results, int geInput) {
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getGender() == geInput) {
            results.push_back(i);
        }
    }
}

void Domain::searchBirthYear(vector<Persons>& vec, vector<int>& results, int byInput) {
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getYearOfBirth() == byInput) {
            results.push_back(i);
        }
    }
}

void Domain::searchDeathYear(vector<Persons>& vec, vector<int>& results, int dyInput) {
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i].getYearOfDeath() == dyInput) {
            results.push_back(i);
        }
    }
}




// á eftir að cutta niður og setja í önnur föll
void searchDB() {
    // asking user to choose how he will search
    Presentation::displaySearch();

    // if user chooses 1/Search by name
    if(userChoice == 1) {
        Presentation::displaySearchName;
        Domain::searchName;
        sizeOfResults = results.size();
        // if sizeOfResults = 0, then nothing is found
        // for loop to check output
        if(sizeOfResults != 0) {
            Presentation::displaySearchResults;
        }
        else {
            Presentation::nothingFound();
        }
    }


    // if user chooses 2/Search by gender
    else if(userChoice == 2) {
        Presentation::displaySearchGender;
        Domain::searchGender;
        sizeOfResults = results.size();
        if(sizeOfResults != 0) {
            Presentation::displaySearchResults;
        }
        else {
            Presentation::nothingFound();
        }
    }



    // if user chooses 3/search by birth year
    if(userChoice == 3) {
        Presentation::displaySearchBirthYear;
        Domain::searchBirthYear;
        sizeOfResults = results.size();
        if(sizeOfResults != 0) {
            Presentation::displaySearchResults;
        }
        else {
            Presentation::nothingFound();
        }

    }

    // if user chooses 4/search by death year
    if(userChoice == 4) {
        Presentation::displaySearchDeathYear;
        Domain::searchDeathYear;
        sizeOfResults = results.size();
        if(sizeOfResults != 0) {
            Presentation::displaySearchResults;
        }
        else {
            Presentation::nothingFound();
        }
    }

    // if user chooses 5/return to main menu
    if(userChoice == 5) {
        Presentation::displaySearch();
    }
}
*/


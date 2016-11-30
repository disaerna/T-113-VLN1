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

<<<<<<< HEAD
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

=======
/*
// á eftir að cutta niður og setja í önnur föll
void searchDB(vector<Persons> vec) {
    // asking user to choose how he will search
    int userChoice = 0;
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by gender" << endl;
    cout << "3. Search by year of birth" << endl;
    cout << "4. Search by year of death" << endl;
    cout << "5. Return to main menu" << endl;
    cin >> userChoice;

    // if user chooses 1/Search by name
    if(userChoice == 1) {
        string input = " ";
        cout << "Enter a name to search: ";
        cin >> input;

        vector<int> results; // vector to keep found indexes

        // for loop to find indexes matching input
        for(size_t i = 0; i < vec.size(); i++) {
            if(vec[i].getName() == input) {
                results.push_back(i); // if index is found, it is pushed back to results vector
            }
        }

        int sizeOfResults = results.size(); // size of results vector

        // if sizeOfResults = 0, then nothing is found
        // for loop to check output
        if(sizeOfResults != 0) {
            for(int i = 0; i < sizeOfResults; i++) {
                cout << vec[i].getName() << " ";
                cout << vec[i].getGender() << " ";
                cout << vec[i].getYearOfBirth() << " ";
                cout << vec[i].getYearOfDeath() << endl;
            }
            cout << endl;
        }
        else {
            cout << "Error" << endl; // error message
        }
    }


    // if user chooses 2/Search by gender
    else if(userChoice == 2) {
        int input = 0;
        cout << "Choose one of the following to search: " << endl;
        cout << "1. Find all males" << endl;
        cout << "2. Find all females" << endl;
        cin >> input;

        vector<int> results; // vector to keep found indexes

        if(input == 1) {
            for(size_t i = 0; i < vec.size(); i++) {
                if(vec[i].getGender() == "Male" || vec[i].getGender() == "male") {
                    results.push_back(i);
                }
            }

            int sizeOfResults = results.size();

            if(sizeOfResults != 0) {
                for(int i = 0; i < sizeOfResults; i++) {
                    cout << vec[i].getName() << " ";
                    cout << vec[i].getGender() << " ";
                    cout << vec[i].getYearOfBirth() << " ";
                    cout << vec[i].getYearOfDeath() << endl;
                }
                cout << endl;
            }
            else {
                cout << "Error" << endl; // error message
            }
        }
        else if(input == 2) {
            for(size_t i = 0; i < vec.size(); i++) {
                if(vec[i].getGender() == "Female" || vec[i].getGender() == "female") {
                    results.push_back(i);
                }
            }

            int sizeOfResults = results.size();

            if(sizeOfResults != 0) {
                for(int i = 0; i < sizeOfResults; i++) {
                    cout << vec[i].getName() << " ";
                    cout << vec[i].getGender() << " ";
                    cout << vec[i].getYearOfBirth() << " ";
                    cout << vec[i].getYearOfDeath() << endl;
                }
                cout << endl;
            }
            else {
                cout << "Error" << endl; // error message
            }
        }
        else {
            // error// choose either 1 or 2
        }
    }



    // if user chooses 3/search by birth year
    if(userChoice == 3) {
        int input = 0;
        cout << "Enter a year to search: ";
        cin >> input;

        vector<int> results; // vector to keep found indexes

        for(size_t i = 0; i < vec.size(); i++) {
            if(vec[i].getYearOfBirth() == input) {
                results.push_back(i);
            }
        }

        int sizeOfResults = results.size();

        if(sizeOfResults != 0) {
            for(int i = 0; i < sizeOfResults; i++) {
                cout << vec[i].getName() << " ";
                cout << vec[i].getGender() << " ";
                cout << vec[i].getYearOfBirth() << " ";
                cout << vec[i].getYearOfDeath() << endl;
            }
            cout << endl;
        }
        else {
            cout << "Error" << endl; // error message
        }
    }

    // if user chooses 4/search by death year
    if(userChoice == 4) {
        int input = 0;
        cout << "Enter a year to search (input 0 for alive persons): ";
        cin >> input;

        vector<int> results; // vector to keep found indexes

        for(size_t i = 0; i < vec.size(); i++) {
            if(vec[i].getYearOfDeath() == input) {
                results.push_back(i);
            }
        }

        int sizeOfResults = results.size();

        if(sizeOfResults != 0) {
            for(int i = 0; i < sizeOfResults; i++) {
                cout << vec[i].getName() << " ";
                cout << vec[i].getGender() << " ";
                cout << vec[i].getYearOfBirth() << " ";
                cout << vec[i].getYearOfDeath() << endl;
            }
            cout << endl;
        }
        else {
            cout << "Error" << endl; // error message
        }
    }

    // if user chooses 5/return to main menu
    if(userChoice == 5) {
        // return to previous screen
    }

}
*/
>>>>>>> origin/master

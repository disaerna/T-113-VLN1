#include "presentation.h"
#include "persons.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

Presentation::Presentation()
{

}


void displayVector(vector<Persons> p);

void Presentation::program()
{

    cout << "Please enter one of the following commands: " << endl;
    cout << "1 - Add a new person to the database" << endl;
    cout << "2 - Delete a person from the database" << endl; // TODO - EXTRA
    cout << "3 - View the database" << endl;
    cout << "4 - Search the database" << endl;
    cout << "5 - Quit the program" << endl;

    int input = 0;

    cin >> input;

    if(input == 1) {


        Persons newPerson;
        int number = 0;
        string name1;
        string gender1;
        string yearOfBirth1;
        string yearOfDeath1;

        cout << "How many persons would you like to input: " << endl;
        cin >> number;

        for(int i=0; i<number; i++)
        {
            cout << "Enter name: ";
            cin >> name1;
            cout << "Enter gender: ";
            cin >> gender1;
            cout << "Enter year of birth: ";
            cin >> yearOfBirth1;
            cout << "If deceased enter year of death, else enter 0: ";
            cin >> yearOfDeath1;

            newPerson.setPersons(name1, gender1, yearOfBirth1, yearOfDeath1);

            _domain.addPersons(newPerson);
        }
    }

    else if(input == 2)
    {
        vector<Persons> getPerson;
        getPerson = _domain.getPersons();
        displayVector(getPerson);
        int numberOfPerson;
        cout << "Enter the number of person you wish to delete from the database: ";
        cin >> numberOfPerson;
        _domain.deletePersonFromFile(numberOfPerson);
    }
    else if(input == 3)
    {
        cout << "How would you like view the database? " << endl;
        cout << "1. Default" << endl;
        cout << "2. Name: A-Z" << endl;
        cout << "3. Name: Z-A" << endl;
        cout << "4. Gender: F-M" << endl;
        cout << "5. Gender: M-F" << endl;
        cout << "6. Birth Year: Desc." << endl;
        cout << "7. Birth Year: Asc." << endl;
        cout << "8. Death Year: Desc." << endl;
        cout << "9. Death Year: Asc." << endl;

        // allt föll inní domain ! sortera
        // öll föll hér inní þurfa að nota readPersonsFromFile fallið í data !

        int viewInput = 0;
        cin >> viewInput;

        vector<Persons> getPerson;
        getPerson = _domain.getPersons();

        displayVector(_domain.SortPersons(getPerson, viewInput));

   /* else if(input == 4)
    {
        // search the database
        // fall inní domain ! leitar
    }
    else if(input == 5)
    {
            // hætta í forriti
    }
    else
    {
            // villutékk
        cout << "Please enter a valid command!" << endl;
    }
*/

    }
}

void Presentation::displayVector(vector<Persons> p)
{
    // raða betur upp í töflu, ef t.d langt nafn
    //cout << "Fer inni displayVector" << endl;
    cout << endl;
    cout << "Nr. Name" << "\t" << "Gender" << "\t" << "Year of birth" << "\t" << "Year of death" << "\t" << endl;
    cout << "----------------------------------------------" << endl;
    for(size_t i=0; i< p.size(); i++)
    {
        cout << (i+1) << ".  " <<p[i].getName() << "\t" << p[i].getGender() << "\t" << p[i].getYearOfBirth() << "\t" << "\t" << p[i].getYearOfDeath()<< endl;
    }
}



//

int Presentation::displaySearch() {
    int userChoice = 0;
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by gender" << endl;
    cout << "3. Search by year of birth" << endl;
    cout << "4. Search by year of death" << endl;
    cout << "5. Return to main menu" << endl;
    cin >> userChoice;
    return userChoice;
}

string Presentation::displaySearchName() {
    string nameInput = " ";
    cout << "Enter a name to search: ";
    cin >> nameInput;
    return nameInput;
}

string Presentation::displaySearchGender() {
    string genderInput = " ";
    cout << "Enter 'male' for male results" << endl;
    cout << "Enter 'female' for female results" << endl;
    cin >> genderInput;
    return genderInput;
}

int Presentation::displaySearchBirthYear() {
    int birthYear = 0;
    cout << "Enter birth year";
    cin >> birthYear;
    return birthYear;
}

int Presentation::displaySearchDeathYear() {
    int deathYear = 0;
    cout << "Enter death year";
    cin >> deathYear;
    return deathYear;
}

void Presentation::displaySearchResults(vector<Persons>& vec, vector<int>& results) {
    for(size_t i = 0; i < results.size(); i++) {
        cout << vec[i].getName() << " ";
        cout << vec[i].getGender() << " ";
        cout << vec[i].getYearOfBirth() << " ";
        cout << vec[i].getYearOfDeath() << endl;
    }
    cout << endl;
    results.clear(); // clear the results vector
}

void Presentation::nothingFound() {
    cout << "Nothing found!" << endl;
}

//





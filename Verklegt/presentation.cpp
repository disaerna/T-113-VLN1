#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <functional>

#include "presentation.h"
#include "persons.h"

using namespace std;

Presentation::Presentation()
{

}

void Presentation::newPersonsinFile()
{
    Persons newPerson;
    int number = 0;
    string name1;
    string gender1;
    string yearOfBirth1;
    string yearOfDeath1;
    char answer;
    int currentYear;

    currentYear = _domain.currentYear();

    cout << "How many persons would you like to input: ";
    cin >> number;

    for(int i=0; i<number; i++)
    {
        cout << "-------------" << endl;
        cout << "Person " << i+1 << " of " << number << endl;
        cout << "-------------" << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name1); // tekur fullt nafn

        if (name1.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos)
        {
            while ( name1.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos )
            {
                cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
                cin >> name1;
            }
        }
        cout << "Enter gender: ";
        cin >> gender1;
        cout << "Enter year of birth: ";
        cin >> yearOfBirth1;
        if(stoi(yearOfBirth1)>currentYear)
        {
            cout << "You can't predict people's birth year! Please enter a valid year: ";
            cin >> yearOfBirth1;
        }
        while (yearOfBirth1.find_first_not_of("0123456789")!= std::string::npos || yearOfBirth1.length() != 4)
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth1;
        }

        cout << "Is the person deceased? Y/N: ";

        cin >> answer;
        if(answer == 'y' || answer == 'Y')
        {
            cout << "Enter year of death: ";
            cin >> yearOfDeath1;
            if(yearOfDeath1<yearOfBirth1)
            {
                cout << "Year of death must be higher or equal to year of birth." << endl;
                cout << "Enter year of death: ";
                cin >> yearOfDeath1;
            }
            while(yearOfDeath1.find_first_not_of("0123456789")!= std::string::npos || yearOfDeath1.length() != 4)
            {
                cout << "Wrong input! Please enter 4 digits: ";
                cin >> yearOfDeath1;
            }
        }
        else if(answer == 'n' || answer == 'N')
        {
            yearOfDeath1 = '-';
        }
        cout << endl;

        newPerson.setPersons(name1, gender1, yearOfBirth1, yearOfDeath1);
        _domain.addPersons(newPerson);
    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

    vector<Persons> getPerson;
    getPerson = _domain.getPersons();
    int databaseSize = getPerson.size();

    cout << "You added these people to the database: " << endl;
    cout << endl;
    for(int i = 0; i < number; i++)
    {
        cout << i+1 << ". " << getPerson[databaseSize-number+i].getName() << endl;
    }
    cout << endl;

    cout << "Going back to main screen..." << endl;
    cout << endl;
}

void Presentation::removePerson()
{
    vector<Persons> getPerson;
    getPerson = _domain.getPersons();
    displayVector(getPerson);

    int numberOfPerson;

    cout << "Enter the number of person you wish to delete from the database: ";
    cin >> numberOfPerson;

    _domain.deletePersonFromFile(numberOfPerson);
    cout << getPerson[numberOfPerson-1].getName() << " has been deleted from the database." << endl;
    cout << endl;
    inputToReturn();
}

void Presentation::viewDatabase()
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
    cout << "Enter your choice: ";
    cin >> viewInput;

    vector<Persons> getPerson;
    getPerson = _domain.getPersons();

    displayVector(_domain.SortPersons(getPerson, viewInput));

    inputToReturn();
}

void Presentation::searchDatabase()
{
    // fall inní domain ! leitar
    int userChoice = 0;
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by gender" << endl;
    cout << "3. Search by year of birth" << endl;
    cout << "4. Search by year of death" << endl;
    cout << "5. Return to main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    //  if the user chooses to search by name
    //  we need to link the Person vector to the vector
    //  we use the searchName function in the Domain class
    //  our vector results gets the indexes searchName gave us
    //  we display the results
    //  we clean the vector so that the user can search again
    if(userChoice == 1)         //Leita eftir nafni.
    {
        searchByName();
    }
    else if(userChoice == 2)            //Leita eftir kyni.
    {
        searchByGender();
    }
    else if(userChoice == 3)            //Leita eftir fæðingarári.
    {
        searchByBirthYear();
    }
    else if(userChoice == 4)            //Leita eftir dánarári.
    {
       searchByDeathYear();
    }
    else if(userChoice == 5)
    {
        cout << endl;
        cout << "Going back to main menu..." << endl;
        cout << endl;
        program();
    }
}

void Presentation::searchByName()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons(); // get the vector from file input
    vector<int> results;
    string nameInput = " ";

    cout << "Enter a name to search: ";
    cin >> nameInput;
    cout << endl;

    _domain.searchName(personVector, nameInput);
    results = _domain.getResults();
    displaySearchResults(personVector, results);
    _domain.cleanVector(results);
    inputToReturn();
}
void Presentation::searchByGender()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;
    string genderInput = " ";

    cout << "Enter 'male' for male results" << endl;
    cout << "Enter 'female' for female results" << endl;
    cin >> genderInput;

    _domain.searchGender(personVector, genderInput);
    results = _domain.getResults();
    displaySearchResults(personVector, results);
    _domain.cleanVector(results);
    inputToReturn();
}
void Presentation::searchByBirthYear()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;
    string birthYear = " ";

    cout << "Enter birth year";
    cin >> birthYear;

    _domain.searchBirthYear(personVector, birthYear);
    results = _domain.getResults();
    displaySearchResults(personVector, results);
    _domain.cleanVector(results);
    inputToReturn();
}
void Presentation::searchByDeathYear()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;
    string deathYear = " ";

    cout << "Enter death year";
    cin >> deathYear;

    _domain.searchDeathYear(personVector, deathYear);
    results = _domain.getResults();
    displaySearchResults(personVector, results);
    _domain.cleanVector(results);
    inputToReturn();
}

void Presentation::program()
{
    int input = 6;
    do
    {   //Það fyrsta sem birtist á skjá notanda.
        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new person to the database" << endl;
        cout << "2 - Delete a person from the database" << endl; // TODO - EXTRA
        cout << "3 - View the database" << endl;
        cout << "4 - Search the database" << endl;
        cout << "5 - Quit the program" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;

        if(input == 1)          //Ef valið er 1 bætist ný manneskja í database.
        {
            newPersonsinFile();
        }
        else if(input == 2)         //Ef valið er 2 eyðum við manneskju úr database.
        {
            removePerson();
        }
        else if(input == 3)   //Ef valið er 3 bjóðum við valmöguleika til að skoða database.
        {
            viewDatabase();
        }
        else if(input == 4)     // Search the database.
        {
            searchDatabase();
        }
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 5);        //Fer aftur inn í menu gluggan.
}

void Presentation::displayVector(vector<Persons> p) //Uppröðun töflu.
{
    // raða betur upp í töflu, ef t.d langt nafn
    // cout << "Fer inni displayVector" << endl;
    int maxNameSize = 0;
    for(unsigned int i=0; i<p.size(); i++)
    {
        if(p[i].getName().length() > maxNameSize )
        {
            maxNameSize = p[i].getName().length();
        }
    }
    //cout << "MaxNameSize: " << maxNameSize << endl;

    cout << endl;
    cout << "Nr.\t" << setw(30) << left << "Name"  << "Gender" << "\t" << "Born" << "\t" << "Died" << endl;
    for(int i=0; i<maxNameSize*3; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(size_t i=0; i< p.size(); i++)
    {
        cout << (i+1) << ".\t" << setw(30) << left << p[i].getName() << p[i].getGender() << "\t" << p[i].getYearOfBirth() << "\t" << p[i].getYearOfDeath()<< endl;
    }
    cout << endl;
}

// prints out only information about the indexes that match the search
// þarf að raða betur
void Presentation::displaySearchResults(vector<Persons> p, vector<int> results)
{
    int number = 0;

    int maxNameSize = 0;
    for(unsigned int i=0; i<p.size(); i++)
    {
        if(p[i].getName().length() > maxNameSize )
        {
            maxNameSize = p[i].getName().length();
        }
    }
    //cout << "MaxNameSize: " << maxNameSize << endl;

    cout << endl;
    cout << "Nr.\t" << setw(30) << left << "Name"  << "Gender" << "\t" << "Born" << "\t" << "Died" << endl;
    for(int i=0; i<maxNameSize*3; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(size_t i=0; i< results.size(); i++)
    {
        number = results[i];
        cout << (i+1) << ".\t" << setw(30) << left << p[number].getName() << p[number].getGender() << "\t" << p[number].getYearOfBirth() << "\t" << p[number].getYearOfDeath()<< endl;
    }
    cout << endl;
}

void Presentation::inputToReturn()
{
    int input = 0;
    while(input != 1)
    {
        cout << "Enter '1' to return to main menu: ";
        cin >> input;
    }
    cout << endl;
}

void Presentation::splashMessage()
{
    // endl í byrjun
    cout << endl;

    // lína uppi
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // önnur lína
    for(int i = 0; i < 1; i++)
    {
        cout << "*" << "*";
        for(int j = 0; j < 5; j++)
        {
            cout << " ";
        }
        cout << "Computer Scientists v.1.0"; // 25
        for(int j = 0; j < 6; j++)
        {
            cout << " ";
        }
        cout << "*" << "*" << endl;
    }

    // þriðja lína
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // eitt endl í lokin
    cout << endl;
}

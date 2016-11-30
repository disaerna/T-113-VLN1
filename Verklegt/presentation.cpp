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

    /*else if(input == 2)
    {
        // delete person from the database
        // fara inní nýja klasann sem sér um að deleta & adda
    }

    */
    else if(input == 3)
    {
        cout << "How would you like view the database? " << endl;
    }

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

        _domain.SortPersons(getPerson, viewInput);

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

void Presentation::displayVector(vector<Persons> p)
{
    // raða betur upp í töflu, ef t.d langt nafn
    //cout << "Fer inni displayVector" << endl;
    cout << endl;
    cout << "Nr. Name" << "\t" << "Gender" << "\t" << "Year of birth" << "\t" << "Year of death" << "\t" << endl;
    cout << "----------------------------------------------" << endl;
    for(int i=0; i< p.size(); i++)
    {

        cout << (i+1) << ".  " <<p[i].getName() << "\t" << p[i].getGender() << "\t" << p[i].getYearOfBirth() << "\t" << "\t" << p[i].getYearOfDeath()<< endl;
    }
}





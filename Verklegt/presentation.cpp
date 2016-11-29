#include "presentation.h"
#include "persons.h"
#include <string>
#include <iostream>

using namespace  std;


Presentation::Presentation()
{

}

void Presentation::program() {

    cout << "Please enter one of the following commands: " << endl;
    cout << "add - Add a new person to the database" << endl;
    cout << "delete - Delete a person from the database" << endl;
    cout << "view - View the database" << endl;
    cout << "search - Search the database" << endl;
    cout << "quit - Quit the program" << endl;

    string input = " ";
    cin >> input;


    if(input == "add" || input == "Add" || input == "ADD") {

        string name1;
        string gender1;
        int yearOfBirth1;
        int yearOfDeath1;
        Persons newPerson;
        int number = 0;

        cout << "How many persons would you like to input: " << endl;
        cin >> number;
        for(int i=0; i<number; i++){

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
    else if(input == "delete" || input == "Delete" || input == "DELETE") {
        // delete person from the database
        // fara inní nýja klasann sem sér um að deleta & adda
    }
    else if(input == "view" || input == "View" || input == "VIEW") {

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

        int viewInput = 0;
        cin >> viewInput;
        // allt föll inní domain ! sortera
        if(input == "1") {
            // default
        }
        else if(input == "2") {
            // sort name descending
        }
        else if(input == "3") {
            // sort name ascending
        }
        else if(input == "4") {
            // sort gender descending
        }
        else if(input == "5") {
            // sort gender ascending
        }
        else if(input == "6") {
            // sort birth year desc.
        }
        else if(input == "7") {
            // sort birth year asc.
        }
        else if(input == "8") {
            // sort death desc.
        }
        else if(input == "9") {
            // sort death asc.
        }
        else {
            cout << "Please enter a valid number!" << endl; // villutékk
        }
    }
    else if(input == "search" || input == "Search" || input == "SEARCH") {
        // search the database
        // fall inní domain ! leitar
    }
    else if(input == "quit" || input == "Quit" || input == "QUIT") {

       return;
    }
    else {
            // villutékk
        cout << "Please enter a valid command!" << endl;
    }
}

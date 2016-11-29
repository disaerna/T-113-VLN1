#include "presentation.h"

Presentation::Presentation()
{

}

Presentation::Presentation() {

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
        // add person into database
    }
    else if(input == "delete" || input == "Delete" || input == "DELETE") {
        // delete person from the database
    }
    else if(input == "view" || input == "View" || input == "VIEW") {
        cout << "How would you like view the database? " << endl;
        cout << "1. Name: A-Z" << endl;
        cout << "2. Name: Z-A" << endl;
        cout << "3. Gender: F-M" << endl;
        cout << "4. Gender: M-F" << endl;
        cout << "5. Birth Year: Desc." << endl;
        cout << "6. Birth Year: Asc." << endl;
        int viewInput = 0;
        cin >> viewInput;

        if(input == "1") {
            // sort name descending
        }
        else if(input == "2") {
            // sort name ascending
        }
        else if(input == "3") {
            // sort gender descending
        }
        else if(input == "4") {
            // sort gender ascending
        }
        else if(input == "5") {
            // sort birth year desc.
        }
        else if(input == "6") {
            // sort birth year asc.
        }
        else {
            cout << "Please enter a valid number!" << endl; // villutékk
        }
    }
    else if(input == "search" || input == "Search" || input == "SEARCH") {
        // search the database
    }
    else if(input == "quit" || input == "Quit" || input == "QUIT") {
        // quit the program
    }
    else {
            // villutékk
        cout << "Please enter a valid command!" << endl;
    }
}

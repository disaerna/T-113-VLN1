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

    }
    else if(input == "delete" || input == "Delete" || input == "DELETE") {

    }
    else if(input == "view" || input == "View" || input == "VIEW") {

    }
    else if(input == "search" || input == "Search" || input == "SEARCH") {

    }
    else if(input == "quit" || input == "Quit" || input == "QUIT") {

    }
    else {
        cout << "Please enter a valid command!" << endl;
    }

}

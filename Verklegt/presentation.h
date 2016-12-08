#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <iomanip>

#include "domain.h"
#include "persons.h"
#include "computers.h"

using namespace std;

class Presentation
{

public:

    Presentation();
    void startProgram();
    void addScientist();
    void addComputer();
    void connectTables();
    void splashMessage();

private:
    // Functions for scientists
    void newPersonsInFile(); // Adds new persons to the file.
    void removePerson(); // Removes person from the file.
    void viewPersonsDatabase(); // View options for the file.
    void searchPersonDatabase(); // Searches the database for input.

    // Function for computer
    void removeComputer(); //Removes Computer from database.
    void searchComputersDatabase();
    void viewComputersDatabase();
    void newComputer();

    // Functions for connection
    void displayConnectVector();
    void displayPersonsVector(vector<Persons> p); // Displays a table from the file.
    void displayComputersVector(vector<Computers> c); //Displays a table from the file.

    // Function that asks the user to return or quit.
    void inputToReturn();

    Domain _domain;
    Computers _computer;

};

#endif // PRESENTATION_H

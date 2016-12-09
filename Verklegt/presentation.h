#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <iomanip>
#include <limits>

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
    void splashMessage();
    void quitDoubt();

private:
    // Functions for scientists
    void newPersonsInFile(); // Adds new persons to the file.
    void removePerson(); // Removes person from the file.
    void viewPersonsDatabase(); // View options for the file.
    void searchPersonDatabase(); // Searches the database for input.
    void viewScientistConnection();
    void connectScientist();
    void updatePerson();

    // Function for computers
    void removeComputer();
    void searchComputersDatabase();
    void viewComputersDatabase();
    void newComputer();
    void viewComputerConnection();
    void connectComputer();
    void updateComputer();

    // Functions for connection
    void displayPersonsVector(vector<Persons> p); // Displays a table from the file.
    void displayComputersVector(vector<Computers> c); //Displays a table from the file.

    // Function that asks the user to return or quit.
    void inputToReturn();




    Domain _domain;
    Computers _computer;

};

#endif // PRESENTATION_H

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

    void addScientist();
    void addComputer();
    void splashMessage();

private:
    // Functions for scientists
    void newPersonsInFile(); // Adds new persons to the file.
    void removePerson(); // Removes person from the file.
    void viewPersonsDatabase(); // View options for the file.
    void searchPersonDatabase(); // Searches the database for input.

    // Functions for search options.
    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByDeathYear();

    // Function for computer
    void removeComputer(); //Removes Computer from database.
    void searchComputerDatabase();
    void viewComputersDatabase();

    // Search functionsn for computer
    void searchByComputerName();
    void searchByBuiltYear();
    void searchByType();
    void searchBySuccessfulBuilt();

    void displayPersonsVector(vector<Persons> p); // Displays a table from the file.

    // Function that asks the user to return or quit.
    void inputToReturn();

    Domain _domain;

};

#endif // PRESENTATION_H

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

using namespace std;

class Presentation
{

public:

    Presentation();
    void program();
    void splashMessage();

private:
    // Functions for main menu.
    void newPersonsInFile(); // Adds new persons to the file.
    void removePerson(); // Removes person from the file.
    void viewDatabase(); // View options for the file.
    void searchDatabase(); // Searches the database for input.

    void displayVector(vector<Persons> p); // Displays a table from the file.

    // Functions for search options.
    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByDeathYear();

    // Function that asks the user to return or quit.
    void inputToReturn();

    Domain _domain;

};

#endif // PRESENTATION_H

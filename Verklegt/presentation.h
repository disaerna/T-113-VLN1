#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

#include "domain.h"
#include "persons.h"

using namespace std;


class Presentation
{

public:

    Presentation();

    void run();
    void program();

    void newPersonsinFile();

    void viewDatabase();
    void removePerson();
    void searchDatabase();
    void displayVector(vector<Persons> p);

    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByDeathYear();

    //Search Föll
    int displaySearch();
    /*string displaySearchName();
    string displaySearchGender();
    int displaySearchBirthYear();
    int displaySearchDeathYear();
    */

    void displaySearchResults(vector<Persons> p, vector<int> results);
    void nothingFound();

    // Önnur föll
    void splashMessage();
    void inputToReturn();

private:

    Domain _domain;
};

#endif // PRESENTATION_H

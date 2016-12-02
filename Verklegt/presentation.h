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

/*
    Öll samskipti við notenda
    Displayar allt
    Dependar á DOMAIN klasann
    cout
    cin
    skilagildi í PRESENTATION = PERSON klasi
*/


class Presentation
{

public:

    Presentation();
    void program();
    void splashMessage();

private:
    void run();         //What is this?


    void newPersonsinFile();

    void viewDatabase();
    void removePerson();
    void searchDatabase();
    void displayVector(vector<Persons> p);

    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByDeathYear();

    void ifNotFound();
    //Search Föll
    int displaySearch();

    void displaySearchResults(vector<Persons> results);
    void inputToReturn();

    // Önnur föll



    Domain _domain;
};

#endif // PRESENTATION_H

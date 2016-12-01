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

    void run();
    void program();
    void displayVector(vector<Persons> p);
    void NewPersonsinFile();
    void viewDatabase();
    void removePerson();


    //Search Föll
    int displaySearch();
    string displaySearchName();
    string displaySearchGender();
    int displaySearchBirthYear();
    int displaySearchDeathYear();
    void displaySearchResults(vector<Persons> p, vector<int> results);
    void nothingFound();

    // Önnur föll
    void splashMessage();


private:
    Domain _domain;


};

#endif // PRESENTATION_H

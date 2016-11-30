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

    //
    int displaySearch();
    string displaySearchName();
    string displaySearchGender();
    int displaySearchBirthYear();
    int displaySearchDeathYear();
    void displaySearchResults(vector<Persons>& vec, vector<int>& results);
    void nothingFound();
    //

private:
    Domain _domain;


};

#endif // PRESENTATION_H

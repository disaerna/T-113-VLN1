#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

#include "data.h"
#include "persons.h"

/* Dependar á DATA klasann
    Sorterar
    Leitar

    Tekur við upplýsingum frá persons
    Búa til fall sem sorterar
    Búa til fall sem leitar
    Sendir upplýsingar yfir í presentation
        -> til þess að birta upplýsingarnar
    Sendir upplýsingar yfir í data
        -> til þess að lesa í skránna
*/

using namespace std;

class Domain
{

public:

    Domain();

    void addPersons(Persons person);
    void deletePersonFromFile(int numberOfPerson);
    vector<Persons> getPersons();
    vector<Persons> SortPersons(vector<Persons> getPerson, int viewInput);
    int currentYear();

    // functions for search function
    void searchName(vector<Persons> vec, string input);
    void searchGender(vector<Persons> vec, string input);
    void searchBirthYear(vector<Persons> vec, string byInput);
    void searchDeathYear(vector<Persons> vec, string dyInput);
    void setResults(vector<int> results);
    vector<int> getResults();
    void cleanVector(vector<int> results);

private:

    Data _data;
    vector<int> _results;

};

#endif // DOMAIN_H

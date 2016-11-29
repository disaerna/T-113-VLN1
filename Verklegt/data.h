#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

#include "persons.h"


/*  "Persistence" layer
    Les úr skrá
    Les í skrá
    Búa til fall sem skila vector<persons>

    Búa til fall sem setur Í skrá
    Búa til fall sem les ÚR skrá
*/

using namespace std;

class Data
{
public:

    Data();

    void addPersonsToFile(Persons person);
    vector<Persons> readPersonsFromFile();

private:

};

#endif // DATA_H

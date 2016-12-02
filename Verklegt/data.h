#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

#include "persons.h"

using namespace std;

class Data
{

public:

    Data();

    void addPersonsToFile(Persons person);
    vector<Persons> readPersonsFromFile();
    void addPersonsAfterDelete(vector<Persons> afterDeletePersons);

private:

};

#endif // DATA_H

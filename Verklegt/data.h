#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <QSqlDatabase>
#include "persons.h"
#include "computers.h"

using namespace std;

class Data
{

public:

    Data();

    void addPersonsToFile(Persons person);
    vector<Persons> readPersonsFromFile();
    void addPersonsAfterDelete(vector<Persons> afterDeletePersons);

private:
    QSqlDatabase m_db; // eintak af database-num
};

#endif // DATA_H

#include "data.h"
#include "persons.h"
#include <fstream>
#include <iostream>

using namespace std;

Data::Data()
{

}

vector<Persons> Data::persons(Persons person)
{
    _dataInfo.push_back(person);

    return _dataInfo;
}

void Data::addPersonsToFile(Persons person)
{
    ofstream file;
    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirkrifa ekki í textafile.

    file << "Name: " << person.getName() << endl;
    file << "Gender: " << person.getGender() << endl;
    file << "Year of birth: " << person.getYearOfBirth() << endl;
    file << "Year of death if deceased: " << person.getYearOfDeath() << endl;

    file.close();

}

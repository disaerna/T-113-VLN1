#include "persons.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

Persons::Persons()
{

}

string Persons::getName() const
{
    return _name;
}

string Persons::getGender() const
{
    return _gender;
}

int Persons::getYearOfBirth() const
{
    return _yob;
}

int Persons::getYearOfDeath() const
{
    return _yod;
}

void Persons::setPersons(string n, string g, int yob, int yod)
{
    _name = n;
    _gender = g;
    _yob = yob;
    _yod = yod;
}

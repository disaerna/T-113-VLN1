#include "persons.h"
#include <iostream>

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
void Persons::setName(string n)
{
    _name = n;
}
void Persons::setGender(string g)
{
    _gender = g;
}
void Persons::setYearOfBirth(int yob)
{
    _yob = yob;
}
void Persons::setYearOfDeath(int yod)
{
    _yod = yod;
}


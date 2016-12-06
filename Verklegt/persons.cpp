#include "persons.h"

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

string Persons::getYearOfBirth() const
{
    return _birth;
}

string Persons::getYearOfDeath() const
{
    return _death;
}

void Persons::setPersons(int id, string name, string gender, string birth, string death)
{
    _name = name;
    _gender = gender;
    _birth = birth;
    _death= death;
    _id = id;
}


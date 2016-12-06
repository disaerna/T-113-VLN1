#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

class Persons
{

public:

    Persons();

    string getName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;
    void setPersons(string name, string gender, string birth, string death);

private:

    string _name;
    string _gender;
    string _birth; // year of birth
    string _death; // year of death
};

#endif // PERSONS_H

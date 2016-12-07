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
    int getID() const;
    void setPersons(int id, string name, string gender, string birth, string death);

private:

    string _name;
    string _gender;
    string _birth; // year of birth
    string _death; // year of death
    int _id;
};

#endif // PERSONS_H

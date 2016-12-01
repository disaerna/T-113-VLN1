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
    // föll til að fá og setja gildi
    string getName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;
    void setPersons(string n, string g, string yob, string yod);

private:

    string _name;
    string _gender;
    string _yob; // date of birth
    string _yod; // date of death

};

#endif // PERSONS_H

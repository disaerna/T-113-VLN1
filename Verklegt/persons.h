#ifndef PERSONS_H
#define PERSONS_H
#include <iostream>
#include <string>

using namespace std;

class Persons
{

public:

    Persons();
    Persons(int n, int g, int db, int dd);
    friend bool operator <(Persons& lhs, Persons& rhs);

private:

    string _name;
    string _gender;
    int _dob; // date of birth
    int _dod; // date of death

};

#endif // PERSONS_H

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
    friend istream& operator >>(istream& is, Persons rhs);
    friend ostream& operator <<(ostream& os, Persons rhs);
    void readInfo(vector<Persons> info, Persons rhs);
    void writeInfo(vector<Persons> info, Persons rhs);

private:

    string _name;
    string _gender;
    int _dob; // date of birth
    int _dod; // date of death
    vector<Persons> _info;

};

#endif // PERSONS_H

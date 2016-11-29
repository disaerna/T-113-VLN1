#include "persons.h"
#include <iostream>

using namespace std;

Persons::Persons()
{

}

Persons::Persons(int n, int g, int db, int dd)
{
     _name = n;
     _gender = g;
     _dob = db;
     _dod = dd;
}

// get föll
string Persons::getName() const {
    return _name;
}

string Persons::getGender() const {
    return _gender;
}

int Persons::getDOB() const {
    return _dob;
}

int Persons::getDOD() const {
    return _dod;
}


/*

bool operator <(Persons lhs, Persons rhs)
{
    if(lhs._dob < rhs._dob)
    {
        return true;
    }
    else
        return false;
}
istream& operator >>(istream& is, Persons rhs)
{
    is >> rhs;

    return is;
}
ostream& operator <<(ostream& os, Persons rhs)
{
    os << rhs;

    return os;
}
void readInfo(vector<Persons>& info, int number)
{
    Persons ps;

    for(int i = 0; i < number; i++)
    {
        cin >> ps._name;
        cin >> ps._gender;
        cin >> ps._dob;
        cin >> ps._dod;

        info.push_back(ps);
    }
}
<<<<<<< HEAD
void writeInfo(vector<Persons> info)
{
    ofstream file;
    file.open("data.txt");

    for(int i=0; i<info.size(); i++)
    {
        file << info[i];
    }

    file.close();
}*/

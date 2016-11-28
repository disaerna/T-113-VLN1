#include "persons.h"
#include <iostream>

using namespace std;

Persons::Persons()
{

}

 Persons(int n, int g, int db, int dd)
 {
     _name = n;
     _gender = g;
     _dob = db;
     _dod = dd;
 }

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
    }

    info.push_back(ps);
}
void writeInfo(vector<Persons> info, Persons rhs)
{

}

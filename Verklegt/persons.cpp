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

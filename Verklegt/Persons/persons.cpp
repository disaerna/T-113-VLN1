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
vector<Persons> Persons::getVector(int i)
{
    return _info[i];
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

void Persons::readInfo(vector<Persons>& info, int number)
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

void Persons::writeInfo(vector<Persons> info)
{
    ofstream file;
    file.open("data.txt");

    for(int i=0; i<info.size(); i++)
    {
        file << info[i];
    }

    file.close();
}

void Persons::readData(vector<Persons>& myVector) { // inputting into vector

    Persons p;
    ifstream dataFile;
    dataFile.open("data.txt");
    while(dataFile >> p.n && dataFile >> p.g && dataFile >> p.db && dataFile >> p.dd) {
        myVector.push_back(p);
    }
}

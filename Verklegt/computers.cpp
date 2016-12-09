#include "computers.h"

using namespace std;

// constructor
Computers::Computers()
{

}

// get functions
string Computers::getCompName () const
{
    return _compName;
}

string Computers::getCompYearBuild () const
{
    return _compYearBuild;
}

string Computers::getCompType () const
{
    return _compType;
}

bool Computers::getCompBuilt() const
{
    return _compBuilt;
}

int Computers::getCompID () const
{
    return _compID;
}

// set function
void Computers::setComputers(int compID, string compName, string compYearBuild, string compType, bool compBuilt)
{
    _compName = compName;
    _compYearBuild = compYearBuild;
    _compType = compType;
    _compBuilt = compBuilt;
    _compID = compID;
}

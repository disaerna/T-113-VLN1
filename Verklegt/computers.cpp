#include "computers.h"

using namespace std;

Computers::Computers() {
    // constructor
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

/*string Computers::getCompMemory () const
 * {
    return _compMemory;
}

string Computers::getCompClockSpeed () const
{
    return _compClockSpeed;
}*/
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
   // _compMemory = compMemory;
   // _compClockSpeed = compClockSpeed;
}

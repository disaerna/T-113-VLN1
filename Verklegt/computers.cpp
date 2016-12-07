#include "computers.h"

using namespace std;

Computers::Computers() {
    // constructor
}

// get föll
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

string Computers::getCompBuilt () const
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

// set fall
void Computers::setComputers(string compName, string compYearBuild, string compType, string compBuilt)
{
    _compName = compName;
    _compYearBuild = compYearBuild;
    _compType = compType;
    _compBuilt = compBuilt;
   // _compMemory = compMemory;
   // _compClockSpeed = compClockSpeed;
}

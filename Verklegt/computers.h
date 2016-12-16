#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>

using namespace std;

class Computers
{

public:
    Computers();

    // get functions
    string getCompName() const;
    string getCompYearBuild() const;
    string getCompType() const;
    bool getCompBuilt() const;
    string getCompMemory() const;
    string getCompClockSpeed() const;
    int getCompID() const;

    // set functions

    void setComputers(int compID, string compName, string compYearBuild, string compType, bool compBuilt);

private:
    string _compName; // name of computer
    string _compYearBuild; // year computer was built
    string _compType; // type of computer (mech, electronic etc.)
    bool _compBuilt; // was the computer built?
    int _compID;
};

#endif // COMPUTERS_H

#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>
#include <iostream>

using namespace std;

class Computers {
public:
    Computers();

    // get föll
    string getCompName() const;
    string getCompYearBuild() const;
    string getCompType() const;
    string getCompBuilt() const;
    string getCompMemory() const;
    string getCompClockSpeed() const;
    int getCompID() const;


    // set fall
    void setComputers(string compName, string compYearBuild, string compType, string compBuilt);
private:
    string _compName; // name of computer
    string _compYearBuild; // year computer was built
    string _compType; // type of computer (mech, electronic etc.)
    string _compBuilt; // was the computer built?
    //string _compMemory; // size of memory on computer
    //string _compClockSpeed; // clock speed of computer
    int _CompID;
};

#endif // COMPUTERS_H

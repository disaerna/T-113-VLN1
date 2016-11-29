#ifndef DATA_H
#define DATA_H

#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include <iterator>
#include "persons.h"

using namespace std;

/*    "Persistence" layer
    Les úr skrá
    Les í skrá
    Búa til fall sem skila vector<persons>

    Búa til fall sem setur Í skrá
    Búa til fall sem les ÚR skrá
*/

using namespace std;

class Data
{
public:
/*        struct Database {
        string name;
        string gender;
        int dob;
        int dod;
        };
*/

    Data();
    //vector<Persons> Persons(Persons person);
    //void addPersonsToFile(Persons person);
    //vector<Persons> people(Persons person);

    //void readData(ifstream& data);

private:

    //vector<Persons> _dataInfo;
    //vector<Database> _vec;
    /*
    void setVector(vector<Database> vec);
    void getVector(vector<Database> vec);
    void readData(vector<Database> vec);
    void saveData(vector<Database> vec);
    //void readData(ifstream& data);
    */

};

#endif // DATA_H

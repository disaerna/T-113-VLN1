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
<<<<<<< HEAD
        /*struct Database {
=======
/*        struct Database {
=======
//<<<<<<< Updated upstream
        struct Database {
//=======
    struct Database
    {
//>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> origin/master
        string name;
        string gender;
        int dob;
        int dod;
        };
<<<<<<< HEAD
        */

    Data();

    void addPersonsToFile(Persons person);
    void readPersonsFromFile(Persons person);
    vector<Persons> people(Persons person);
=======
*/

    Data();
    //vector<Persons> Persons(Persons person);
    //void addPersonsToFile(Persons person);
    //vector<Persons> people(Persons person);
>>>>>>> origin/master

private:

<<<<<<< HEAD
    vector<Persons> _dataInfo;

    /*vector<Database> _vec;
=======
    //vector<Persons> _dataInfo;
    //vector<Database> _vec;
    /*
=======
    vector<Persons> _dataInfo;
//<<<<<<< Updated upstream
    vector<Database> _vec;
//=======

    ~Data();
//>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> origin/master
    void setVector(vector<Database> vec);
    void getVector(vector<Database> vec);
    void readData(vector<Database> vec);
    void saveData(vector<Database> vec);
    */

    //void readData(ifstream& data);
    */

//<<<<<<< Updated upstream
//=======

//>>>>>>> origin/master


private:
    //vector<Database> _vec;


//>>>>>>> Stashed changes
};

#endif // DATA_H

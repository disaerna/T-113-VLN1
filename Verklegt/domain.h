#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctime>

#include "data.h"
#include "persons.h"
#include "computers.h"
#include "dbmanager.h"

using namespace std;

class Domain
{

public:

    Domain();
    // Functions for computers class
    vector<Computers> getComputers();
    void addComputer (Computers computer);

    // Functions for persons class
    void addPersons(Persons person);
    bool deletePersonFromFile(int ID);
    vector<Persons> getPersons();
    vector<Persons> sortPersons(int viewInput);
    void printPerson();
    Persons getSinglePerson(int ID);

    // Functions for search function
    vector<Persons> searchName(string input);
    vector<Persons> searchGender(string input);
    vector<Persons> searchBirthYear(string input);
    vector<Persons> searchDeathYear(string input);

    //Functions for computer
    bool validDeleteOfComputer(int number);
    string deleteComputerFromDatabase(int numberOfComputer);
    int wasBuiltCheck (string answer);

    // Functions for error checking input
    bool validNameCheck(string name);
    bool validGenderCheck(string gender);

    bool validYearCheck(string year);
    int yesOrNoCheck(string answer); // Three option for this function. Checks if input is digit, yes or no
    bool validDeathYearCheck(string birth, string death);

    string setGender(string gender); // Sets input from user M/F to Male/Female
    string currentYear(); // Gets current year

private:

    Data _data;
    DbManager _DbManager;
    Persons person;

};

#endif // DOMAIN_H

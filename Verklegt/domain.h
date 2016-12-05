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
    string deletePersonFromFile(int numberOfPerson);
    vector<Persons> getPersons();
    vector<Persons> sortPersons(int viewInput);

    // Functions for search function
    vector<Persons> searchName(string input);
    vector<Persons> searchGender(string input);
    vector<Persons> searchBirthYear(string input);
    vector<Persons> searchDeathYear(string input);

    //Functions for computer
    bool validDeleteOfComputer(int number);
    string deleteComputerFromDatabase(int numberOfComputer);

    // Functions for error checking input
    bool validNameCheck(string name);
    bool validGenderCheck(string gender);

    bool validYearCheck(string year);
    int yesOrNoCheck(string answer); // Three option for this function. Checks if input is digit, yes or no
    bool validDeathYearCheck(string birth, string death);
    bool validDeleteOfPerson(int number);

    string setGender(string gender); // Sets input from user M/F to Male/Female
    string currentYear(); // Gets current year

private:

    Data _data;

};

#endif // DOMAIN_H

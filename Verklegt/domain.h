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

/* Dependar á DATA klasann
    Sorterar
    Leitar

    Tekur við upplýsingum frá persons
    Búa til fall sem sorterar
    Búa til fall sem leitar
    Sendir upplýsingar yfir í presentation
        -> til þess að birta upplýsingarnar
    Sendir upplýsingar yfir í data
        -> til þess að lesa í skránna
*/

using namespace std;

class Domain
{

public:

    Domain();

    void addPersons(Persons person);
    string deletePersonFromFile(int numberOfPerson);
    vector<Persons> getPersons();
    vector<Persons> SortPersons(vector<Persons> getPerson, int viewInput);

    // functions for search function
    vector<Persons> searchName(vector<Persons> vec, string input);
    vector<Persons> searchGender(vector<Persons> vec, string input);
    vector<Persons> searchBirthYear(vector<Persons> vec, string byInput);
    vector<Persons> searchDeathYear(vector<Persons> vec, string dyInput);

    // functions for error checking add input
    bool validNameCheck(string name1);
    bool validGenderCheck(string gender);
    string setGender(string gender);
    bool validBirthYearCheck(string year);
    bool isDeadCheck(string answer);
    int validDeathYearCheck(string birth, string death);
    bool validDeleteOfPerson(int number);

    string currentYear();





    // new functions
    void setSearchInput(string input);
    string getSearchInput();

    void setCommandInput(string input);
    string getCommandInput();

    void setUserInput(int input);
    int getUserInput();


    void searchAgainLogic();
    void showSearchResults();
    vector<Persons> searchAlgo();


private:

    Data _data;
    vector<int> _results;
    string _searchInput;
    string _commandInput;
    int _userInput;




};

#endif // DOMAIN_H

#include "data.h"
#include "persons.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

Data::Data()
{

}

vector<Persons> Data::readPersonsFromFile()
{

     int i = 1;
     string line;
     string name;
     string gender;
     string dob;
     string dod;
     vector<Persons> personsFromFile;

     ifstream myfile ("data.txt");

    /* while (getline(myfile, line))
        {
            istringstream ss(line);

            ss >> name >> gender >> dob >> dod;

            Persons p;
            p.setPersons(name,gender,dob,dod);
            personsFromFile.push_back(p);
        }*/



     if (myfile.is_open())
     {
       while (getline(myfile, line))
       {
         if (i == 1)
         {
            name = line;
            i++;
         }
         else if ( i == 2)
         {
            gender = line;
            i++;
         }
         else if ( i == 3)
         {
            dob = line;
            i++;
         }
         else if ( i == 4)
         {
            dod = line;
            i = 1;
            Persons p;
            p.setPersons(name, gender, dob, dod);
            personsFromFile.push_back(p);
         }
       }
     }
    else
    cout << "Unable to open file";
    myfile.close();
    return personsFromFile;

}
void Data::addPersonsToFile(Persons person)
{
    ofstream file;
    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirskrifa ekki í textafile.
    file << person.getName() << "*" << person.getGender() << "*" << person.getYearOfBirth() << "*" << person.getYearOfDeath() << "*" << endl;
    file.close();
}

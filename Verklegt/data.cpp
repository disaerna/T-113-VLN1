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
                        //Definition of variables.
     string line;
     string name;
     string gender;
     string dob;
     string dod;
     string delimeter;

     vector<Persons> personsFromFile;

     ifstream myfile;
     myfile.open("data.txt");

     if (myfile.is_open())      //Reading out of data.txt file.
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
                i++;
            }
            else if( i == 5)
            {
                delimeter = line;

             if(delimeter == "<3")
             {
                i = 1;
                Persons p;
                p.setPersons(name, gender, dob, dod);
                personsFromFile.push_back(p);
             }
             else
             {
                 cout << "Error found while reading from file!" << endl;
                 break;
             }
         }
    }
    }
    else
    {
         cout << "Unable to open file";
    }

    myfile.close();
    return personsFromFile;

}
void Data::addPersonsToFile(Persons person)
{                       //Function to add a person to data.txt file.
    ofstream file;
    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirskrifa ekki í textafile.

    file << person.getName() << endl;
    file << person.getGender() << endl;
    file << person.getYearOfBirth() << endl;
    file << person.getYearOfDeath() << endl;
    file << "<3" << endl; // ONE LOVE

    file.close();
}
void Data::addPersonsAfterDelete(vector<Persons> afterDeletePersons)
{                   //Function to update data.txt file after deleting someone.
    ofstream file;
    file.open("data.txt", fstream::out | fstream::trunc);

    for(int i=0; i<afterDeletePersons.size(); i++)
    {
        file << afterDeletePersons[i].getName() << endl;
        file << afterDeletePersons[i].getGender() << endl;
        file << afterDeletePersons[i].getYearOfBirth() << endl;
        file << afterDeletePersons[i].getYearOfDeath() << endl;
        file << "<3" << endl;
    }

    file.close();
}

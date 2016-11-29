#include "data.h"
#include "persons.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

// split fyrir string?

Data::Data()
{

}



vector<Persons> Data::readPersonsFromFile()
{
    // VIKTORÍA KLÁRAR FILESTREAM


     int i = 1;
     string line;
     string name;
     string gender;
     int dob = 0;
     int dod = 0;
     vector<Persons> personsFromFile;

     ifstream myfile ("data.txt");

     while (getline(myfile, line))
        {
            istringstream ss(line);

            ss >> name >> gender >> dob >> dod;

            Persons p;
            p.setPersons(name,gender,dob,dod);
            personsFromFile.push_back(p);
        }

     myfile.close();

     /*if (myfile.is_open())
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
            dob = stoi(line);
            i++;
         }
         else if ( i == 4)
         {
            //dod = (int)line;
            i = 1;
            Persons p;
            p.setPersons(name, gender, dob, dod);
            personsFromFile.push_back(p);
         }
       }
     }
    else
    cout << "Unable to open file";
    */

    return personsFromFile;

}
void Data::addPersonsToFile(Persons person)
{
    ofstream file;
    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirkrifa ekki í textafile.
    file << person.getName() << " " << person.getGender() << " " << person.getYearOfBirth() << " " << person.getYearOfDeath() << endl;


    file.close();
}

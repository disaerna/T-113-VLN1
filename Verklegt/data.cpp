#include "data.h"



using namespace std;

Data::Data()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("people.db");

    if (!m_db.open())
    {

        //Kanna hvort töflurnar eru til, ef ekki þá búa þær til.
        if (! m_db.tables().contains( QLatin1String("people")))
        {

        }
        if (! m_db.tables().contains( QLatin1String("computers")))
        {

        }
    }
    else
    {

    }
}

// Reads from the file.
vector<Persons> Data::readPersonsFromFile()
{
    int i = 1;
    string line;
    string name;
    string gender;
    string birth;
    string death;
    string delimeter;

    vector<Persons> personsFromFile;

    ifstream myfile;
    myfile.open("data.txt");

    if (myfile.is_open())      // Reads from the text file.
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
                birth = line;
                i++;
            }
            else if ( i == 4)
            {
                death = line;
                i++;
            }
            else if( i == 5)
            {
                delimeter = line;

                if(delimeter == "<3") // Checks if the file includes "<3", if not the file has been edited outside the program.
                {
                    i = 1;
                    Persons p;
                    p.setPersons(i, name, gender, birth, death);
                    personsFromFile.push_back(p);
                }
                else
                {
                    cout << "Error found while reading from file!" << endl; // We should have used try-catch here, but have'nt learn that yet.
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Unable to open file"; // We should have used try-catch here, but have'nt learn that yet.
    }

    myfile.close();
    return personsFromFile;

}

// Adds new person to the file.
void Data::addPersonsToFile(Persons person)
{
    ofstream file;
    //file.open("data.txt", fstream::out | fstream::app); // Passar að yfirskrifa ekki í textafile.

    file << person.getName() << endl;
    file << person.getGender() << endl;
    file << person.getYearOfBirth() << endl;
    file << person.getYearOfDeath() << endl;
    file << "<3" << endl; // ONE LOVE

    file.close();
}



// Clears the file and add the remaining persons back
void Data::addPersonsAfterDelete(vector<Persons> afterDeletePersons)
{
    ofstream file;
    file.open("data.txt", fstream::out | fstream::trunc);

    for(int i=0; (unsigned)i<afterDeletePersons.size(); i++)
    {
        file << afterDeletePersons[i].getName() << endl;
        file << afterDeletePersons[i].getGender() << endl;
        file << afterDeletePersons[i].getYearOfBirth() << endl;
        file << afterDeletePersons[i].getYearOfDeath() << endl;
        file << "<3" << endl;
    }

    file.close();
}

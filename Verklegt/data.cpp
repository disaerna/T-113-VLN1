#include "data.h"
#include "persons.h"
#include <fstream>

using namespace std;

// split fyrir string

Data::Data()
{

}

<<<<<<< HEAD
vector<Persons> Data::persons(Persons person)
{
    //_dataInfo.push_back(person);

    return _dataInfo;
}

void Data::readPersonsFromFile(Persons person)
{
    string name;
    int number;
    ifstream file;
    file.open("data.txt");
    while(!file.eof)
    {
        getline(file, word);
        _dataInfo.push_back(word);
    }
    file.close();

}
void Data::addPersonsToFile(Persons person)
{
    ofstream file;
    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirkrifa ekki í textafile.

    file << person.getName() << " ";
    file << person.getGender() << " ";
    file << person.getYearOfBirth() << " ";
    file << person.getYearOfDeath() << " ";
    file << endl;
    // notum | til að seperate-a nafn|gender|yob|yod
    // notum || til að seperate-a persónur
    // person1 || person 2

    file.close();
}

/*void Data::setVector(vector<Database> vec) {
=======
//vector<Persons> Data::Persons(Persons person)
//{
//    _dataInfo.push_back(person);

//    return _dataInfo;
//}

//void Data::addPersonsToFile(Persons person)
//{
//    ofstream file;
//    file.open("data.txt", fstream::in | fstream::app); // Passar að yfirkrifa ekki í textafile.
//
//    file << "Name: " << person.getName() << endl;
//    file << "Gender: " << person.getGender() << endl;
//    file << "Year of birth: " << person.getYearOfBirth() << endl;
//    file << "Year of death if deceased: " << person.getYearOfDeath() << endl;
//
//    file.close();

//}
/*
void Data::setVector(vector<Database> vec) {
>>>>>>> origin/master

    _vec = vec;
}

vector<Database> Data::getVector(vector<Database> vec) {

    return _vec;
}

void Data::readData(vector<Database> vec) {
    Database db;
    ifstream inData;
    inData.open("data.txt");
    while(inData >> db.name && inData >> db.gender && inData >> db.dob && inData >> db.dod) {
        vec.push_back(db);
    }
}

void Data::saveData(vector<Database> vec) {
    Database db;
    ofstream outData;
    outData.open("data.txt");
    for(size_t i = 0; i < vec.size(); i++) {
        outData << vec[i].name << endl;
        outData << vec[i].gender << endl;
        outData << vec[i].dob << endl;
        outData << vec[i].dod << endl;
    }
}
*/

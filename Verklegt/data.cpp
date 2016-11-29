#include "data.h"
#include "persons.h"

Data::Data()
{

}

Data::~Data() {

}

void Data::setVector(vector<Database> vec) {
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

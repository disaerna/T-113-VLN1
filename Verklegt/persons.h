#ifndef PERSONS_H
#define PERSONS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Tekur við breytum frá notenda
 * Sendir þær yfir í domain
 *
*/

class Persons
{

public:

    Persons();

    // föll til að fá og setja gildi
    string getName() const;
    string getGender() const;
    int getYearOfBirth() const;
    int getYearOfDeath() const;
    void setPersons();


private:

    string _name;
    string _gender;
    int _yob; // date of birth
    int _yod; // date of death

};

#endif // PERSONS_H

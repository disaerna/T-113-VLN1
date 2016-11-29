#ifndef DOMAIN_H
#define DOMAIN_H
#include "data.h"
#include "persons.h"

/* Dependar á DATA klasann
    Sorterar
    Leitar
    Búa til fall sem skila vector<persons>

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

private:
    Data _data;
};

#endif // DOMAIN_H

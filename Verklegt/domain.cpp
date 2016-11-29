#include "domain.h"
#include "persons.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

Domain::Domain()
{

}

void Domain::addPersons(Persons person)
{
    Data data;
    data.addPersonsToFile(person);

}

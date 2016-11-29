#include "domain.h"
#include "persons.h"

Domain::Domain()
{

}

void Domain::addPersons(Persons person)
{
    _data.addPersonsToFile(person);

}

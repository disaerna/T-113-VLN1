#ifndef PRESENTATION_H
#define PRESENTATION_H
#include "domain.h"
#include "persons.h"

using namespace std;

/*
    Öll samskipti við notenda
    Displayar allt
    Dependar á DOMAIN klasann
    cout
    cin
    skilagildi í PRESENTATION = PERSON klasi
*/


class Presentation
{
public:
    Presentation();
//<<<<<<< HEAD
    void run();
//=======
    void program();

private:
    Domain _domain;


//>>>>>>> origin/master
};

#endif // PRESENTATION_H

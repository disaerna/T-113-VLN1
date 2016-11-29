#include <iostream>
//<<<<<<< HEAD
//=======
#include <fstream>
#include <string>
#include <vector>
#include "persons.h"
//>>>>>>> origin/master
#include "presentation.h"

#include <QCoreApplication>

using namespace std;

int main(int argc, char *argv[])
{
//<<<<<<< HEAD
   // Presentation ui;


   // return 0;
//=======


   // Presentation pres;
    Presentation pres;
    pres.program();



    QCoreApplication a(argc, argv);

    return a.exec();
//>>>>>>> origin/master
}

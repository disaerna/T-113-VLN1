#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "persons.h"
#include "presentation.h"

using namespace std;

int main(int argc, char *argv[])
{


   // Presentation pres;
    Presentation pres;
    pres.program();



    QCoreApplication a(argc, argv);

    return a.exec();
}

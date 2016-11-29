#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "persons.h"
#include "presentation.h"
#include "data.h"
#include "domain.h"

#include <QCoreApplication>

using namespace std;

int main(int argc, char *argv[])
{

    Presentation pres;
    pres.program();

    QCoreApplication a(argc, argv);

    return a.exec();
}

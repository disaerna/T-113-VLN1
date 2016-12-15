#include "mainmenu.h"
#include <QApplication>
#include <QtGui>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    //Presentation pres;

    MainMenu mm;
    mm.show();

    //pres.startProgram(); // Runs program.

    return application.exec();
}

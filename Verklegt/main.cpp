#include "mainmenu.h"
#include <QApplication>
#include <QtGui>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainMenu mm;
    mm.show();

    return application.exec();
}

#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
//<<<<<<< HEAD
#include "persons.h"
//=======

using namespace std;

//class
//>>>>>>> origin/master

// test
// dísa test
// sandra test
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* // syntax fyrir file input og file output
    istream& operator>>(istream& is, MyClass& obj) {
        is >> obj.myClassAttb;
        // sama
        return is;
    }

    ostream& operator<<(ostream& os, const MyClass& obj) {
        os << obj.myClassAttb;
        // sama
        return os;
    }
     * */

    return a.exec();
}
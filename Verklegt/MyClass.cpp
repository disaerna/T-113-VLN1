#include "MyClass.h"

MyClass::MyClass()
{
    //ctor
}

MyClass::~MyClass()
{
    //dtor
}

MyClass::MyClass(string n, string s, int db, int dd) {
    name = n;
    sex = s;
    dob = db;
    dod = dd;
}

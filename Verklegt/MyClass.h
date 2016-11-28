#ifndef MYCLASS_H
#define MYCLASS_H


class MyClass
{
    public:
        MyClass();
        ~MyClass();
        MyClass(int n, int s, int db, int dd);

    private:
        string name; // nafn
        string sex; // kyn
        int dob; // date of birth
        int dod; // date of death
};

#endif // MYCLASS_H

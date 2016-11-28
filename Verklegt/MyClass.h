#ifndef MYCLASS_H
#define MYCLASS_H

using namespace std;


class MyClass
{
    public:
        MyClass();

        MyClass(int n, int s, int db, int dd);
        friend bool operator <(MyClass& lhs, MyClass& rhs);

    private:
        string name; // nafn
        string sex; // kyn
        int dob; // date of birth
        int dod; // date of death
};

#endif // MYCLASS_H

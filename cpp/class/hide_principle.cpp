#include<iostream>
using namespace std;

class Base1 {
public:
    int var;
    void fun() {cout << "Base1" << endl;}
};

class Base2 {
public:
    int var;
    void fun() {cout << "Base2" << endl;}
};

class Derive : public Base1,public Base2 {
public:
    int var;
    void fun() {cout << "Derive" << endl;}
};

int main()
{
    Derive d;
    Derive *p = &d;

    d.var = 1;
    d.fun();
    d.Base1::var=2;
    d.Base1::fun();

    p->Base2::var = 3;
    p->Base2::fun();

    return 0;
}
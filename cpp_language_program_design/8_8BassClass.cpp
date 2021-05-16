#include<iostream>
using namespace std;

class BaseClass {
public:
    virtual void fn1() { cout << "BaseCalss::fn1() " << endl;}
    void fn2() { cout << "BaseClass::fn2() " << endl;}
};

class DeriveClass : public BaseClass {
public:
    void fn1() { cout << "DeriveClass::fn1() " << endl;}
    void fn2() { cout << "DeriveClass::fn2() " << endl;}
};

int main()
{
    DeriveClass d;
    BaseClass* B = &d;
    DeriveClass* D = &d;
    B->fn1();
    B->fn2();
    D->fn1();
    D->fn2();
}
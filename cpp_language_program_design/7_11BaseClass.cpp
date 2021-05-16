#include<iostream>
using namespace std;

class BaseClass {
public:
    void fn1() { cout << "Base fn1()" << endl;} ;
    void fn2() { cout << "Base fn2()" << endl;} ;
};

class DeriveClass :public BaseClass
{
private:
    /* data */
public:
    void fn1() { cout << "Derive fn1()" << endl;} ;
    void fn2() { cout << "Derive fn2()" << endl;} ;
};

int main()
{
    DeriveClass d,*a;
    BaseClass *b;
    d.fn1();
    d.fn2();

    a->fn1();a->fn2();

    b->fn1();b->fn2();
}
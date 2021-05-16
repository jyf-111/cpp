#include<iostream>
using namespace std;

class Base {
public:
    void fn1() { cout << "fn1()" << endl;} ;
    void fn2() { cout << "fn2()" << endl;} ;
};

class Derive: public Base {

};

int main()
{
    Derive d;
    d.fn1();
    d.fn2();
}
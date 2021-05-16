#include<iostream>
using namespace std;

class BaseClass {
public:
    
    virtual ~BaseClass() { cout << "Bsae destructor" << endl;}
};

class DeriveClass : public BaseClass {
public:
    
    ~DeriveClass() { cout << "derive destruction" << endl;}
};

int main()
{
    BaseClass *d = new DeriveClass;
    delete d;
}
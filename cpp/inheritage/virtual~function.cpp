#include<iostream>
using namespace std;

class Base {
public:
    virtual ~Base();
};

Base::~Base() {
    cout << "Base destructor" << endl;
}

class Derive :public Base{
public:
    Derive();
    ~Derive();
private:
    int *p;
};
Derive::Derive() {
    p = new int(0);
}
Derive::~Derive() {
    cout << "Derive constructor " << endl;
    delete p;
}

void fun(Base * b) {
    delete b;
}

int main()
{
    Base *b = new Derive();
    fun(b);
    return 0;
}
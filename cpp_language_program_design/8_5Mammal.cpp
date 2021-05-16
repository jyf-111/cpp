#include<iostream>
using namespace std;

class mammal {
public:
    mammal() { cout << "mammal construct" << endl;}
    ~mammal() { cout << "mammal destructor" << endl; }
    virtual void speak() { cout << "mammal speak" << endl;}
};

class Dog : public mammal{
public:
    Dog() :mammal() { cout << "Dog construct" << endl;}
    void speak() { cout << "dog speak" << endl;}
    ~Dog() { cout << "Dog destructor" << endl; }
};

int main()
{
    Dog d;
    mammal* m;
    m = &d;
    m->speak();
}
#include<iostream>
using namespace std;

class mammal {
public:
    mammal() { cout << "mammal construct" << endl;}
    ~mammal() { cout << "mammal destructor" << endl; }
};

class Dog : public mammal{
public:
    Dog() :mammal() { cout << "Dog construct" << endl;}
    ~Dog() { cout << "Dog destructor" << endl; }
};

int main()
{
    Dog d;
}
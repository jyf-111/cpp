#include<iostream>
using namespace std;

class Dog {
private:
    int age;
    int weight;
public:
    Dog() : age{0},weight{0}{ }
    Dog(int age,int weight) : age(age),weight(weight) { }
    Dog(Dog &D) :age(D.age),weight(D.weight){ }
    void getAge() const {cout << "age = " << age << endl;}
    void getWeight( ) const {cout << "weight = " << weight << endl;}
};

int main()
{
    Dog myDog;
    myDog.getAge();
    myDog.getWeight();

    myDog = {10,20};
    myDog.getAge();
    myDog.getWeight();
}
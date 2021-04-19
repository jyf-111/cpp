#include<iostream>
using namespace std;
class A {
 public:
    void display() {cout << x << endl;}
    int GetX() {return x;}
    friend class B;
 private:
    int x;
};

class B {
 public:
    void set(int i);
    void display();
 private:
    A a;
};

void B::set(int i) {
    a.x = i;
}
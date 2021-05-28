#include<iostream>
using namespace std;

template<class T>
class A {
    friend ostream& operator << (ostream &os,A<T> &a){
    os  << a.a << endl;
    return os;
}
public:
    int a=100;
    A() { a= 100;}
};

int main()
{
    A<int> a;
    cout << a;
}
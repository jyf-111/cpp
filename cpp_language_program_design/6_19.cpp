#include<iostream>
using namespace std;
class A {
private:
    int a,b;

public:
    static int c;
    A() : a(0),b(0) { } 
     long plus(int c) {return a+b+c ;}
};
int A::c =10;
long pl(int a){return a;}

int main()
{
    
    long (*p)(int a) ;
    p = pl;
    long (A::*c)(int a ) ;
    c = &A::plus;
    cout << p(1);
    A a;
    cout << (a.*c)(100);

    int *x = &A::c;
    cout << *x << endl;
}
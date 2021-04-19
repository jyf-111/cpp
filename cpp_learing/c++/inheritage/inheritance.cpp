#include<iostream>
using std::cout;
using std::endl;
class A {
public:
    A() {cout<<"A( )"<<endl;}
    A(int x) {cout<<"A("<<x<<")"<<endl;}
};
class B : public A{//基类公有保护可，私有不可
public:
    B() {cout<<"B( )"<<endl;}
    B(int x) {cout<<"B("<<x<<")"<<endl;}
};
class C : public B{
public:
    C() {cout<<"C( )"<<endl;}
    C(int x) ;
};

int main()
{
    A();
    A(1);
    cout<<endl;
    B();
    B(2);
    cout<<endl;
    C();
    C(3);
    return 0;
}
 C::C(int x) 
{
    cout<<"C("<<x<<")"<<endl;
}
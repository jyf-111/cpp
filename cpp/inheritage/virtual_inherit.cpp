#include<iostream>
using namespace std;

class Base0
{
public:
    Base0(int val):var0(val) {}
    int var0;
    void fun0() {cout << "Base0" << endl;}
};

class Base1 :virtual public Base0 { 
public:
    int var1;
    Base1(int val): Base0(val) {}
};

class Base2 : virtual public Base0 {
public:
    int var2;
    Base2(int val): Base0(val) {}
};

class Derived : public Base1 , public Base2  {
public:
    int var;
    Derived(int val):Base1(val),Base2(val),Base0(val) { /*编译器自动优化，只初始化一次base0*/} 
    void fun() {cout << "Derive" << endl;}
    
};
//这样fun（）在derive中不会有多的副本，都是Base0里的fun,不然如果没有virtual要用::限定调用
int main()
{
    Derived d(0);
    d.var0 = 2;
    d.fun0();
    return 0;
}
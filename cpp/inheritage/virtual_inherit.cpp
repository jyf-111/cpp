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
    Derived(int val):Base1(val),Base2(val),Base0(val) { /*�������Զ��Ż���ֻ��ʼ��һ��base0*/} 
    void fun() {cout << "Derive" << endl;}
    
};
//����fun������derive�в����ж�ĸ���������Base0���fun,��Ȼ���û��virtualҪ��::�޶�����
int main()
{
    Derived d(0);
    d.var0 = 2;
    d.fun0();
    return 0;
}
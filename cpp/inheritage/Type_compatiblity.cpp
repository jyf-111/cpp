#include<iostream>

using namespace std;

class Base1 {
public:
    virtual void display()const { cout << "Base1::display()" << endl;}
    Base1() {cout << "Base1" << endl;}
    Base1(int a) {cout <<"base1::Base(int a)" << endl;}
};

class Base2 : public Base1 {
public:

    /*virtual*/void display()const override { cout << "Base2::display()" << endl;}
    Base2() {cout << "Base2" << endl;}
    Base2(int a) {cout <<"base2::Base(int a)" << endl;}
    Base2(const Base2 &base2) { cout << "copy construct is done" << endl;}
};

class Derive :public Base2 {
public:
    using Base2::Base2;

    /*virtual*/void display()const override final{ cout << "Derive::display()" << endl;}
    Derive(const Derive & derive) : Base2(derive){ /*若自己定义复制构造函数，要继承基类复制构造函数*/}
};

void fun(Base1 *ptr) {//派生类指针可以转化为基类指针
    ptr->display();
}

int main()/*override派生类必须覆盖final该函数不可以再被覆盖*/
{
    Base1 base1(0);
    Base2 base2(0);
    Derive derive(0);//派生类直接重用直接基类构造函数，构造函数如果带有默认形参，则生成两个 
    Derive derive2(derive);
    fun(&base1);
    fun(&base2);
    fun(&derive);//多态虚函数  只有指针和引用可以，对象不可以
    return 0;
}
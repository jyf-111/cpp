#include<iostream>
using namespace std;

class Base1  { 
public:
    virtual void display() const = 0 ;//纯虚函数，纯虚类不能实例化
};

class Base2 :public Base1 {
public:
    void display()const {
        cout << "Base2::display()" << endl;
    }
};

class Derived :public Base2  {
public:
void display()const {
    cout << "Derived::display()" << endl;
}
    
};
void fun(Base1 *ptr) {
    ptr->display();
}
//这样fun（）在derive中不会有多的副本，都是Base0里的fun,不然如果没有virtual要用::限定调用
int main()
{
    Base2 base2;
    Derived derived;
    fun(&base2);
    fun(&derived);
    return 0;
}
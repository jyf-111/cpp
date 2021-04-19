#include<iostream>
using namespace std;
//保护继承公有保护都变保护，私有不可访问
class A {
 protected:
    int a;
};
class B :protected A{
 public:
    void function() {
        a = 5;//正确
        cout << "protected a = " << a << endl;
    }
};
//保护成员对于基类对象而言跟private一样
int main()
{
    A a;
    //a.a = 10; 不可访问
    return 0;
}
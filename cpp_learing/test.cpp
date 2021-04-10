#include<iostream>
using namespace std;
class CExample
{
private:
    int a;
public:
    //构造函数
    CExample(int b)
    {
        a=b;
        printf("constructor is called\n");
    }
    //拷贝构造函数
    CExample(const CExample & c)
    {
        a=c.a;//是两个对象不同的成员变量a
        printf("copy constructor is called\n");
    }
    //析构函数
    ~CExample()
    {
        cout<<"destructor is called\n";
    }
    void Show()
    {
        cout<<a<<endl;
    }
};
int main()
{
    CExample A(100);
    CExample B=A;
    B.Show(); 
    return 0;
}

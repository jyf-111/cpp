#include<iostream>
using namespace std;

void foo()noexcept{throw 1;}
//void foo(){}
void tao()noexcept(1){}
void zen()noexcept(1-1){}
int main()
{
    cout<<noexcept(foo())<<endl
        //<<noexcept(foo())<<endl
        <<noexcept(tao())<<endl
        <<noexcept(zen())<<endl;
        foo();
}
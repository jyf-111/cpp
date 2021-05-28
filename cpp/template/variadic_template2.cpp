#include<iostream>
using namespace std;

template<class T>
void another_func(T &t) {

}

template<class T,class... TypeArgs>
void func(T &t,TypeArgs&... args) {
    cout << sizeof...(args) << endl;
    another_func(args)...;
}

int main()
{
    func("sadas");
}
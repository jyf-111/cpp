#include<iostream>
#include<string>
using namespace std;

int main()
{
    auto lmba = [] () ->string {return "Hello World";};
    cout << lmba() << endl;

    auto m = [](int a,int b)->bool { return a>b;};

    int size = 10;
    int identifier_list = 10;

    auto longer_than=[size](const string& s) { return s.size()>size;};//值捕获
    auto longer_than=[&size](const string& s) { return s.size()>size;};//引用捕获
    auto longer_than=[=](const string& s) { return s.size()>size;};//隐式值捕获
    auto longer_than=[&](const string& s) { return s.size()>size;};//隐式引用捕获
    auto longer_than=[=,&identifier_list](const string& s) { return s.size()>size;};//混用
    auto longer_than=[&,identifier_list](const string& s) { return s.size()>size;};//混用

    int count1 = 10;//非const
    auto increment1=[count1]()mutable { return ++count1;};
    
    int count2 = 10;
    auto increment1=[&count2]()mutable { return ++count2;};
}
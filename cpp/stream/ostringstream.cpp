#include<iostream>
#include<sstream>
#include<string>
using namespace std;

template<class T>
inline string toString(const T &v) {
    stringstream os;
    os << v;
    return os.str();
}

int main()
{
    string str1 = toString(5);
    cout << str1;
    string str2 = toString(1.2);
    cout << str2;
}
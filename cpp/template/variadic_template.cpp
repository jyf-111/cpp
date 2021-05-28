#include<iostream>
using namespace std;

template<typename T>
void print(const T & t) {
    cout << t << endl;
}

template<typename T,typename...TypeArgs>
void print(const T & t,const TypeArgs&... args) {
    cout << t << endl;
    print(args...);
}

int main() {
    print(3,4.5,"hello world");
}
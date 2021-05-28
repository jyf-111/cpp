#include<iostream>
using namespace std;

template<class T>
T myMax(T &a, T &b) {
    return a>b ? a:b;
}

template<class T>
T* myMax(T* a,T *b) {
    return *a > *b? a:b;
}

int main(){
    int a = 2;
    int b = 1;
    cout << myMax(a,b) << endl;

    cout << myMax(&a,&b);
}
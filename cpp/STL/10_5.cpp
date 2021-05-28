#include<iostream>
#include<numeric>
#include<functional>
using namespace std;

class MultClass {
public:
    int operator () (int x,int y) { return x*y;}
};

int main()
{
    int a[] = {1,2,3,4,5};
    const int N = sizeof(a)/sizeof(int);
    cout << accumulate(a,a+N,1,multiplies<int>()) << endl;
}
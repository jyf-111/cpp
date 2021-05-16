#include<iostream>
using namespace std;
class SimpleCircle {
public:
    int r;
public:
    SimpleCircle(int _r):r(_r) { }

};

int main()
{
    SimpleCircle s(100);
    int SimpleCircle::*p = &SimpleCircle::r;
    s.*p = 20;
    cout << s.r << endl;
}
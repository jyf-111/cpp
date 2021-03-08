#include<iostream>
using namespace std;

class A{
private:
    int a;
public:
    A()=default;
    bool operator+(const int &a_);
};

int main()
{
    int v1,v2;
    v1=1;

    cout << +(v1)<<endl;
    return 0;
}

inline bool A::operator+(const int &a_){
        return 1;
    }
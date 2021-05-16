#include<iostream>
using namespace std;

class Tree {
private:
    int ages;
public:
    void grow(int years) {ages +=years; }
    void age() const { cout << ages << endl;}
};

int main()
{
    Tree T;
    T.grow(5);
    T.age() ;
}
#include<iostream>
#include<memory>
using namespace std;
int main()
{
    int* p = new int(33);

    auto_ptr<int> api(p);

}
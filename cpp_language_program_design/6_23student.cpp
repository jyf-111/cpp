#include<iostream>
using namespace std;

int main()
{
    int N = 8;
    int grade;
    int sum = 0;
    while(cin>>grade){
        sum+=grade;
        if(--N==0)break;
    }
    cout << sum << endl;
}
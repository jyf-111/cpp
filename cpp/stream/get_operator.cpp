#include<iostream>
#include<string>
using namespace std;

int main()
{
    char ch;
    string s;
    char a[10];
    if(1){
        getline(cin,s,',');
        cin.getline(a,100);
        cout << a << endl;
    }
    if((ch = cin.get())!=EOF){
        cout.put(ch);
    }
}
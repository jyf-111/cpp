#include<iostream>
#include<string>
using namespace std;

void reserve(string &s,int pos) {
    if(pos>=s.length()/2) return;
    swap(s[pos],s[s.length()-1-pos]);
    reserve(s,pos+1);
}

int main()
{
    string s("abcdefg");
    reserve(s,0);
    cout << s << endl;
}
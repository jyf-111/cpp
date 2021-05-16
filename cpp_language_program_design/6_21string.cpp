#include<iostream>
#include<string>
using namespace std;
class sentence {
    string s;
public:
    sentence(string _s):s(_s) { }
    void len() const { cout << s.length() << endl;}
};
int main()
{
    string a;
    getline(cin,a);
    sentence s(a);
    s.len();
}
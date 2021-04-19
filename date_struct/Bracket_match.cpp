#include<iostream>
#include<stack>
#include<string>
using namespace std;
void Bracket_match(string str);
auto Match(char a,char b)->bool;
int main()
{
    string str;
    cin >> str;
    Bracket_match(str);
    return 0;
}
auto Match(char a,char b)->bool {
    return a==40&&b==41||a==91&&b==93||a==123&&b==125;
}
void Bracket_match(string str)
{
    stack<char> S;
    for(auto i = str.cbegin(); i!=str.cend(); ++i) {
        //cout << *i << endl;
        switch(*i) {
            case '(':
            case '[':
            case '{':
                S.push(*i);
                break;
            case ')':
            case ']':
            case '}':
                if(S.empty()) {
                    cout << "the bracket is useless" << endl;
                    return ;
                }else {
                    char c = S.top();
                    if(Match(c,*i)){
                        S.pop();
                    }else{
                        cout << "the bracket is not match" << endl;
                        return ;
                    }
                }
        }
    }
    if(S.empty()){
        cout << "the brackets are matched" << endl;
    }else{
        cout << "the left brackets are useless" << endl;
    }
}
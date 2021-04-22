#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> map= {pair<string,int>{"love",1},pair<string,int>{"fuck",2}};
    map.insert(make_pair("wcy",1111));
    for(auto i:map){
        cout << i.first << " "<< i.second << endl;
    }
}
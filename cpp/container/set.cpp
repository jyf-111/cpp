#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> set = {1,2,3};
    for(auto i:set){
        cout << i << endl;
    }  
}
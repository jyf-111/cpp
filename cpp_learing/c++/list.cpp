#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> ilist{1,2,3};
//push_front
    ilist.push_front(-100);
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;

    for(int i=0 ; i < 4 ;i++){
        ilist.push_front( i );
    }
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;
//下面的操作相当于push_front (c++11)
    auto iter = ilist.begin();
    for( int i = 0 ; i < 4 ; i++){
        iter = ilist.insert( iter , i );
    }
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;
}
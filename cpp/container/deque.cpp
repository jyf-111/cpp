#include<iostream>
#include<deque>
#include<algorithm>
#include<array>

using namespace std;

int main()
{
    array<int,10> array;
    for(int i = 1; i<=10;++i){
        array[i-1] = i;
    }
    
    sort(array.begin(),array.end());

    deque<int> Q;
    for(auto i:array){
        if(i%2){
            Q.push_front(i);
        }else{
            Q.push_back(i);
        }
    }

    for(auto i:Q){
        cout << i << endl;
    }
}
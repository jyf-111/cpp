#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> s;
    for(int i=0 ; i<100000 ; i+=100 ) {
        s.push_back(i);
        cout << s.capacity() << " ";
        if(i%1000 == 0 )cout << endl; 
    }
}
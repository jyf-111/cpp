#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;
using namespace placeholders;



int main()
{
    int intArr[]={30,90,10,40,70,50,20,80};
    const int N=sizeof(intArr)/sizeof(int);
    vector<int> a(intArr,intArr+N);
    auto p=find_if(a.begin(),a.end(),bind(greater<int>(),_1,_2));
    if ( p== a.end()){ 
        cout << "no elemnet greater than 40" << endl;
    }else{
        cout << "the first greater than 40 is "<< *p << endl;
    }
    return 0;
}
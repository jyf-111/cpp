#include<iostream>
#include<exception>
#include<stdexcept>
#include<new>
using namespace std;

int main()
{
    try {
       for(int i=0;i<10000;i++){
           auto *p = new long long int[700000];
           cout << i+1 << "array"<<endl;
       }
    }
    
    catch (bad_alloc& e){
        cout << "fuck you " << e.what() <<endl;
    }
    return 0;
}
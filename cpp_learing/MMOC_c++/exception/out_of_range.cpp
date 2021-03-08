#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <char>v1 {'a','b','c','d','e'};
    try{for(int i=0;i<=5;i++){
        cout<<v1[i]<<endl;
        cout<<v1.at(i)<<endl;
    }
    }
    catch(std::out_of_range &e){
        cout<<"fuck you "<<e.what()<<endl;
    }
    return 0;
}
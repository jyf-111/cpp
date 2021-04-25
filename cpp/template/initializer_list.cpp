#include<iostream>
#include<initializer_list>
#include<string>
using namespace std;

void print_err(initializer_list<string> lst)
{
    for(auto i:lst){
        cout << i ;
        cout << endl;
    }
}
int main()
{
    initializer_list<string>lst;
    initializer_list<int> li{1,2,3,4};//对象元素是const
    print_err({"love","you","like"});
    return 0;
}
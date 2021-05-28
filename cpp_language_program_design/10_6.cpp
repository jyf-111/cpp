#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

template<class T>
void exchange(list<T> &l1,typename list<T>::iterator p1,list<T> &l2,typename list<T>::iterator p2){
    list<T> temp(p1,l1.end());
    swap_ranges(p2,l2.end(),p1);
    swap_ranges(temp.begin(),temp.end(),p2);
    
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    list<int> l1(array,array+5);
    list<int> l2(array+5,array+10);


    exchange(l1,l1.begin(),l2,l2.begin());

    for(auto i:l1){
        cout << i << " ";
    }
    cout << endl;
    for(auto i:l2){
        cout << i << " ";
    }
}
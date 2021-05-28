#include<iostream>
#include"9_4Dlist.h"

template <class T>
class order_list
{
private:
    DoubleLink<T> orderList;
public:
    int insert(T x);
    void print() ;
};

template<class T>
int order_list<T>::insert(T x) {
    int i=0;
    for(i=0 ; i<orderList.getCount() ;i++) {
        if(x <= orderList.get(i)) break;
    }
    orderList.insert(i,x);
    return 0;
}

template<class T>
void order_list<T>::print()  {
    orderList.printList();
}

int main() {
    order_list<int> od;
    for(int i=10 ;i >0 ;i-=2) {
        od.insert(i);
    }
    for(int i=10 ;i >0 ;i--) {
        od.insert(i);
    }
    od.print();
}
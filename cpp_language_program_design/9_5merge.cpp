#include<iostream>
#include"9_4DList.h"
using namespace std;

int main()
{
    DoubleLink<int> a;
    DoubleLink<int> b;
    for(int i=0;i<5 ;i++){
        a.append_last(i);
    }
    a.printList();

    for(int i=5;i<10;i++){
        b.append_last(i);
    }

    b.printList();

    for(int i=0;i<5;i++){
        a.append_last(b.get(i));
    }
    a.printList();
}
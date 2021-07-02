#include<iostream>
using namespace std;

void shift(int a[],int n,int p) {
    int X = a[p];
    int Parent,Child;
    for(Parent = p ; 2*Parent < n ; Parent = Child) {
        Child = 2*Parent;
        if(Child<n && (a[Child] < a[Child+1])) {
            Child++;
        }
        if( X >= a[Child]) {
            break;
        }else{
            a[Parent] = a[Child];
        }
        
    }
    a[Parent] = X;
}

void buildHeap(int a[],int n) {
    for(int i = n/2 ; i>=0 ;i--) {
        shift(a,n-1,i);
    }
}

void HeapSort(int a[],int n) {
    buildHeap(a,n);
    for(int i = n-1;i>0;i--) {
        int X = a[0];
        a[0] = a[i];
        a[i] = X;
        shift(a,i-1,0);
    }
}

int main()
{
    int a[] = {0,1,3,2,6,5,4,7,8,9};
    HeapSort(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << ' ';
    }
}
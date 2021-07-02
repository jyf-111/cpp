#include<iostream>
using namespace std;

void BubbleSort(int a[],int n) {
    bool change = true;
    for(int i=1; i < n && change  ; i++) {
        change = false;
        for(int j=1 ; j < n-i ; j++) {
            if(a[j]>a[j+1]) {
                change = true;
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main()
{
    int a[11]={0,0,1,3,2,6,5,4,9,8,7};
    BubbleSort(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}
#include<iostream>
using namespace std;

void selectSort(int a[],int n) {
    for(int i=1 ;i<n ;i++) {
        int min = i;
        for(int j=i+1 ;j<n;j++) {
            if(a[j]<a[min]) {
                min = j;
            }
        }
        if(min != i)
            swap(a[min],a[i]);
    }
}

int main()
{
    int a[11]={0,0,1,3,2,6,5,4,9,8,7};
    selectSort(a,sizeof(a)/sizeof(decltype(a[0])));
    for(auto i:a) {
        cout << i << " ";
    }
}
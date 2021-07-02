#include<iostream>
using namespace std;

int QuickPass(int a[],int low,int high) {
    int x = a[low];
    while(low < high){
        while(low < high && a[x] <= a[high]) {
            high--;
        } 
        if(low < high) {
            a[low] = a[high];
            low++;
        }
        while(low < high && a[x] >= a[low]) {
            low++;
        }
        if(low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = x;
    return low;
}

void QuickSort(int a[],int low,int high) {
    if(low < high) {
        int pos;
        pos = QuickPass(a,low,high);
        QuickSort(a,low,pos-1);
        QuickSort(a,pos+1,high);
    }
}

int main()
{
    int a[11]={0,0,1,3,2,6,5,4,9,8,7};
    QuickSort(a,1,sizeof(a)/sizeof(decltype(a[0]))-1);
    for(auto i:a) {
        cout << i << " ";
    }
}
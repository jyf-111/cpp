#include<iostream>
using namespace std;

void ShellInsert(int a[],int n,int delta) {
    for(int i=1+delta;i<n;i++) {
        if(a[i-delta]>a[i]) {
            a[0] = a[i];
            int j;
            for(j=i-delta;j>0 && a[0]<a[j] ;j-=delta) {
                a[j+delta] = a[j];
            }
            a[j+delta] = a[0];
        }
    }
}

void ShellSort(int a[],int n,int delta[],int len) {
    for(int i=len-1;i>=0;i--) {
        ShellInsert(a,n,delta[i]);
    }
}

int main()
{
    int a[11]={0,0,2,1,3,5,4,8,7,6,9};
    int delta[] ={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360};
    ShellSort(a,sizeof(a)/sizeof(decltype(a[0])),delta,2);
    for(auto i:a) {
        cout << i<<" ";
    }
}
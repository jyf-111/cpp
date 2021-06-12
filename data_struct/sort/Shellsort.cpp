#include<iostream>
using namespace std;

void ShellInsert(int a[],int n,int delta) {
    for(int i=1+delta;i<n;i++) {
        if(a[i-delta]>a[i]) {
            a[0] = a[i];
            int j;
            for(j=i;j>0 && a[0]<a[j-delta] ;j-=delta) {
                a[j-delta] = a[j];
            }
            a[j] = a[0];
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
    int a[11]={0,0,1,2,3,4,5,6,7,8,9};
    int delta[] ={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360};
    for(auto i:a) {
        cout << i<<" ";
    }
}
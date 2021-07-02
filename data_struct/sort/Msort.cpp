#include<iostream>
#include<cstring>
using namespace std;

void Merge(int a[],int low,int mid,int high,int d[]) {
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j <=high) {
        d[k++] = a[i] <= a[j] ?a[i++]:a[j++];
    }
    while(i<=mid) {
        d[k++] = a[i++];
    }
    while(j<=high) {
        d[k++] = a[j++];
    }
    for(int z = low;z<k;z++) {
        a[z] = d[z];
    }
}

void MSort(int a[],int temp[],int low,int high) {
    if(low<high) {
        int mid = (high+low)/2;
        MSort(a,temp,low,mid);
        MSort(a,temp,mid+1,high);
        Merge(a,low,mid,high,temp);
    }
}

int main()
{
    int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
    int* record = new int [sizeof(a)/sizeof(int)+2];
    memset(record,0,sizeof(a));

    MSort(a,record,0,sizeof(a)/sizeof(int)-1);
    for(int i=0;i<sizeof(a)/sizeof(int);i++) {
        cout << a[i] << " ";
    }
}
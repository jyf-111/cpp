#include<iostream>
using namespace std;

void InsertSort(int a[],int n) {
    for(int i=2;i<n;i++) {
        int j=i;
        a[0] = a[j];
        while(a[j-1]>a[j]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = a[0];
    }
}
int main()
{
    int a[11]={0,0,1,3,2,6,5,4,9,8,7};
    for(auto i:a) {
        cout << i << " ";
    }
    cout << endl;
    InsertSort(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}
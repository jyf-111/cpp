#include<iostream>
using namespace std;

void binSort(int a[],int n) {
    for(int i=2;i<n;i++) {
        a[0] = a[i];
        int low = 1;
        int high = i-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(a[0]>a[mid]) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        for(int j=i-1;j>=low;j--) {
            a[j+1] = a[j];
        }
        a[low] = a[0];
    }
}

void binSort_v2(int a[],int n) {
    for(int i=2;i<n;i++) {
        a[0] = a[i];
        int low = 1;
        int high = i-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(a[0]>a[mid]) {
                low = mid+1;
            }else{
                high = mid-1;
                a[high+1] = a[high];
            }
            
        }
        a[high+1] = a[0];
    }
}
int main()
{
    int a[11]={0,0,1,3,2,6,5,4,9,8,7};
    for(auto i:a) {
        cout << i << " ";
    }
    cout << endl;
    binSort(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
    cout << endl;
    binSort_v2(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}
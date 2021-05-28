#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
int bin_search(T a[],int n,const T& key) {
    sort(a,a+n);
    int begin = 0;
    int end = n-1;
    while(begin<=end){
        int mid =begin + (end - begin)/2;
        if(key == a[mid] ){
            return mid;
        }else if(key > a[mid]){
            begin = mid + 1;
        }else {
            end = mid - 1 ;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19,
               2,4,6,8,10,12,14,16,18,20};
    int key;
    cin >> key;
    cout << bin_search(a,sizeof(a)/sizeof(int),key) << endl;
}
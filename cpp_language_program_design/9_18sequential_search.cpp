#include<iostream>
using namespace std;

template<class T>
int seqsearch(T a[],int n,const T& key) {
    for(int i=0 ; i<n ; ++i) {
        if(key == a[i]){
            return i;
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
    cout << seqsearch(a,sizeof(a)/sizeof(int),key) << endl;
}
#include<iostream>
using namespace std;

template<class T>
void insert_sort(T a[],int n) {
    int i,j;
    T temp;
    for(i=1 ; i<n ; i++) {
        j=i;
        temp = a[i];
        while(j>0 && temp<a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
        for(int i=0 ; i<n ; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19,
               2,4,6,8,10,12,14,16,18,20};
    insert_sort(a,sizeof(a)/sizeof(int));
    cout << endl;
    for(auto i:a) {
        cout << i << ' ';
    }
}
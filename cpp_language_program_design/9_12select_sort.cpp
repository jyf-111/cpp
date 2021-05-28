#include<iostream>
using namespace std;

template<class T>
void Swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
void select_sort(T a[],int n) {
    
    for(int i=0; i<n-1 ; ++i) {
        int minnum = i ;
        for(int j=i+1; j<n ; ++j) {
            if(a[j]<a[minnum]){
                minnum = j;
            }
        }
        Swap(&a[i],&a[minnum]);
        cout << "swap(" << i << ',' << minnum << ')' << endl;
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
    select_sort(a,sizeof(a)/sizeof(int));
    cout << endl;
    for(auto i:a) {
        cout << i << ' ';
    }
}
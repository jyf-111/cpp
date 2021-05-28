#include<iostream>
using namespace std;

template<class T>
void Swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
void bubble_sort_down(T a[],int n) {
    int i = n-1;
    int lastExchangeIndex = 0;
    while(i>0) {
        for(int j = 0 ; j< i ; j++){
            if(a[j]<a[j+1]){
                Swap(&a[j],&a[j+1]);
                lastExchangeIndex = j;
                    cout << "swap(" << j << ',' <<j+1 << ')' << endl;
                    for(int i=0 ; i<n ; ++i) {
                        cout << a[i] << " ";
                    }
                    cout << endl;
            }
        }
        i = lastExchangeIndex;
    }
}
int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19,
               2,4,6,8,10,12,14,16,18,20};
    bubble_sort_down(a,sizeof(a)/sizeof(int));
    cout << endl;
    for(auto i:a) {
        cout << i << ' ';
    }
}
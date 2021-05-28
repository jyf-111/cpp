#include<iostream>
using namespace std;


template<class T>
void Bubble_sort(T a[],int n) {
    for(int i = n-1 ;i>0 ;i--) {
        for(int j = 0; j < i ; j++ ) {
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    int a,b,c,d,e;
    int* f[5] = {&c,&b,&a,&e,&d};

    Bubble_sort(f,sizeof(f)/sizeof(int*));
    for(auto i:f){
        cout << i << endl;
    }
}
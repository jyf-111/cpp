#include<iostream>
using namespace std;
#define Maxsize = 10
int num[10] = {0,1,2,3,4,5,6,7,8,9};

typedef struct {
    int r[11];
    int length;
}Recordlist;

int SeqSearch(Recordlist l,int k) {
    l.r[0] = k;
    int i = l.length;
    while(l.r[i]!=k) {
        i--;
    }
    return i;
}

int main()
{
    Recordlist l;
    for(int i=0;i<10;i++) {
        l.r[i+1] = num[i];
    }
    l.length = 10;
    cout << SeqSearch(l,11);
}
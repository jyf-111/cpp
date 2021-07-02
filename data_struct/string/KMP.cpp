#include<iostream>
#define MaxSize 10
using namespace std;
typedef struct {
    char data[MaxSize];
    int length;
} SqString;
void GetNext(SqString t,int next[]) {
    int j,k;
    j = 0;
    k = -1;
    for(int i=0 ;i<MaxSize;i++ ) {
        next[i] = -1;
    }
    while(j<t.length-1) {
        if(k==-1 || t.data[j]==t.data[k]) {
            j++;
            k++;
            if(t.data[j]!=t.data[k]) {
                next[j] = k;
            }else{
                next[j] = next[k];
            }
        }else{
            k = next[k];
        }
    }
}
int KMPIndex(SqString s,SqString t) {
    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while(i<s.length && j<t.length) {
        if(j==-1 || s.data[i]==t.data[j]) {
            i++;
            j++;
        }else {
            j = next[j];
        }
    }
    if(j>=t.length) {
        return i-t.length;
    }else{
        return -1;
    }
}

int main()
{
    SqString s = {"123456",6};
    SqString t = {"1234",4};
    cout << KMPIndex(s,t);
}
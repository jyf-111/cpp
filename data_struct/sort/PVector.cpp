#include<iostream>
#include<cstring>
#define N 10
#define D 10

int GetDigit(int M,int i) {
    while(i>1) {
        M/=10;
        i--;
    }
    return M%10;
}

void RadixSort(int num[],int len) {
    int i,j,k,l,digit;
    int allot[10][N];
    memset(allot,0,sizeof(allot));

    for(i = 1;i<=D;i++) {
        int flag = 0;
        for(j = 0;j<len;j++) {
            digit = GetDigit(num[j],i);
            k = 0;
            while(allot[digit][k]) {
                k++;
            }
            allot[digit][k] = num[j];
            if(digit) {
                flag = 1;
            }
        }
        if(!flag) {
            break;
        }
        l = 0;
        for(j = 0;j<10;j++) {
            k = 0;
            while(allot[j][k]>0) {
                num[l++] = allot[j][k];
                k++;
            }
        }
        memset(allot,0,sizeof(allot));
    }
}

int main()
{
    int num[N] = {52, 20, 4, 10, 17, 39, 8, 300, 60, 81};
    RadixSort(num,N);

    for(int i=0;i<N;i++) {
        std::cout << num[i] << " ";
    }
}

/*
#include<iostream>
#include<cstring>
#define N 10
#define D 10

int GetDigit(int M,int i) {
    while(i>1) {
        M/=10;
        i--;
    }
    return M%10;
}

void RadixSort(int num[],int len) {
    int i,j,k,l,digit;
    int allot[10][N];
    memset(allot,0,sizeof(allot));

    for(i = 1;i<=D;i++) {
        int flag = 0;
        for(j = 0;j<len;j++) {
            digit = GetDigit(num[j],i);
            k = 0;
            while(allot[digit][k]) {
                k++;
            }
            allot[digit][k] = num[j];
            if(digit) {
                flag = 1;
            }
        }
        if(!flag) {
            break;
        }
        l = 0;
        for(j = 0;j<10;j++) {
            k = 0;
            while(allot[j][k]>0) {
                num[l++] = allot[j][k];
                k++;
            }
        }
        memset(allot,0,sizeof(allot));
    }
}

int main()
{
    int num[N] = {52, 20, 4, 10, 17, 39, 8, 300, 60, 81};
    RadixSort(num,N);

    for(int i=0;i<N;i++) {
        std::cout << num[i] << " ";
    }
}
*/
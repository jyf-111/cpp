/*
������˾N��Ա���Ĺ��䣬Ҫ�󰴹����������ÿ��������ж���Ա����
�����ʽ:
�������ȸ���������N����10^5������Ա����������������N����������ÿ��Ա���Ĺ��䣬��Χ��[0, 50]��

�����ʽ:
������ĵ���˳�����ÿ�������Ա����������ʽΪ��������:��������ÿ��ռһ�С��������Ϊ0��������

��������:
8
10 2 0 5 7 2 5 2
�������:
0:1
2:3
5:2
7:1
10:1
*/
#include<iostream>
using namespace std;

typedef int ElementType;
void BucketSort(ElementType A[],int N) {
    for(int i=0 ; i<N ; ++i) {
        int pos;
        cin >> pos;
        A[pos]++;
    }
}

int main()
{
    int N;
    cin >> N;
    ElementType myArray[51] = {0};
    
    BucketSort(myArray,N);

    for(int i=0;i<51;i++){
        if(myArray[i]!=0) {
            cout << i <<':' << myArray[i] << endl;
        }
    }
}
#include<iostream>
using namespace std;
#define Maxsize = 10
int num[10] = {0,1,2,3,4,5,6,7,8,9};

int binsearch(int num[],int k) {
    int begin = 0;
    int end = 9;
    
    while( begin < end) {
        int mid = begin + (end-begin) / 2;
        if(mid == k) {
            return mid;
        }else if(mid < k) {
            begin = mid + 1;
        }else {
            end = mid-1;
        }
    }
    return -1;
}

int main()
{
    cout << binsearch(num,11);
}
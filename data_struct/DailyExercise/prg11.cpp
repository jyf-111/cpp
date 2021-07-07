/*设计一个函数separatepn函数格式如下：
void separatepn(int a[],int n)
将数组a中a[1]-a[n]的数重新排列，使得所有正数（包括0）排在所有负数之前。算法复杂度为O(n)，函数里只能有一个循环语句。
*/
#include<iostream>
using namespace std;
void separatepn(int a[],int n) {
    int i=1;
    int j=n;
    while(i<j) {
        a[0] = a[i];
        while(i<j && a[j]<0) {
            j--;
        }
        if(i<j) {
            a[i] = a[j];
            i++;
        }
        while(i<j && a[i]>00) {
            j--;
        }
        if(i<j) {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = a[0];
}
int main()
{
    int a[]={0,1,2,3,4,5,6,-1,-1,-2,-3,-4,-5};
    separatepn(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}
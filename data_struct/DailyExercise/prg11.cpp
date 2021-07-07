/*���һ������separatepn������ʽ���£�
void separatepn(int a[],int n)
������a��a[1]-a[n]�����������У�ʹ����������������0���������и���֮ǰ���㷨���Ӷ�ΪO(n)��������ֻ����һ��ѭ����䡣
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
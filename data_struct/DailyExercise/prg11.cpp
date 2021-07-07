/*���һ������separatepn������ʽ���£�
void separatepn(int a[],int n)
������a��a[1]-a[n]�����������У�ʹ����������������0���������и���֮ǰ���㷨���Ӷ�ΪO(n)��������ֻ����һ��ѭ����䡣
*/
#include<iostream>
using namespace std;
void separatepn(int a[],int n) {
    int i=1;
    int j=n-1;
    while(i<j) {
        while(i<j && a[j]<0) {
            j--;
        }
        
        while(i<j && a[i]>=0) {
            i++;
        }
        swap(a[i],a[j]);
        for(int i=0 ;i<13;i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[]={-1,-1,-2,-3,-4,-5,0,1,2,3,4,5,6};
    separatepn(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}
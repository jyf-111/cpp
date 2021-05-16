/*Given any permutation of the numbers {0, 1, 2,..., N?1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (��10
?5
?? ) followed by a permutation sequence of {0, 1, ..., N?1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1
Sample Output:
9
����һ����0��N-1�����У����ֻ�ܽ���0����һ������λ�ã�����ٴ��ܹ������б�Ϊ�������С�

����Ϊ<N> <����>��N������֮����һ���ո�����Ԫ��֮�����һ���ո񣩡�

�����д洢������A� 

һ��ֱ�ӵ�˼·�ǽ�0��0����λ��Ӧ�е�Ԫ�ؽ��������0������0��λ�õ�������û����ȫ��ɵ������У�
����0��һ��û�й�λ��Ԫ�ؽ���һ���Ͻ�����Ȼ���ٽ��к����Ľ�����

һ�����ص�˼·�ǣ���0Ӧ��λ�õ�Ԫ�أ���A[0]��������Ӧ���ڵ�λ�ã�����A[0]=3�����A[0]��A[3]��������
��������������ֱ��0��������0λ�ã��ж�һ���Ƿ�ȫ����λ����Ȼ�Ļ��Ͱ�0������һ��û�й�λ��Ԫ���ϣ�
��ʵ��һ����������ķϽ��������������ظ���������Ľ�����ֱ�����б�Ϊ�������С�
Ҫע����ǣ�ÿ�μ�����һ��û�й�λ��Ԫ��ʱ���𲽵�ֵ����A[0]��������λ�ÿ�ʼ������ᳬʱ��������㷨�����˼·ʵ�֡�
*/

#include<iostream>
using namespace std;

int FirstNotRight(int *A,int begin,int end) {
    for(int i = begin; i<=end ;++i) {
        if(*(A+i)!=i) {
            return i;
        }
    }
    return 0;
}

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int N;
    cin >> N;
    int* A = new int [N];
    for(int i=0 ; i<N ; ++i) {
        cin >> A[i];
    }

    int cur = FirstNotRight(A,1,N-1);
    int count = 0;
    while( cur != 0) {
        if(*A==0) {
            swap(A,A+cur);
            count++;
        }
        while(*A !=0) {
            int curtoswap = *A;
            swap(A,A+curtoswap);
            count++;
        }
        cur = FirstNotRight(A,cur,N-1);
    }
    cout << count << endl;
}
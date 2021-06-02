/*Given any permutation of the numbers {0, 1, 2,..., N?1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (≤10
?5
?? ) followed by a permutation sequence of {0, 1, ..., N?1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1
Sample Output:
9
对于一个由0到N-1的序列，如果只能交换0和另一个数的位置，求多少次能够将序列变为递增序列。

输入为<N> <序列>（N和序列之间有一个空格，序列元素之间均有一个空格）。

设序列存储在数组A里。 

一个直接的思路是将0和0所在位置应有的元素交换，如果0到达了0号位置但是序列没有完全变成递增序列，
则让0和一个没有归位的元素进行一个废交换，然后再进行后续的交换。

一个独特的思路是，将0应在位置的元素（即A[0]）换到它应该在的位置（例如A[0]=3，则把A[0]和A[3]交换），
不断这样交换，直到0真正到了0位置，判断一下是否全部归位，不然的话就把0换到第一个没有归位的元素上，
其实这一步就是上面的废交换，接下来再重复进行上面的交换，直到序列变为递增序列。
要注意的是，每次检索第一个没有归位的元素时，起步的值根据A[0]所交换的位置开始，否则会超时。下面的算法用这个思路实现。
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
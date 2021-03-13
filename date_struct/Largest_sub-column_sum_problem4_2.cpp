/*给定K个整数组成的序列{ N1, N2, ..., NK}，“连续子列”被定义为{ Ni, Ni+1, ..., Nj}，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，
其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和，数列开始和结束的值。
Given a sequence of K integers { N1, N2, …, NK }. A continuous subsequence is defined to be { Ni, Ni+1, …, Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/

//online algorithm o(n)
struct array{
    int a[100001];
    int n;
    int flag = 0 ;//没有最大为0，有最大是1
};
int sub(array *a,int & , int &);

#include<iostream>

int main()
{
    
    array *a = new array;
    int n;
    int begin = 0 ;
    int end = 0 ;
    //输入个数
    std::cin >> n ;

    a->n=n;
    //输入
    for(int i = 0 ; i < a->n ; i++){
        std::cin >> a->a[i] ;
    }
    if(sub(a,begin ,end)>=0&&a->flag){
        std::cout << sub(a,begin ,end) << ' ' << a->a[begin] << ' '<< a->a[end] << std::endl;
    }else{
        std::cout << 0 << ' ' << a->a[0] << ' '<< a->a[n-1] << std::endl;
    }
    delete[] a;
    return 0;
}

int sub(array *a,int& begin ,int& end){
    int thissum,maxsum;
    thissum=0;maxsum=-1;
    int prebegin = 0;
    for(int i = 0 ; i<a->n ;i++){
        //累加
        thissum+=a->a[i];
        
        if(thissum>maxsum){ //当前和大于最大和，重制最大和
            a->flag=1;//出现过最大
            maxsum=thissum;
            begin = prebegin ; //结束时把预存的存储
            end = i ;
        }else if(thissum<0){ //当前和是0舍弃
            thissum=0;
            prebegin = i + 1 ;//预存储
        }
    }
    return maxsum;
}
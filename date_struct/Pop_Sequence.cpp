/*
Given a stack which can keep M numbers at most. 
Push N numbers in the order of 1, 2, 3, ...,N and pop randomly. 
You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, 
we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case.
For each case, the first line contains 3 numbers (all no more than 1000):
M (the maximum capacity of the stack),
 N (the length of push sequence), 
 K (the number of pop sequences to be checked). 
Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO

题意：栈的大小M，输入序列的长度N（默认序列即为1,2,3…,N），
入栈出栈的顺序不定。有K个测试序列，判断每一个测试序列是否是可能的出栈顺序。

分析：就是从出栈顺序退出进栈顺序。当我们遇见输出x时，则要考虑的是x前的元素，
即小于等于x的元素都先push栈，才会有pop x；

1。栈为空时，判断需要填入的数 是否小于 栈的容量(即M)
2。若后一个数比前一个数大，又要push其之前的数 再判断　
3。若后一个数比前一个数小，则要判断栈顶元素是否与其相等


*/

#include<stdio.h>
#include<stdlib.h>
typedef struct SNode
{
    int *Data;
    int Top;
    int MaxSize;
}*Stack;


Stack InitStack(int M);

void Push(Stack S,int Data);

void Pop(Stack S);

bool IsEmpty(Stack S);

bool IsFull(Stack S);

int main()
{
    int M;//堆栈maxsize
    int N;//序列长度
    int K;//多少次判断
    Stack S;
    scanf("%d %d %d",&M,&N,&K);
//初始化堆栈
    S=InitStack(M);
    
    while(K--)
    {
        int *a=(int*)malloc(sizeof(int)*N);
        int i,k=0;
        //读入储存在a里
        for(i=0; i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=N;i++){
            Push(S,i);
            //如果入栈元素等于序列元素
            
            for(;!IsEmpty(S);){
                if(S->Data[S->Top]==a[k]){
                    k++;
                    Pop(S);
                }else{
                    break;
                }
            }
            
            
        }
        if(k==N)printf("YES\n");
        else printf("NO\n");
        S->Top=-1;//清空堆栈
    }
    return 0;
}
Stack InitStack(int M)
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=(int*)malloc(M*sizeof(int));
    S->Top=-1;//目前堆栈高
    S->MaxSize=M;//堆栈最大高 
    return S;
}
void Push(Stack S,int Data)
{
    if(!IsFull(S)){
        S->Data[++S->Top]=Data;
    }
}
void Pop(Stack S)
{
    if(!IsEmpty(S)){
        S->Data[S->Top--];
    }
}
bool IsEmpty(Stack S)
{
    return S->Top==-1;
}
bool IsFull(Stack S)
{
    return S->Top==S->MaxSize-1;
}
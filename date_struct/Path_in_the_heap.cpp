/*
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。
下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
输出样例:
24 23 10
46 23 10
26 10    
*/

#include<iostream>
#define MaxN 10001
#define Min -10001
using namespace std;

typedef struct HeapNode *Heap;
struct HeapNode
{
    int date[MaxN];
    int size;
    HeapNode():date{Min},size(0) { }
};

/*插入最小堆*/
void insert(Heap H,int x)
{
    if(H->size >= MaxN) return ;
    else {
        ++H->size;
        int i = H->size;
        H->date[i] = x;//一定要防止下个循环没进
        for(i = H->size ; H->date[i/2] > x ; i = i/2) {
            H->date[i] = H->date[i/2];
        }
        H->date[i] = x ;
    }
}

void Trace(Heap H , int num)
{
    if(num <= 0) return;
    else {
        int i = num;
        for( ; i>=1 ;i = i / 2) {
            if( i > 1)cout << H->date[i] << " ";
            else if( i==1 )cout <<H->date[i];
        }
    }
}

int main()
{
    	/*向堆中插入元素*/
	/*打印对应下标的根节点上的路径*/

    Heap H = new struct HeapNode;/*构建一个堆*/

    int N;//插入元素的个数
    int M;//以及需要打印的路径条数。
    int x,num;
    cin >> N >> M;	/*读入N，M*/

    for(int i =0 ; i < N ; ++i){
        cin >> x;
        insert(H,x);
    }
    
    for(int i = 0 ; i < M ; ++i){
        cin >> num;
        Trace(H , num);
        cout << endl;
    }
    return 0;
}
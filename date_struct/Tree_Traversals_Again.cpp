/*
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. 
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are:
push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (≤30) which is the total number of nodes in a tree 
(and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: 
"Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist.
 All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

3 4 2 6 5 1

前序中序遍历转后序
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define maxn 30

stack<int> s;
int pre[maxn],mid[maxn],last[maxn];


//1 2 3 4 5 6
//3 2 4 1 6 5
//通过 输入的 push 顺序，得到前序遍历的数组
//通过 push 和 pop 得到 中序遍历的数组
//通过前序和中序的数组，可以唯一确定一个后序遍历数组。

//参数：PreL为当前前序序列的起始位置，即根节点位置
//InL为当前中序序列中的左或右子树的起始位置
//LastL为后序序列中子序列起始位置的下标
//n为当前左或右子树的长度
void Solve(int PreL, int InL ,int LastL ,int n)
{
    if(n == 0 ){//若没有节点直接返回
        return ;
    }
    if( n == 1){//若只有一个节点，直接将其赋值给后序第一个元素
        last[LastL] = pre[PreL];
        return ;
    }
    int Root = pre[PreL];//存储当前子序列的根节点的值
    //LastL+n-1 就是当前序列的最后一个位置，因为根节点一定在LastL为当前子序列起始位置，
	//n为当前序列总长度，-1为当前序列最后一个位置的下标
    last[LastL+n-1] = Root;

    int i;

    //在当前子序列长度n中找到根节点位置

    for( i = 0 ; i < n ; ++i){
        if(mid[InL+i] == Root){//找到的i的位置为当前子序列中的位置
            break;
        }
    }
    int L = i,R = n-i-1;//当前左右子序列的长度
    
    //递归解决左右

    /*后一个前序序列的根节点(第一个参数PreL):
	1、当前节点的下一个节点（当前左子树的根）即PreL+1
	2、以及当前节点往后推左子树的长度L(当前右子树的根)即PreL+1+L
	//中序序列开始查找的位置（第二个参数InL）
	1、当前左子树的起点往后走即InL
	2、当前右子树的起点往后走左子树的长度L即InL+1+L
	//后序序列的存储位置,当前左子树的起点位置（第三个参数postL）
	1、即当前位置postL
	2、往后走L到右子树起点即postL+L
	//第四个参数（L,R）
	存储当前左右子树的长度，最后将其值都赋值给n
	*/
    Solve( PreL+1 , InL , LastL , L );
    Solve( PreL+L+1, InL+L+1 , LastL+L , R );
}

int main()
{
    int n,a,j = 0 ,k = 0;
    string str;

    cin >> n;
    
    for( int i = 0 ; i < 2*n ; ++i)
    {
        cin >> str;
        if(str == "Push"){
            cin >> a;
            s.push(a);
            pre[j++] = a;
        }
        if(str == "Pop"){
            mid[k++] = s.top();
            s.pop();
        }
    }

    Solve(0,0,0,n);

    for(int i = 0 ; i < n ; ++i)
    {
        if( i == 0){
            cout << last[i];
        }else{
            cout << " " << last[i];
        }
    }
    cout << endl;
    return 0;
}

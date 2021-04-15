/*
We have a network of computers and a list of bi-directional connections. 
Each of these connections allows a file transfer from one computer to another.
Is it possible to send a file from any computer on the network to any other?

Input Specification:
Each input file contains one test case. For each test case, the first line contains N (2≤N≤10^4),
the total number of computers in a network. 
Each computer in the network is then represented by a positive integer between 1 and N. 
Then in the following lines, the input is given in the format:

I c1 c2  
where I stands for inputting a connection between c1 and c2; or

C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:
For each C case, print in one line the word "yes" or "no" 
if it is possible or impossible to transfer files between c1 and c2, respectively.
At the end of each case, print in one line "The network is connected." 
if there is a path between any pair of computers; or "There are k components."
where k is the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:
no
no
yes
There are 2 components.


题目大意就是给定编号 1-n 的独立电脑，当一行输入开头为 ‘I’ 时，连接之后两台编号的电脑，当输入为 ‘C’ 时，测试之后两台编号电脑是否相连，当输入为 ‘S’ 时，结束输入
考察的是并查集的优化
核心在于"并"和"查"操作

并：将两个结点所属集合合并，在此用到按秩归并，即每次合并时，规模小的树作为子结点挂到规模大的树上
查：检查两个结点是否属于同一集合，在此用到路径压缩，即每次查找时，把所查找结点到根结点间一系列结点的值都直接挂到根结点上去
当输入为 ‘I’，如果输入结点所属集合不同，将所在集合并在一起
当输入为 ‘C’，检查两台电脑所在集合根结点是否相同
当输入为 ‘S’，检查数组值中小于 0 的值个数

*/

//并查集
#include<iostream>
#define Maxsize 10005
typedef int SetType;
using namespace std;

// 初始化 
void Init(SetType s[],int n)
{
    for(auto i = 0 ; i<n ; ++i) {
        s[i] = -1;
    }
}

// 查找 

int main()
{
    int n;
    char in;
    SetType s[Maxsize];
    cin >> n;
    Init(s,n);
    do { 
        getchar(); // 接收每次多出来的回车 
        cin >> in;
        switch(in) {
            case 'I' :Input_connection(s);break;
            case 'C' :check_connection(s);break;
            case 'S' :check_network(s,n);break;
        }
    }while(in !='S');

    return 0;
}
/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。
于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。
第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
Yes
No
No

思路分析：本体整体的思路很明显，先输入二叉搜索树的结点个数，然后输入要比较的二叉搜索树的个数，之后进入循环迭代，首先要构建一个要进行比较的模板二叉树，然后再构建要比较的函数，这里用到了很多函数的方法，值得注意的是C++的实现，必须在main函数之前提供函数的声明。



*/

#include<iostream>
using namespace std;

typedef struct TNode* Tree;
struct TNode
{
    int date;
    Tree left,right;
    int flag;
};
Tree makeNewTree(int n );//用来生成二叉搜索树
Tree treeNewNode(int v);//生成新的结点
Tree insert(Tree T, int v);//因为是通过用户输入的值进行插入，所以需要这个函数
int check(Tree T, int v);//检查这个结点之前是否出现，改变flag的值
int judge(Tree T, int n);//判断两棵树是否相同
void ResetT(Tree T);//重置flag值，为后面要生成的树做准备
void FreeTree(Tree T);//释放已经比较过的二叉搜索树

int main()
{
    int n,testn;
    Tree T;
    cin >> n ;
    cin >> testn;
    while(n)
    {
        T = makeNewTree(n);
        for(int i = 0 ; i<testn ; ++i){
            
            if(judge(T,n))cout <<"Yes" <<endl;
            else cout << "No" <<endl;
            ResetT(T);
        }
        FreeTree(T);
        cin >> n ;
        if(n == 0)break;
        cin >> testn;
    }
    return 0;
}

Tree makeNewTree(int n) 
{
    Tree T;
    int v;
    if(!n){
        return nullptr;
    }else{

        cin >> v;
        T = treeNewNode( v );
        for(int i = 1 ; i<n ; ++i){
            cin >> v;
            T = insert(T,v);
        }
        return T;
    }
}

Tree treeNewNode(int v ) 
{
    Tree T;
    T = (Tree)malloc(sizeof(struct TNode));
    T->date = v ;
    T->left = nullptr;
    T->right = nullptr;
    T->flag = 0; 
    return T;
}

Tree insert(Tree T,int v)
{
    if(!T) {
        T = treeNewNode(v);
    }else if(v > T->date){T->right= insert(T->right,v);}
    else {T->left = insert(T->left,v);}
    return T; 
}

int check(Tree T,int v) 
{
    if(T->flag){//判断节点有没有访问过
        if(v > T->date){
            check(T->right,v);
        }else if(v < T->date){
            check(T->left,v);
        }else{
            return 0;
        }
    }else{
        //如果访问过判断数值是不是一样
        if(v == T->date){
            T->flag = 1 ;
            return 1;
        }else{
            return 0;
        }
    }
}

int judge(Tree T,int n) 
{
    int v ,flag = 0;//0表示一样，1表示不同；
    for(int i = 0 ; i < n ; ++i){
        cin >> v;
        if(!flag&&!check(T,v)){
            flag = 1;
        }
    }
    if(flag ) return false;
    else return true;

}

void ResetT(Tree T)
{
    if(T->left) ResetT(T->left);
    if(T->right) ResetT(T->right);
    T->flag = 0;
}
void FreeTree(Tree T)
{
    if(T->left) ResetT(T->left);
    if(T->right) ResetT(T->right);
    free(T);
}

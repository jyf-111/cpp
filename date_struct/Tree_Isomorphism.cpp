/*给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，
则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，
因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。

现给定两棵树，请你判断它们是否是同构的。
输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。*/
#include<iostream>
#define Maxsize 10
#define Null -1
using namespace std;
struct NodeTree{
    char Element;
    int Left;
    int Right;
}T1[Maxsize],T2[Maxsize];
bool Check[Maxsize];

int TreeBuild(struct NodeTree T[])
{
    
    int Root = Null;
    char cl,cr;
    int n;
    cin>>n;
    if(n==0)return Null;
    for(int i=0;i<n;i++){
        Check[i]=false;
    }
    for(int i=0;i<n;i++){
        cin>>T[i].Element>>cl>>cr;
        if(cl=='-') T[i].Left=Null;
            else {
                T[i].Left=cl-'0';
                Check[T[i].Left]=true;
            }
        if(cr=='-') T[i].Right=Null;
            else {
                T[i].Right=cr-'0';
                Check[T[i].Right]=true;
            }
    }
    for(int i=0;i<n;i++){
        if(!Check[i]){
            Root=i;
        }
    }
    return Root;
}
int Isomorphic(int R1,int R2)
{
    if(R1 == Null && R2 == Null)/*如果两个树同时为空那么就同构*/
    {
        return 1;
    }
    else if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))/*如果两个树一个空一个不空*/
    {
        return 0;
    }
    else if(T1[R1].Element != T2[R2].Element)/*两棵树的根节点不同*/
    {
        return 0;
    }
    else if(T1[R1].Left == Null && T2[R2].Left == Null)/*如果两棵树左边都为空就比较右边*/
    {
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    }
    if(T1[R1].Left != Null && T2[R2].Left != Null/*如果两棵树左边都不为空*/
       && T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)/*且两棵树左子树的根相同*/
    {
        return (Isomorphic(T1[R1].Left ,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right));/*就看两棵树左边和右边是否都相同*/
    }
    else/*如果两棵树的左边不相同且都不为空或者一个空一个不空就同时看两遍的左右是否交换位置*/
    {
        return (Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left));
    }
}
int main()
{
    int R1,R2;
    R1=TreeBuild(T1);
    R2=TreeBuild(T2);
    if(Isomorphic(R1,R2)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

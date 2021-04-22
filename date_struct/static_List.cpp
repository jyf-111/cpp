#include<iostream>
#define Maxsize 11
#define Null -1
using namespace std;
using ElementType = int;

struct Node
{
    ElementType data;
    int curcor;
}List[Maxsize];


void InitList()
{
    for(int i = 1; i<Maxsize-1 ; i++){
        List[i].data=0;
        List[i].curcor=i+1;
    }
    List[0].curcor=Null;
    List[Maxsize-1].curcor=Null;
    List[Maxsize-1].data=0;
}

int getnode(int &av)
{
    if(av == Null){
        cout << "no more space" << endl;
        return Null;
    }else{
        int i = av;
        av = List[av].curcor;
        return i;
    }
}

void Delete(int &s,int &av)
{
    int pre = List[0].curcor;
    while(List[pre].curcor!= s){
        pre = List[pre].curcor;
    }
    List[s].curcor = av;
    av = s;
    List[pre].curcor = Null;
    s = pre;
}
//尾插
int lenth()
{
    int p = 0;
    int cnt = 0;
    while(List[p].curcor!=Null){
        cnt++;
        p=List[p].curcor;
    }
    return cnt;
}

void Insert(int &s,int &av,ElementType X)
{
    int space;
    
    space = getnode(av);
    if(space!=Null){
        List[s].curcor=space;
        List[space].data = X;
        List[space].curcor=Null;
        s=space;
    }
}

void printList()
{
    int p = List[0].curcor;
    while(p !=Null){
        cout << p <<" = "<<List[p].data << endl;
        p = List[p].curcor;
    }
    cout << endl;
}

int main()
{
    int av = 1; 
    int s=0;
    InitList();
    
    for(int i=0;i<Maxsize-1;i++){
        Insert(s,av,i);
    }
    for(int i = 0;i<Maxsize/2;i++)
        Delete(s,av);
    printList();
    
    return 0;
}

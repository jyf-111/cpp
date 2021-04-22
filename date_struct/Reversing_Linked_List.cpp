/*
给出一个常量K和单链表L，你要做的是反转L中的每K个元素。
例如给出的L是1→2→3→4→5→6，
若K=3，就要输出 3→2→1→6→5→4；若K=4，就要输出4→3→2→1→5→6。

input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1


00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
//可能有废弃节点
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100010
#define Null -1
struct Node
{
    int Address;
    int Data;
    int Next;
    int flag;
};

struct Node* InitList();
void PrintList(struct Node*);
struct Node* Reserve(struct Node*);
void Exchange(struct Node*,struct Node*);

int main()
{
    struct Node *List;
    List = InitList();
    List = Reserve(List);
    PrintList(List);
    return 0;
}
struct Node* InitList(){
    int i;
    
    struct Node *List = (struct Node*)malloc(Maxsize*sizeof(struct Node));
    //第一个节点存放基本信息
    scanf("%5d %d %d",&List[0].Address,&List[0].Data,&List[0].Next);
    
    for(i = 1 ; i<=List[0].Data ; i++){
        scanf("%5d %d %d",&List[i].Address,&List[i].Data,&List[i].Next);
        List[i].flag=0;
    }
    return List;
}

void PrintList(struct Node *List)
{
    int i;
    for( i = 1 ; i <= List[0].Data ; i++){
        if(List[i].flag==1){
            if(List[i].Next!=Null){
                printf("%05d %d %05d\n",List[i].Address,List[i].Data,List[i].Next);
            }else{
                printf("%05d %d %d\n",List[i].Address,List[i].Data,List[i].Next);
            }
        }
    }
}

void Exchange(struct Node* a,struct Node* b)
{
    struct Node temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
struct Node* Reserve(struct Node* List)
{
    int i,j,A=List[0].Address;

/*排序链表并处理好多余节点*/
    for(i = 1 ; i<=List[0].Data ; i++){
        for( j = i ; j<=List[0].Data ;j++){
            if(List[j].Address==A){
                A=List[j].Next;
                Exchange(&List[j],&List[i]);
                List[i].flag=1;
                break;
            }
        }
    }
    int cnt=0;
    for(i=1;i<=List[0].Data;i++){
        if(List[i].flag==1){
            cnt++;
        }
    }//printf("|%d|",cnt);
    /*转置链表*/
    int num=(cnt<List[0].Next)?cnt:List[0].Next;
    
    int temp;
    for(i=1,j=num;i<j;i++,j--){
        Exchange(&List[i],&List[j]);
    }

        for(i = 1 ; i<=num ; i++){
            List[i].Next=List[i+1].Address;

        }
        if(List[0].Data==List[0].Next)List[i-1].Next=Null;
    return List;
}
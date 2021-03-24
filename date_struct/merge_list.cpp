#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
/*本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。*/
List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List pa,pb,pc,L;
	L=(List)malloc(sizeof(struct Node));/*返回的链表*/
	pa=L1->Next;
	pb=L2->Next;
	pc=L;
	/*尾插法*/
	while(pa&&pb)
	{
		if(pa->Data<=pb->Data){
			pc->Next=pa;
			pc=pa;
			pa=pa->Next;
		}else{
			pc->Next=pb;
			pc=pb;
			pb=pb->Next;
		}
	}
	/*接入余下链表*/
	pc->Next=pa?pa:pb;
	
	L1->Next=NULL;
	L2->Next=NULL;
	return L;
}
List Read()
{
	int n;
	scanf("%d",&n);
	List L=(List)malloc(sizeof(PtrToNode));
	L->Next=NULL;
	if(n)
	{
		List r=L;
		for(int i=0;i<n;i++)
		{
			List p=(List)malloc(sizeof(struct Node));
			scanf("%d",&(p->Data));
			r->Next=p;
			r=p;
		}
		r->Next=NULL;
	}
	return L;
}

void Print(List L)
{
	List p=L->Next;
	if(p)
	{
		List r;
		r=L;
		while(r->Next)
		{
			r=r->Next;
			printf("%d ",r->Data);
		}
	}
	else
	{
		printf("NULL");
	}
	printf("\n");
}


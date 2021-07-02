//ʹ���������ݽṹ
#include<iostream>
using namespace std;
//#define NULL 0
#define N 100

typedef  struct  BiTNode {  
	int  data;
    struct  BiTNode *lchild, *rchild;
}BiTNode, * BiTree;

int datagroup[N];
int num;
	
/*��Ƶ�һ������
void CreateTree(BiTree *t);�ú����Ĺ����ǽ�����datagroup�е����ݣ��������������ʽ�����һ��������
datagroup�����Ԫ�ص�ֵ��Ϊ���и����ڵ�����ݣ����涨���ĳ��Ԫ�ص�ֵΪ-1����ʾ��Ӧ�Ľڵ���NULL�ڵ㡣*/

/*��Ƶڶ�������
void InOrder( BiTree t );�ú����Ĺ�����t��ָ����������������������ڱ����н����ݷ�������datagroup�У�
������Ч�ڵ���������NULL�ڵ㣩����ȫ�ֱ���num�С�*/
void CreateTree(BiTree *t) {
	*t = new struct BiTNode;	
	(*t)->lchild = nullptr;
	(*t)->rchild = nullptr;
	(*t)->data = datagroup[num];
	if(datagroup[num++]!=-1){
		CreateTree(&(*t)->lchild);
		CreateTree(&(*t)->rchild);
	}
}

void InOrder( BiTree t ) {
	if(t) {
		InOrder(t->lchild);
		if(t->data != -1)
		datagroup[num++] = t->data;
		InOrder(t->rchild);
	}
}

int main(int argc, char* argv[])
{
	BiTree root=nullptr; 
	int i;

	for(i = 0; i < 15;i++)
		scanf("%d", &datagroup[i]); 
	CreateTree(&root);
	num = 0;
	InOrder( root );
	for(i = 0; i < num; i++)
		printf("%d ", datagroup[i]);
	printf("\n");
}
/*
��������Ϊ
1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 -1 -1
ִ�еĽ��Ϊ
4 2 5 1 6 7 3
*/
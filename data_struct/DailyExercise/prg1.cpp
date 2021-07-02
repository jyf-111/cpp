/*���һ������
	void merge(SeqList *LA, SeqList *LB, SeqList *LC) 
�ú����Ĺ����ǽ��ݼ�˳���LA��LB�ͺϲ����ݼ�˳���LC��
����SeqList�ṹ���£�
typedef  struct{ 
    int  elem[maxsize]; 
    int  last;
}SeqList; 

���µ�main����ִ�к�
int main(int argc, char* argv[])
{
	SeqList LA, LB, LC;
	int i;

	for(i = 0; i < 10;i++)
	{
		LA.elem[i] = 20-2*i;
	}
	LA.last = 9;

	for(i = 0; i < 8;i++)
	{
		LB.elem[i] = 24-3*i;
	}
	LB.last = 7;

	merge(&LA, &LB, &LC);
	
	for(i = 0; i <= LC.last ;i++)
	{
		printf("%d ", LC.elem[i]);
	}
	printf("\n");
	return 0;
}
ִ�еĽ��Ϊ
24 21 20 18 18 16 15 14 12 12 10 9 8 6 6 4 3 2 */
#include<iostream>
#define maxsize 10
using namespace std;

typedef  struct{ 
    int  elem[maxsize]; 
    int  last;
}SeqList; 

void merge(SeqList *LA, SeqList *LB, SeqList *LC) ;

int main(int argc, char* argv[])
{
	SeqList LA, LB, LC;
	int i;

	for(i = 0; i < 10;i++)
	{
		LA.elem[i] = 20-2*i;
	}
	LA.last = 9;

	for(i = 0; i < 8;i++)
	{
		LB.elem[i] = 24-3*i;
	}
	LB.last = 7;

	merge(&LA, &LB, &LC);
	
	for(i = 0; i <= LC.last ;i++)
	{
		printf("%d ", LC.elem[i]);
	}
	printf("\n");
	return 0;
}

void merge(SeqList *LA, SeqList *LB, SeqList *LC) {
	int i=0;
	int j=0;
	for(auto &i : LC->elem) {
		i = 0;
	}
	LC->last = 0;

	while(i<=LA->last && j<=LB->last) {
		if(LA->elem[i] >= LB->elem[j]) {
			LC->elem[LC->last] = LA->elem[i++];
		}else{
			LC->elem[LC->last] = LB->elem[j++];
			
		}
		(LC->last)++;
	}
	while(i<=LA->last) {
		LC->elem[++LC->last] = LA->elem[i++];
	}
	while(j<=LB->last) {
		LC->elem[++LC->last] = LB->elem[j++];
	}
	
}
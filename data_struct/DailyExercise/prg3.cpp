/*���һ������
void LinkReverse(List *pla)*/
#include<iostream>
using namespace std;
/*�书�ܽ���ͷ���ĵ�������ת��la��һ����ͷ��������������Ŀ������ת�������Ҳ���ǵ�һ����������һ����㣬�ڶ�������Ϊ�����ڶ�����㣬�Դ����ơ��ú����Ŀռ临�Ӷ�ΪO(1����
Ҳ���Ǹú������ܶ������������ʹ�ö�̬���亯����
����List�����½ṹ�壺*/
typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
//���µ�main����ִ�к�
//����ͷָ��Ϊla������
void createlink(List *pla)
{
	int i;
	Node *p;

	*pla = (Node *)malloc(sizeof(Node));     //����ͷ���
	p = *pla;

	for(i = 1; i <=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i;
		p->next = NULL;
	}
}

void LinkReverse(List *pla) {
	Node* p = (*pla)->next;
	Node* q;
	(*pla)->next = nullptr;
	while(p) {
		q = p->next;
		p->next = (*pla)->next;
		(*pla)->next = p;
		p = q;
	}
}

int main( )
{
	List la, p;
	int i;

	createlink(&la);
	LinkReverse(&la);

	p = la->next;
	for(i = 1; i <=10;i++)
	{
		printf("%4d",p->d);
		p = p->next;
	}
	printf("\n");
}
/*ִ�еĽ��Ϊ
  10   9   8   7   6   5   4   3   2   1*/

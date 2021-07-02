/*���һ������
	void  Intersection (List La, List Lb)*/
#include<iostream>
using namespace std;
/*
�书������Lb��La�Ľ������ҽ������Ľ������La�У�����La��Lb��Ԫ�ؾ�Ϊ�ϸ�����������У��󽻼����La��Ԫ��ҲΪ�ϸ�����������С�La��Lb�Ǵ�ͷ���ĵ�������
����List�����½ṹ�壺*/

typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
/*�����У����������µĽ�㣬���������Ѿ��еĽ�㡣

���µ�main����ִ�к�*/
//����ͷָ��Ϊla, lb����������
void createlink(List *pla, List *plb)
{
	int i;
	Node *p;

	*pla = (Node *)malloc(sizeof(Node));     //����ͷ���
	p = *pla;

	for(i = 1; i <=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i*2;
		p->next = NULL;
	}


	*plb = (Node *)malloc(sizeof(Node));     //����ͷ���
	p = *plb;

	for(i = 1; i <= 8;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i+6;
		p->next = NULL;
	}
}


void  Intersection (List La, List Lb) {
	Node* p1,* p2 ,*pre;
	bool flag = true;//trueΪ��ɾ��
	p1 = La->next;
	pre = La;
	while(p1) {
		flag = true;
		p2 = Lb->next;
		while(p2) {
			if(p1->d == p2->d) {
				flag = false;
				break;
			}
			p2 = p2->next;
		}
		if(flag) {
			Node* temp = p1;
			p1 = p1->next;
			pre->next = p1;
			free (temp);
		}else{
			pre = pre->next;
			p1 = p1->next;
		}
	}
}

int main()
{
	int i;

	List la, lb;
	Node *p;

	createlink(&la, &lb);
	Intersection (la, lb);
	
	p = la->next;
	while(p!=NULL)
	{
		printf("%4d",p->d);
		p = p->next;
	}
	printf("\n");
}
/*
ִ�еĽ��Ϊ
   8  10  12  14
*/

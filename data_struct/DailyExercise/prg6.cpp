//���һ������
//	void  add_poly( Polylist pa,  Polylist pb )
#include<iostream>
using namespace std;
//�书����pb��pb�Ķ���ʽ������ӡ�
//����Polylist�����½ṹ�壺
typedef struct Polynode {
  int coef;  //����
  int exp;   //��
  struct Polynode *next;
}Polynode , * Polylist; 

//��������ʽ�ĺ������£�
Polylist polycreate( ) 
{
	Polynode *rear, *head, *s;

	int c, e;
	
	rear=head=(Polynode *)malloc(sizeof(Polynode));  
	scanf("%d%d",&c,&e); 
	while(c!=0) 
	{ 	
		s=(Polynode*)malloc(sizeof(Polynode));
		s->coef=c; 
		s->exp=e; 
		rear->next=s; 
		rear=s;  
		scanf("%d%d",&c,&e); 
	}
	rear->next=NULL; 
	return(head);
}

//��ʾ����ʽ�ĺ�������
void print(Polylist p)
{
	int j;

	p = p->next;
	while(p)
	{
		printf("%d", p->coef);
		for(j = 0; j< p->exp; j++)
			printf("*x");
		if(p->next!=NULL)
			printf(" + ");
		p = p->next;
	}
	printf("\n");
}


void  add_poly( Polylist pa,  Polylist pb ) {
	Polynode* p = pa->next;
	Polynode* q = pb->next;
	Polynode* pre = pa;
	int c ;
	while(p && q){
		if(p->exp==q->exp) {
			c = p->coef + q->coef  ;
			if(c!=0) {
				p->coef = c;
				p = p->next;
				q = q->next;
				pre = pre->next;
			}else{
				Polynode* temp = p;
				pre->next = p->next;
				p = p->next;
				q = q->next;
				free(temp);
			}
		}else{
			if(p->exp > q->exp) {
				pre->next = q;
				q = q->next;
				pre->next->next = p;
				pre = pre->next;
			}else{
				p = p->next;
				pre = pre->next;
			}
		}
	}
	if(q) {
		pre->next = q;
	}
}
//��ִ�����µ�main������
int main(int argc, char* argv[])
{
	Polylist pa, pb;   //����������ʾ����ʽ������

	pa = polycreate();  //����pa����
	pb = polycreate();  //����pb����
	add_poly(pa, pb);   //���ӷ������������pa������
	print(pa);          //���ӷ��Ľ����һ������ʽ��ʽ��ʾ������豸��
}
/*����Ӽ��������ֵ���£�
5 0
3 5
4 8
0 0
5 0
3 5
4 8
0 0

��ִ�еĽ��Ϊ
10 + 6*x*x*x*x*x + 8*x*x*x*x*x*x*x*x
*/
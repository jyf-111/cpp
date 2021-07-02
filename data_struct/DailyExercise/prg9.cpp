/*���һ������
	double getaverage(List f, int *nodenum) 
��֪fΪһ������ͷ��㵥�������ͷָ�룬���������ݽṹ������ʾ��ʹ�õݹ麯����������н������ֵ��ƽ������	
nodenumΪ����������������	����ƽ���������Ϊ�������򷵻�0��*/
#include<iostream>
using namespace std;
/*List�Ľṹ���£�*/
typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
//createlink�������£�
void createlink(List *pf)
{
	int i;
	Node *p;

	*pf = (Node *)malloc(sizeof(Node));
	p = *pf;
	for(i = 1; i <= 99; i++)
	{
		p->d = i;
		p->next = (Node *)malloc(sizeof(Node));
		p = p->next;
	}
	p->d = 100;
	p->next  = NULL;
}

double getaverage(List f, int *nodenum) {
	if(f==nullptr) {
		*nodenum = 0;
		return 0.0;
	}
	
	double sum =  (f->d +  getaverage(f->next,nodenum)* *nodenum)/(*nodenum + 1);
	(*nodenum )++;

	return sum;
	
}

//���µ�main����ִ�к�
int main(int argc, char* argv[])
{
	int n;
	List f;
	double a;
	createlink(&f);
	a = getaverage(f, &n);
	printf("%d  %lf\n",n, a);
	return 0;
 }
/*ִ�еĽ��Ϊ
100  50.500000
*/
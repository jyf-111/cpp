/*���һ����ʾƽ����Բ��״��circle��ṹ���£�*/
#include<iostream>
#include<cmath>
using namespace std;

class circle 
{
protected:
	double x,y;     //x��y��ʾΪԲ��Բ������ 
	double r;       //r��ʾԲ�İ뾶
public:
	circle(double a,double b, double c);              //��ʼ��Բ�����ԣ�a,bΪԲ�����꣬cΪ�뾶
	friend int relation(circle c1, circle c2);
};
/*
relationΪ�������Ԫ���������ж�c1��c2����Բ�Ĺ�ϵ��
����0��ʾ����Բ��ȫ�غϣ�����1��ʾ����Բû�н�������ȫ�ֿ�������2��ʾ����Բ���ص�������Ҳ��ʾ�ص�����
���༰����Ԫ������ɺ�����main()��������ִ�С�*/

circle::circle(double a,double b, double c) : x(a) , y(b) , r(c) { }   
int relation(circle c1, circle c2) {
    if(c1.r==c2.r&&c1.x==c2.x&&c1.y==c2.y) return 0;
    else if(sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)) > c1.r+c2.r) return 1;
    else return 2;
}


int main()
{
	circle c1(2,2,2);
	circle c2(29,1,2);
	circle c3(2,2,10);
	circle c4(0,0,0);
	circle c5(3,4,5);

	switch(relation(c1,c1))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

	switch(relation(c2, c3))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

	switch(relation(c4, c5))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

}
/*
ִ�еĽ��Ϊ
overlapping
separate
intersect
?
*/
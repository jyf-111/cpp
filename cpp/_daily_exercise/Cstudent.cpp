/*���һ��CStudent�࣬���а���ѧ����Ϣ������������ѧ�š�Ӣ���ѧ��������Ƴɼ���ƽ���ɼ���
����Ľṹ���£�*/
#include <iostream>
#include<iomanip>
using namespace std;
class CStudent{
private:
	char stuno[20];    //ѧ��
	char  name[20];    //��������Ӣ�ﲻ���Ǻ���
	int english;       //Ӣ��ɼ���С�ڵ���100�����ڵ���0�����ڴ˷�Χ��0�ִ���
	int math;          //��ѧ�ɼ���С�ڵ���100�����ڵ���0�����ڴ˷�Χ��0�ִ���
	int programe;      //������Ƴɼ���С�ڵ���100�����ڵ���0�����ڴ˷�Χ��0�ִ���
	double avg;        //ƽ���ɼ���С�����ֻȡһλ�����ಿ���������봦��
public:
	CStudent();
	//����ƽ���ɼ�
	void getavg();
	//��ʾ������¼����
	void print();
};
void CStudent::print()
{
    cout << fixed  << setprecision(1);
	cout << "ѧ�ţ�"<<stuno << "  ������"<<name<<"  Ӣ��ɼ���"<<english<<"  ��ѧ�ɼ���"<<math<<"  ������Ƴɼ�"<<programe<<"  ƽ���ɼ�"<<avg<<endl;
}

CStudent::CStudent() : avg(0) {
    cin >> stuno >> name >> english >> math >> programe ;
    if(math<0)  math = 0;
    if(english<0)  english = 0;
    if(programe<0) programe=0;
}

void CStudent::getavg() {
    avg = (english+math+programe)/3.0;
}
//����main����ִ�к�
int main()
{
	CStudent s[3];

	for(int i = 0; i < 3; i++)
	{
		s[i].getavg();
		s[i].print();
	}
	return 0;
}
/*
���������������ݣ�
1101001 zhangsan 85 69 89
1101002 lisi 75 89 77
1101003 wangwu 100 100 -89
ִ�еĽ��Ϊ
ѧ�ţ�1101001  ������zhangsan  Ӣ��ɼ���85  ��ѧ�ɼ���69  ������Ƴɼ�89  ƽ���ɼ�81
ѧ�ţ�1101002  ������lisi  Ӣ��ɼ���75  ��ѧ�ɼ���89  ������Ƴɼ�77  ƽ���ɼ�80.3
ѧ�ţ�1101003  ������wangwu  Ӣ��ɼ���100  ��ѧ�ɼ���100  ������Ƴɼ�0  ƽ���ɼ�66.7
*/
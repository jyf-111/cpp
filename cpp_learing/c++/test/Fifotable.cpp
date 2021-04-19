/*���һ��FifoTable���ʾ���ζ��У������ĸ�˽�����ԣ��ֱ�Ϊ��
	int table[SIZE];   //��Ŷ������ݵ�����
	int tail;          //����βָ��
	int head;          //����ͷָ��
	int max,min;       //����Ԫ�صĽ磬Ҳ�������������е�Ԫ��ֵ����max����С��min����������޷��ɹ���
�������г�Ա��������
FifoTable(int max,int min);   //�ṹ���������ö����max��minֵ��
bool AddElement(int d);       //����м���һ��Ԫ��d���ɹ������棬���򷵻ؼ١�����������ˣ����µ�ֵ�޷�����
int GetElement();             //�Ӷ���ͷ��ȡһ��Ԫ�أ������ظ�Ԫ��ֵ���������Ϊ�գ��򷵻�NULLVALUE
����NULLVALUE��SIZEֵ����
const int NULLVALUE= 999999;
const int SIZE = 10;

����Ĵ�����ɺ�����main()��������ִ�С�
*/
#include<iostream>
using namespace std;
const int NULLVALUE= 999999;
const int SIZE = 10;

class FifoTable {
 private:
    int table[SIZE];   //��Ŷ������ݵ�����
	int tail;          //����βָ��
	int head;          //����ͷָ��
	int max,min;       //����Ԫ�صĽ磬Ҳ�������������е�Ԫ��ֵ����max����С��min����������޷��ɹ���
 public:
    FifoTable(int _max,int _min);   //�ṹ���������ö����max��minֵ��
    bool AddElement(int d);       //����м���һ��Ԫ��d���ɹ������棬���򷵻ؼ١�����������ˣ����µ�ֵ�޷�����
    int GetElement() ;             //�Ӷ���ͷ��ȡһ��Ԫ�أ������ظ�Ԫ��ֵ���������Ϊ�գ��򷵻�NULLVALUE
};


FifoTable::FifoTable(int _max,int _min) : max( _max ) , min( _min ) , head(0) , tail(0) {}

inline bool FifoTable::AddElement(int d) { 
    if(d > max || d < min)
        return false;
    if((tail+1)%SIZE==head)
        //������
        return false;
    table[tail] = d;
    tail=(tail+1)%SIZE;

    return true;
}

inline int FifoTable::GetElement() {
    if(head == tail)
        return NULLVALUE;
    else {
        int result = table[head];
        head = (head+1)%SIZE;
        return result;
    }
}

int main()
{
	FifoTable ft(20,-2);
	int i;

	for(i = -2; i <= 23; i++)
		ft.AddElement(i);

	for(i = 0; i < 9; i++)
		cout << ft.GetElement() << ",";

	cout << ft.GetElement() << endl;
    return 0;
}
/*
ִ�еĽ��Ϊ��
-2,-1,0,1,2,3,4,5,6,999999
*/
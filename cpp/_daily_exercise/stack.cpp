/*���һ��stack��Ľṹ������������ջ�Ĺ��ܡ���ջ��Ԫ������Ϊint��������Ϊ100���������push��pop���������ֱܷ�Ϊѹջ�ͳ�ջ��
����main()��������ִ�С�*/
#include<iostream>
#define Maxsize 100
#define stack Stack

using namespace std;
using ElementType = int;


class Stack {
 private:
    ElementType data[Maxsize];
    mutable int top = -1;
 public:
    Stack( ) = default;
    void push(ElementType X) {data[++top] = X;}
    ElementType pop() const {return data[top--];};
    ~Stack() = default;
};

int main()
{
	stack s1;
	int i;

	for(i = 1; i < 10;i++)
		s1.push(i);
	for(i = 1; i <6;i++)
		cout << s1.pop()<<",";
	s1.push(200);
	cout << s1.pop()<<endl;
 
    return 0;
}
/*ִ�еĽ��Ϊ
9,8,7,6,5,200
*/
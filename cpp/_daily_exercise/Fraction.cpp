/*
���һ��Fraction��Ľṹ�������ʾһ�����Ե���ǰ���Ĺ�����������������������˽������
	int den; //����ǰ���Ĳ�������,Ҳ����ִ��++��������������
	int num; //��ǰ������ֵ
��ƺ�ʵ�ָ�����Ӧ�Ľṹ������print����������������ǰ׺++������źͺ�׺++������š�
������ɺ�����main()��������ִ�С�
void main()
{
 Fraction b(1,10),a(4,-8);

  (a++).print();
  a.print();

  a = b++;
  a.print();

  a = ++b;
  a.print();
  
}
ִ�еĽ��Ϊ
-8
-4
10
12
*/
#include<iostream>
using namespace std;

class Fraction
{
private:
    /* data */
    int den; //����ǰ���Ĳ�������,Ҳ����ִ��++��������������
	int num; //��ǰ������ֵ
public:
    Fraction(/* args */) :den(0),num(0) {}
    Fraction(int den,int num) : Fraction() {this->den=den,this->num=num;}
    void print() const { cout << num << endl;}
    Fraction& operator ++() {
        num+=den;
        return *this;
    }
    Fraction operator ++(int) {
        Fraction old = *this;
        ++ *this;
        return old;
    }
    ~Fraction() {}
};
int main()
{
     Fraction b(1,10),a(4,-8);

  (a++).print();
  a.print();

  a = b++;
  a.print();

  a = ++b;
  a.print();
}
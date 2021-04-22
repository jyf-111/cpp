#include<iostream>

using namespace std;

class Base1 {
public:
    virtual void display()const { cout << "Base1::display()" << endl;}
    Base1() {cout << "Base1" << endl;}
    Base1(int a) {cout <<"base1::Base(int a)" << endl;}
};

class Base2 : public Base1 {
public:

    /*virtual*/void display()const override { cout << "Base2::display()" << endl;}
    Base2() {cout << "Base2" << endl;}
    Base2(int a) {cout <<"base2::Base(int a)" << endl;}
    Base2(const Base2 &base2) { cout << "copy construct is done" << endl;}
};

class Derive :public Base2 {
public:
    using Base2::Base2;

    /*virtual*/void display()const override final{ cout << "Derive::display()" << endl;}
    Derive(const Derive & derive) : Base2(derive){ /*���Լ����帴�ƹ��캯����Ҫ�̳л��ิ�ƹ��캯��*/}
};

void fun(Base1 *ptr) {//������ָ�����ת��Ϊ����ָ��
    ptr->display();
}

int main()/*override��������븲��final�ú����������ٱ�����*/
{
    Base1 base1(0);
    Base2 base2(0);
    Derive derive(0);//������ֱ������ֱ�ӻ��๹�캯�������캯���������Ĭ���βΣ����������� 
    Derive derive2(derive);
    fun(&base1);
    fun(&base2);
    fun(&derive);//��̬�麯��  ֻ��ָ������ÿ��ԣ����󲻿���
    return 0;
}
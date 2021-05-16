/*
���һ��Complex��Ľṹ�������ʾ����������ƺ�ʵ�ָ�����Ӧ�Ľṹ������show����������������+��*������š�
������ɺ�����main()��������ִ�С�
void main()
{
	Complex c1(3, 5);
	Complex c2 = 4;
	c1 = c1 + c2;
	c2 = c1 * c2;
	c1.show();
	c2.show();

}
ִ�еĽ��Ϊ
7+5i
28+20i
*/
#include<iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::ios;
using ElementType = int;

class Complex {
private:
    ElementType real;
    ElementType image;
public:
    Complex() : real(0),image(0) { }
    Complex(ElementType _real =0,ElementType _image =0) { real = _real; image = _image;}
    
    friend Complex operator + (Complex &a,Complex &b);
    Complex operator * (Complex c); 
    void show() const ;
};

Complex operator + (Complex &a,Complex &b) {
    return Complex(a.real+b.real,a.image+b.image);
}

Complex Complex::operator * (Complex c) {
    return Complex(real*c.real - image*c.image , 
                                real*c.image + image*c.real );
}


void Complex::show() const {
    if(image==0){
        cout << real << endl;
    }else{
        cout << resetiosflags(ios::showpos)<< real << setiosflags(ios::showpos) << image << 'i' <<endl; 
    }
}
int main()
{
	Complex c1(3, 5);
	Complex c2 = 4;
	c1 = c1 + c2;
    	
	c2 = c1 * c2;

	c1.show();
	c2.show();
    return 0;
}
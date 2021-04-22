#include<iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0 , double i = 0.0): real(r),imag (i) { }
    void display()const;
    //类的成员函数
    Complex operator+(const Complex&c2)const;
    Complex operator-(const Complex&c2)const;
    //类的非成员函数
    friend Complex operator+(const Complex&c1,const Complex& c2);
    friend Complex operator-(const Complex&c1,const Complex& c2);
    friend ostream & operator<<(ostream & out ,Complex &c) ;
};

inline void Complex::display() const {
    cout << real << " + " << imag << " i" << endl;
}

Complex Complex::operator+(const Complex&c2)const {
    return Complex(real+c2.real,imag+c2.imag);
}

Complex Complex::operator-(const Complex&c2)const {
    return Complex(real-c2.real,imag-c2.imag);
}


Complex operator+(const Complex&c1,const Complex& c2) {
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator-(const Complex&c1,const Complex& c2) {
    return Complex(c1.real-c2.real,c2.imag-c2.imag);
}
ostream & operator<<(ostream & out ,Complex &c) {
    out << c.real << " + " << c.imag << " i" << endl;
    return out;
}
int main()
{
    Complex a(5,4),b(2,10),c;
    cout << "a = " ;
    a.display();
    cout << "b = ";
    b.display();
    c = a-b;
    cout << "c = ";
    c.display(); 

    c = a+b;
    cout << c;
} 
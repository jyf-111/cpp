#include<iostream>
using namespace std;

template<typename T>
class Complex {
private:
    T real;
    T image;
public:
    Complex() : real(0),image(0) { }
    Complex(T real,T image =0 ) : Complex() { this->real = real ; this->image = image; }
    Complex<T> operator + (Complex<T> &x) ;
    Complex operator * (Complex &x) ;
    void show() const ;
    friend ostream& operator << (ostream& out,const Complex<T> &a) {
    if(a.image!=0) {
        out << a.real << showpos << a.image << noshowpos << "i" << endl;
    }else{
        out << a.real << endl;
    }
    return out;
}
};

template<typename T>
Complex<T> Complex<T>::operator + (Complex<T> &x) {
    return Complex<T>(real+x.real,image+x.image);
}

template<typename T>
Complex<T> Complex<T>::operator*(Complex &x) {
    return Complex(real*x.real-image*x.image,real*x.image+image*x.real);
}

template<class T>
void Complex<T>::show() const {
    if(image!=0) {
        cout << real << showpos << image << noshowpos << "i" << endl;
    }else{
        cout << real << endl;
    }
}




int main()
{
    Complex<int> a(1,2);
    //cout << a;
    Complex<int> b(2,3);
    //(a+b).show();
    cout << a+b;
}
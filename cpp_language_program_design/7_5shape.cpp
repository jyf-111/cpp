#include<iostream>
using namespace std;

class Shape {
public:
    virtual double getarea() = 0;
};

class Rectangle :public Shape {
private:
    double longth;
    double width;
public:
    Rectangle () : longth(0),width(0) { }
    Rectangle (int l,int w) :longth(l),width(w) { }
    double getarea() {return longth*width;}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle() :radius(0) { }
    Circle(int r) : radius(r) { }
    double getarea() {return 3.14*radius*radius;}
};

class Square : public Rectangle {
public:
    Square() : Rectangle(0,0) { }
    Square(int a) : Rectangle(a,a) { }
    double getarea() {return Rectangle::getarea();}
};

int main()
{
    Shape *p;
    p = new Circle(5);
    cout << p->getarea() << endl;
    delete p;

    p = new Rectangle(4,5);
    cout << p->getarea() << endl;
    delete p;

    p = new Square(10);
    cout << p->getarea() << endl;
}
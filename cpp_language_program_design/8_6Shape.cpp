#include<iostream>
using namespace std;

class Shape {
public:
    virtual double getarea() = 0;
    virtual double getPerim() = 0;
};

class Rectangle :public Shape {
private:
    double longth;
    double width;
public:
    Rectangle () : longth(0),width(0) { }
    Rectangle (int l,int w) :longth(l),width(w) { }
    double getPerim() {return 2*(longth+width);}
    double getarea() {return longth*width;}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle() :radius(0) { }
    Circle(int r) : radius(r) { }
    double getPerim() {return 2*3.14*radius;}
    double getarea() {return 3.14*radius*radius;}
};


int main()
{
    Shape *p;
    p = new Circle(5);
    cout << p->getarea() << endl;
    cout << p->getPerim() << endl;
    delete p;

    p = new Rectangle(4,5);
    cout << p->getarea() << endl;
    cout << p->getPerim() << endl;
    delete p;

}
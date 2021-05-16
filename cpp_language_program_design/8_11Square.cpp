#include<iostream>
using namespace std;

class Shape {
public:
    virtual double getarea() = 0;
    virtual double getPerim() = 0;
    void getVertexCount(Shape* a) const ;
    virtual void getVertex() = 0;
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
    void getVertex() {
        cout << '4' << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle() :radius(0) { }
    Circle(int r) : radius(r) { }
    double getPerim() {return 2*3.14*radius;}
    double getarea() {return 3.14*radius*radius;}
    void getVertex() {
        cout << '0' << endl;
    }
};

class Square : public Rectangle {
private:
    /* data */

public:
    Square(int r = 0): Rectangle(r,r) { }
    double getRerim() { return Rectangle::getPerim();}
    double getarea() { return Rectangle::getarea();}
    ~Square() {}
    void getVertex() { Rectangle::getVertex();}   
};

void Shape::getVertexCount(Shape* a) const {
/*  //dynamic_cast:::
    Rectangle* p = dynamic_cast<Rectangle*>(a) ;
    if(p!=nullptr) {cout << "4" << endl;}

    Circle* q = dynamic_cast<Circle*>(a) ;
    if(q!=nullptr) {cout << "0" << endl;}
*/
/*  //typeid:::
    if(typeid(*a)==typeid(Rectangle)) cout << "'#4#'" << endl;

    if(typeid(*a)==typeid(Circle)) cout << "'#0#'" << endl;

    if(typeid(*a)==typeid(Square))cout << "$4$" << endl;
*/

}

int main()
{

    Shape *p;
    p = new Circle(5);

    cout << p->getarea() << endl;
    cout << p->getPerim() << endl;
    p->getVertexCount(p);
    p->getVertex();
    delete p;

    p = new Rectangle(4,5);
    cout << p->getarea() << endl;
    cout << p->getPerim() << endl;
    p->getVertexCount(p);
    p->getVertex();
    delete p;

    p = new Square(10);
    cout << p->getPerim() << endl;
    cout << p->getarea() << endl;
    p->getVertexCount(p);
    p->getVertex();

}
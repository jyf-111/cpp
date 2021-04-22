#include<iostream>
#include<cmath>
using namespace std;

class Point
{
 public:
    Point(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }
    Point(Point &p);
    int getX()const{return x;}
    int getY()const{return y;}
 private:
    int x,y;
};

Point::Point(Point &p) {
    x = p.x;
    y = p.y;
    cout << "calling the copy constructor of Point" << endl;
}

class Line 
{
 public:
    Line(Point xp1,Point xp2);
    Line(Line &l);
    double getLen() const ;
 private:
    Point p1,p2;
    mutable double len;     //可修改尽管const
};
Line::Line(Point xp1,Point xp2) : p1(xp1),p2(xp2) {
    cout << "calling the constructor of Line" << endl;
}

Line::Line(Line &l) :p1(l.p1),p2(l.p2) {
    cout << "calling the copy constructor of Line" << endl ;
    len = l.len;
}

double Line::getLen() const {
    double x = static_cast<double>(p1.getX()-p2.getX());
    double y = static_cast<double>(p1.getY()-p2.getY());
    len = sqrt(x*x+y*y);
    return len;
}
int main()
{
    Point myP1(1,1),myP2(4,5);
    Line line(myP1,myP2);
    Line line2(line);
    cout << line.getLen() << endl << line2.getLen() << endl;
    //通过指针访问
    /*int (Point::*p)()const = &Point::getX;
    cout << "function ptr  -> myP2.getX()"<<(myP2.*p)() <<endl;
    Point* ptr = &myP2;
    cout << (ptr->*p)() << endl;
    cout << ptr->getX();*/
    return 0;
}
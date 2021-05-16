#include<iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle() : radius(0) { }
    Circle(double r) : radius(r) { }
    void getArea() const { cout << 3.14*radius*radius << endl;}
};

int main()
{
    Circle C;
    C = static_cast<Circle>(5.5);
    C.getArea();
}
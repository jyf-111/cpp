#include<iostream>
using namespace std;

class Point
{
private:
    int x,y;
public:
    Point(/* args */):x{0},y{0} {}
    Point(int x ,int y =0) : Point() {this->x = x; this->y = y;} 
    friend Point operator+(Point a,Point b);
    void show() const { cout << x  << "  "<< y << endl;}
    ~Point() {}
};

Point operator+(Point a,Point b) {
    return Point(a.x+b.x,a.y+b.y);
}

int main() {
    Point a(1,2);
    Point b(2,3);
    Point c = a+b;
    c.show();
}
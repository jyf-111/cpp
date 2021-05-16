#include<iostream>
using namespace std;

class Point
{
private:
    int x,y;
public:
    Point(/* args */):x{0},y{0} { }
    Point(int _x,int _y):x(_x),y(_y) { }
    Point& operator++();
    Point operator++(int);
    Point& operator--();
    Point operator--(int);
    void show() const { cout << '(' << x <<',' << y << ')';}
    ~Point() {}
};

Point& Point::operator++() {
    ++x,++y;
    return *this;
}
Point Point::operator++(int) {
    Point old = *this;
    ++ (*this);
    return old;
}
Point& Point::operator--() {
    --x,--y;
    return *this;
}
Point Point::operator--(int) {
    Point old = *this;
    -- (*this);
    return old;
}

int main()
{
    Point p(1,2);
    p.show();
    (p++).show();
    (++p).show();
   
}
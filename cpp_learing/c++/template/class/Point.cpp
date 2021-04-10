#include<iostream>
using namespace std;
#include<cmath>
class Point
{
    public:
        Point() { ++count; } 
        Point(const Point &p) : Point(p.x,p.y) { }
        Point(int _x,int _y) : x{_x},y{_y} { ++count; }
        void getx(){ cout << "x = " << x << endl ;}
        void gety(){ cout << "y = " << y << endl ;}

        friend void distance(const Point &p1,const Point &p2);

        static void getcount() { cout << "count = " <<count << endl;}
        ~Point( ) {--count;}
    private:
        int x;
        int y;
        static int count ;
};

void distance(const Point &p1,const Point &p2)
{
    float dis = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    cout << "distance = " << dis << endl;
}
int Point::count = 0;
int main()
{
    Point p1(1,2);
    {
    Point::getcount();//构造+1

    Point p2 = p1;  //拷贝委托+1
    Point::getcount();
     
    distance(p1,p2);
    }
    
    Point::getcount();//析构减1
    return 0;
}

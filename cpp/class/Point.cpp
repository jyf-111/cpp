#include<iostream>
using namespace std;
#include<cmath>
class Point
{
    public:
        Point() { ++count; } 
        Point(const Point &p) : Point(p.x,p.y) { }
        Point(float _x,float _y) : x{_x},y{_y} { ++count; }
        void getx()const{ cout << "x = " << x << endl ;}
        void gety()const{ cout << "y = " << y << endl ;}

        friend void distance(const Point &p1,const Point &p2);
        friend float LineFit(const Point points[],int nPoint);
//静态成员函数可直接访问静态数据成员和私有成员
        static void getcount() { cout << "count = " <<count << endl;}
        ~Point( ) {--count;}
    private:
        float x;
        float y;
        static int count ;
};
float LineFit(const Point points[],int nPoint) {
    float avgx = 0,avgy = 0;

    float lxx = 0,lyy = 0,lxy = 0;
    for(int i=0; i<nPoint; ++i) {
        avgx+=points[i].x/nPoint;
        avgy+=points[i].y/nPoint;
    }
    for(int i=0; i<nPoint ;++i) {
        lxx+=(points[i].x-avgx)*(points[i].x-avgx);
        lyy+=(points[i].y-avgy)*(points[i].y-avgy);
        lxy+=(points[i].x-avgx)*(points[i].y-avgy);
    }
    cout<<"This line can be fitted by y=ax+b"<< endl;
    cout << "a=" <<lxy/lxx << endl;
    cout << "b=" <<avgy-lxy*avgx/lxx<< endl;
    return static_cast<float>(lxy/sqrt(lxx*lyy));
}

void distance(const Point &p1,const Point &p2) {
    float dis = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    cout << "distance = " << dis << endl;
}

int Point::count = 0;   //在类外定义和初始化

int main() {
    Point p1(1,2);
    {
    Point::getcount();//构造+1

    Point p2 = p1;  //拷贝委托+1
    Point::getcount();
     
    distance(p1,p2);
    }
    
    Point::getcount();//析构减1

    Point p[10]={Point(6,10),Point(14,20),Point(26,30),
   Point(33,40),Point(46,50),Point(54,60),Point(67,70),
   Point(75,80),Point(84,90),Point(100,100)};
    float r =  LineFit(p,10) ;
    cout<<"coefficient r = "<<r<< endl;
    return 0;
}

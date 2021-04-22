#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

class Point
{
    public:
        Point() :Point(0.0,0.0){ ++count; } 
        Point(const Point &p) : Point(p.x,p.y) { }
        Point(float _x,float _y) : x{_x},y{_y} { ++count; }
        void getx()const{ cout << "x = " << x << endl ;}
        void gety()const{ cout << "y = " << y << endl ;}

        friend void distance(const Point &p1,const Point &p2);
        static void getcount() { cout << "count = " <<count << endl;}
        ~Point( ) {--count;}
        static int count ;
    private:
        float x;
        float y;
};
void distance(const Point &p1,const Point &p2) {
    float dis = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    cout << "distance = " << dis << endl;
}

int Point::count = 0;   //在类外定义和初始化

class ArrayOfPoint {
private:
    Point *points;
    int size;
public:
    ArrayOfPoint(int size):size(size){
        points = new Point[size];
    }
    ArrayOfPoint(const ArrayOfPoint& array){
        points = new Point[size];
        size = array.size;
        for(int i = 0; i < size ;++i){
            points[i] = array.points[i];
        }
    }
    ~ArrayOfPoint( ){
        cout << "delete___" << endl;
        delete []points;
    }
    Point &element(int index) const {//const版本，这样常对象，常引用常指针都可以
        assert(index>=0 && index<size);
        return points[index];
    }

    Point &element(int index) {//普通版本
        return const_cast<Point &>(
            static_cast<const ArrayOfPoint*>(this)->element(index));
    }

};

int main()
{
    int size;
    cin >> size;
    ArrayOfPoint points(size);
    points.element(0).getx();
}
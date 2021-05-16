#include<iostream>
#include<cmath>
using namespace std;

class Vertex {
private:
    int x;
    int y;
public:
    Vertex() : x(0),y(0) { }
    Vertex(int x,int y) : x(x),y(y) { }
    int getx() const {return x;}
    int gety() const {return y;}
    friend class Rectangle;
};

class Rectangle {
private:
    Vertex V1;
    Vertex V2;
public:
    Rectangle() { }
    Rectangle(Vertex V1,Vertex V2) : V1(V1),V2(V2) { }
    void getS()const { cout << "the  rectangle's area = " << abs(V1.x-V2.x)*abs(V1.y-V2.y);}
};

int main()
{
    Vertex V1{1,2};
    Vertex V2{5,6};
    Rectangle R{V1,V2};
    R.getS();
}

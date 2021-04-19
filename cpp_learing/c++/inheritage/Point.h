#pragma
#include<iostream>
using namespace std;
class Point {
 private:
    float x,y;
 public:
    void initPoint(float x = 0,float y = 0) {
        this->x = x;
        this->y = y;
    }
    void move(float offx,float offy) {x+=offx,y+=offy;}
    float getX()const{return x;}
    float getY()const{return y;}
};
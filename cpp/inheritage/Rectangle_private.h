#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<iostream>
#include"Point.h"
class Rectangle:private Point {//公有保护变私有，原私有不可访问
 public:
    void initRectangle( float x=0,float y=0,float w=0,float h=0 ) {
        initPoint(x,y);
        this->w = w;
        this->h = h;
    }
    void move(float offx,float offy) {Point::move(offx,offy);}
    float getX()const{return Point::getX();}
    float getY()const{return Point::getY();}
    float getH()const{return h;}
    float getW()const{return w;}
 private:
    float w;
    float h;
};
#endif
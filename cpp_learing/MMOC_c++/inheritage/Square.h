#pragma once
#include<iostream>
class Square{
private:
    double side{1.0};
    static int numberOfObjects;
public:
    double getSide(){return side;}
    void setSide(double side){this->side=side;}
    Square(double side){
        this->side = side;
        numberOfObjects++;
    }
    Square():Square(1.0){}
    double getArea(){return side*side;}
    static int getNumberOfObjects(){return numberOfObjects;}
    int get(){return numberOfObjects;}
    Square (const Square &s):Square(s.side){
        
        std::cout<<"fuck attention"<<std::endl;
    }
    ~Square(){
        numberOfObjects--;
    }
};
#include<iostream>
#include<cmath>
#include"Rectangle_public.h"
//#include"Rectangle_private.h"
using namespace std;

int main()
{

    Rectangle rect;
    rect.initRectangle(2,3,20,10);
    rect.move(3,2);
    cout << "x = "<< rect.getX() << endl;
    cout << "y = "<< rect.getY() << endl;
    cout << "w = "<< rect.getW() << endl;
    cout << "h = "<< rect.getH() << endl;
    return 0;
}
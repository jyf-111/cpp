#include<iostream>

using std::cout;
using std::endl;

int main()
{
    
    Vec2D v1{ 3,5 } , v2{ 4,6 };
    cout<<"v1 = " << v1.toString() << endl;
    cout<<"v2 = " << v2.toString() << endl;

    Vec2D v3 = v1.add(v2);
    Vec2D v4 = v3.add(10.0);
    cout<<"v3 = " << v3.toString() << endl;
    cout<<"v4 = " << v4.toString() << endl;

    Vec2D v5 = v2..subtract(v1);
    double v6 = v2.dot(v1);
    Vec2D v7 = v3.multiply(2.1);
    cout<<"v2 - v1 = " << v5.toString() << endl;
    cout<<"v2 . v1 = " << v6 << endl;

    Vec2D v8 = v2.negative();
    cout << "-v2 = " << v8.toString() << endl;

    cout<<"++v8  =" << v8.toString() << endl;
    cout<<"++v2  =" << v2.toString() << endl;

    cout << "v1.x_ = " << v1.at(0) << endl;
    cout << "v1.y_ = " << v1.at(1) << endl;

    cout << "v1.magnitude = " << v1.magnitude() << endl;
    cout << "v1.direction = " << v1.direction() << endl;

    cout << "v1 compare v2 : " << v1.compareTo(v2) << endl;
}

#include<iostream>
using namespace std;

template<class T>
class Point {
private:
    T x;
    T y;
public:
    Point() : x(0), y(0) { }
    Point(T x,T y): Point() { this->x = x; this->y = y;}
    T getx() const { return x;}
    T gety() const { return y;}
};

template<class T>
class ArrayOfPoints {
private:
    Point<T>* point;
    size_t size;
public:
    ArrayOfPoints(size_t sz);

    ArrayOfPoints(const ArrayOfPoints<T>& a) {
            point = new Point<T> [a.size];
            for(int i=0 ; i<a.size ; ++i) {
                point[i] = a.point[i];
            }
            size = a.size;
    }

    ArrayOfPoints<T>& operator = (ArrayOfPoints<T>& a);

    void swap(ArrayOfPoints<T> &s) {
        std::swap(point,s.point);
        std::swap(size,s.size);
    }
    ~ArrayOfPoints () { delete [] point;}
};

namespace std {
    template<class T>
    inline void swap(ArrayOfPoints<T> &a, ArrayOfPoints<T> &b) {
        a.swap(b);
    }
}

template<class T>
ArrayOfPoints<T>& ArrayOfPoints<T>::operator = (ArrayOfPoints<T>& a) {
    Point<T>* p = new Point<T> [a.size];
            for(int i=0 ; i<a.size ; ++i) {
                p[i] = a.point[i];
            }
            delete [] point;
            point = p;
            size = a.size;
}


template<class T>
ArrayOfPoints<T>::ArrayOfPoints(size_t sz) {
    point = new Point<T> [sz];
    size = sz;
}

int main()
{
    ArrayOfPoints<int> a(5);
    ArrayOfPoints<int> b(10);
    
    a.swap(b);
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
}
#include<iostream>
using namespace std;

template<unsigned N>
struct Factorial {
    enum {VALUE = N*Factorial<N-1>::VALUE};
};

template<>
struct Factorial<0> {
    enum {VALUE = 1};
};

template<unsigned N>
inline double power(double v) {
    return v*power<N-1>(v);
}

template<>
inline double power<1>(double v) {
    return v;
}

template<unsigned N>
struct Power {
    template<class T>
    static T value(T x) {
        return x*Power<N-1>::value(x);
    }
};

template<>
struct Power<1> {
    template<class T>
    static T value(T x) {
        return x;
    }
};

int main()
{
    cout << Factorial<8>::VALUE << endl;
    cout << power<4>(5) << endl;

    cout << Power<6>::value(4);
}   
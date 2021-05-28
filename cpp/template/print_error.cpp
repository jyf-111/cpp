#include<iostream>
using namespace std;

template<class T>
void print_error(const T & t) {
    cout << t << endl;
}

template<class T, class...Typeargs>
void print_error(const T & t, const Typeargs&...args) {
    cerr << t << endl;
    print_error(args...);
}



int main()
{
    print_error("111","222","333");
}
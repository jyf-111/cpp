#include<iostream>

using namespace std;
template <typename T, typename S>
auto add(T x, S y){
    return x+y;
}
template <class Q>
Q minu(Q x,Q y){
    return x-y;
}
int main()
{
    auto x = add (1.1, 5);
    auto y = add (1, 2.1);
    auto z = minu (3,5);
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}
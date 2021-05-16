#include<iostream>
using namespace std;

class Counter
{
private:
    int cnt;
public:
    Counter() :cnt(0) {}
    Counter(int n): cnt(n) { }
    Counter operator+(Counter &b) { 
        return static_cast<Counter>(cnt+b.cnt);
    }
    void show() const {cout << cnt << endl;}
};

int main()
{
    Counter a(100);
    Counter b(50);
    Counter c = a+b;
    c.show();
}
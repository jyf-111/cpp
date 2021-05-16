#include<iostream>
using namespace std;

class CPU {
private:
enum Type{ single,two,multiply};
    int TimeFrequency:32;
    int bit : 8;
    Type core :2;
    bool multithread;
public:
    CPU() : TimeFrequency(0),bit(16),core(single),multithread(true) { }
};

int main()
{
    cout << sizeof(CPU) << endl;
}
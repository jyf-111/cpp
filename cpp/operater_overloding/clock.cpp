#include<iostream>
using namespace std;

class Clock
{
private:
    int hour,minute,second;
public:
    Clock(int hour = 0,int minute = 0,int second = 0);
    void show()const;
    Clock& operator++();//«∞÷√
    Clock operator++(int);//∫Û÷√
    ~Clock() {}
};

void Clock::show()const {
    cout << hour << ":" << minute << ":" << second << endl;
}

Clock::Clock(int hour /*= 0*/,int minute /*= 0*/,int second /*= 0*/) {
    if(hour>=0&&hour <24&&minute>=0&&minute<60&&second>=0&&second<60){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }else{
        cout << "Time error" << endl;
    }
}

Clock& Clock::operator++() {
    second++;
    if(second>=60){
        second-=60;
        minute++;
        if(minute>=60){
            minute-=60;
            hour = (hour+1)%24;
        }
    }
    return *this;
}

Clock Clock::operator++(int) {
    Clock old = *this;
    ++(*this);
    return old;
}

int main()
{
    Clock myClock(23,59,59);
    myClock.show();

    (++myClock).show();
    myClock.show();
    
    (myClock++).show();
    myClock.show();
}
#include<iostream>
using std::cout;
using std::endl;

//类的定义
class Clock
{
    public:
        //Clock(): hour(0) , minute(0) , second(0) { }      //默认构造函数

        Clock():Clock(0,0,0) { } //委托构造函数(受委托的函数初始值列表和函数体依次执行)

        Clock(const Clock &c);//拷贝构造函数（如果没有则自动生成）

        Clock(int _hour,int _minute,int _second);             

        void setTime(int _hour = 0,int _minute = 0,int _second = 0);//默认形参写在类的定义中

        void showTime();

        ~ Clock() {}
    private:
        int hour{0};
        int minute{0};
        int second = 0;     //类内初始值必须等号或者花括号(没有类内初始值的成员被默认初始化)
        static int count;
        constexpr static int a = 0;//常量静态成员在类内初始化
};

 int Clock::count = 0;//静态成员在类外声明和定义

Clock::Clock(const Clock &c)
{
    hour = c.hour+100000;
    minute = c.minute;
    second = c.second;
    cout << "copy" << endl;
}

Clock::Clock(int _hour,int _minute,int _second) : hour(_hour) , minute(_minute) , second(_second) { }

inline void Clock::setTime(int _hour,int _minute,int _second)
{
    hour = _hour;
    minute = _minute;
    second = _second;
}

inline void Clock::showTime()//inline在定义时候加，类内声明不加
{
    cout << "hour = " << hour <<" minute = " << minute 
    <<" second = " << second << endl;
    
}


int main()
{
    
    Clock myClock(1,2,3);
    Clock c2( myClock );
    myClock.showTime();
    c2.showTime();

    myClock.setTime(10,12,20);
    myClock.showTime();
    
    c2.showTime();
    

    return 0;
}
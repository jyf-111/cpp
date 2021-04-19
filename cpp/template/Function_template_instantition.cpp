#include<iostream>
#include<string>
template <typename T>
T max(T x,T y){
    return (x > y ? x : y);
}
template  int max <> (int,int);//显式实例化
int main()
{
    std::cout <<max(1,2) << std::endl;
    std::cout <<max(1.1,2.5) << std::endl;
    std::cout <<max('A','D') << std::endl;
    std::cout <<max("123","DEF") << std::endl;

}
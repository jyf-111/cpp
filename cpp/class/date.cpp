#include<iostream>
#include"Data.h"
int Employee::num=0;
int main()
{
    Employee e1;
    Employee* e2 = new Employee{"John",Gender::male,Data(1990,3,2)};
    std::cout<<e2->getBirthday().toString()<<std::endl;
}
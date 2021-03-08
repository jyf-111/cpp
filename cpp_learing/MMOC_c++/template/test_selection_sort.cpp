#include<iostream>
#include<array>
#include"selection_sort.h"

int main()
{
    double x[] {3.0 ,2.0 ,8.0 ,4.0 ,9.0 ,1.0 ,5.0 ,7.0};
    std::array <double,8> y {3.0 ,2.0 ,8.0 ,4.0 ,9.0 ,1.0 ,5.0 ,6.0};
    for(auto i: x){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    selectionsort (x,sizeof(x)/sizeof(x[0]));
    for(auto i : x){
        std::cout << i << " ";
    }
    std::cout<<std::endl;
     for(auto i: y){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    selectionsort (y);
    for(auto i : y){
        std::cout << i << " ";
    }
}
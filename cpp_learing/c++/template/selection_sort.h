#pragma
#include<iostream>
#include<array>
//template<typename T>
void selectionsort(double list[] , const std::size_t size){
    for(int i = 0; i < size - 1 ; i++){
        double min = list [i];
        int index = i;
        for(int j = i + 1 ; j < size ; j++){
            if(min > list[ j ]){
                min=list[j];
                index = j ;
            } 
        }
        if(index != i){
            list[ index ] = list[i];
            list[ i ] = min ;
        }
    }
}


template <typename T,size_t N>
void selectionsort(std::array<T,N>&list ){
    constexpr int size = N;
    for(int i = 0; i < size - 1 ; i++){
        T min = list [i];
        int index = i;
        for(int j = i + 1 ; j < size ; j++){
            if(min > list[ j ]){
                min=list[j];
                index = j ;
            } 
        }
        if(index != i){
            list[ index ] = list[i];
            list[ i ] = min ;
        }
    }
}
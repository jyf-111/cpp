#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>
template<class T>
class Array {
private:
    T* list;
    int size;
public:
    Array(int sz = 50);
    Array(const Array<T> &a);
    ~Array();
    Array<T>& operator=(const Array<T>&rhs);
    T& operator[](int i);
    const T& operator[](int i)const;
    operator T*();
    operator const T *()const;
    int getSize()const;
    void resize(int sz);
    void swap(Array &a);
};

template<class T>
Array<T>::Array(int sz) {
    assert(sz>=0);
    size = sz;
    list = new T[size];
}

template<class T>
Array<T>::~Array() {
    delete []list;
}

template<class T>
Array<T>::Array(const Array<T>& a){
    size = a.size;
    list = new T[size];
    for(int i = 0 ; i < size ; ++i){
        list[i] = a.list[i];
    }
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if(&rhs != this){
        if(rhs.size != size){
            delete []list;
            size = rhs.size;
            list = new T[size];
        }
        for(int i = 0 ; i < size ; ++i) {
            list[i] = rhs.list[i];
        }
    }
    return *this;
}

template<class T>
T& Array<T>::operator[](int n ){
    assert(n>=0&&n<=size);
    return list[n];
}

template<class T>
const T& Array<T>::operator[](int n )const{
    assert(n>=0&&n<=size);
    return list[n];
}

template<class T>
Array<T>::operator T *(){
    return list;
}

template<class T>
Array<T>::operator const T *()const{
    return list;
}

template<class T>
int Array<T>::getSize()const {
    return size;
}

template<class T>
void Array<T>::resize(int sz) {
    assert(sz>=0);
    if(sz == size)return ;
    T* newlist = new T[sz];
    int n = sz < size ? sz : size;
    for(int i = 0 ; i < n ; ++i){
        newlist[i] = list[i];
    }
    delete []list;
    list = newlist;
    size = sz;
}

template<class T>
void Array<T>::swap(Array<T> &a) {
    std::swap(list,a.list);
    std::swap(size,a.size);
}
#endif
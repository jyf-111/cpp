#include<iostream>
#include<cassert>
using namespace std;

template<typename T> 
class Array {
private:
    T* list;
    int size;
public:
    Array(int sz = 50);
    Array(const Array<T> &a);
    ~Array();
    Array<T>& operator= (const Array<T> &rhs);
    T& operator[] (int i);
    const T& operator[] (int i) const;
    operator T* ();
    operator const T*() const;
    int getSize() const ;
    void resize(int sz);
    void getaverage()const {
        T sum = 0 ;
        for(int i=0 ;i<size ;++i) {
            sum+=list[i];
        }
        cout << sum/size;
    }
};

template<typename T>

Array<T>::Array(int sz/*=50*/) {
    assert(sz>=0);
    size = sz;
    list = new T [size];
}

template<typename T>
Array<T>::Array(const Array<T> &a) {
    size = a.size();
    list = new T [size];
    for(int i=0 ; i<size ; ++i) {
        list[i] = a.list[i];
    }
}

template<typename T>
Array<T>::~Array() {
    delete [] list;
}

template<typename T>
Array<T>& Array<T>::operator= (const Array<T> &rhs) {
    if(&rhs!=this){
        if(rhs.size!=size){
            delete []list;
            list = new T [size];
        }
        for(int i=0 ;i<size ;i++) {
            list[i] = rhs.list[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[] (int n) {
    assert(n>=0&&n<size);
    return list[n];
}

template<typename T>
const T& Array<T>::operator[] (int n) const {
    assert(n>=0&&n<size);
    return list[n];
}

template<typename T>
Array<T>::operator T *() {
    return list;
}

template<typename T>
Array<T>::operator const T *() const {
    return list;
} 

template<typename T>
int Array<T>::getSize() const {
    return size;
}

template<class T>
void Array<T>::resize(int sz) {
    assert(sz>=0);
    if(sz==size)return;
    T* newlist = new T [sz];
    for(int i=0 ; i<sz ;++i){
        newlist[i] = list[i];
    }
    delete []list;
    list = newlist;
    size = sz;
}

int main()
{
    int n;
    cin >> n;
    Array<float> grade(n);
    /*while(n--){
        float num;
        cin >> num;
        grade[n] = num;
    }
    grade.getaverage();*/
    cout << grade << endl;
}
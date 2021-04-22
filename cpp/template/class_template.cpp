#include<iostream>
#include<cstdlib>
using namespace std;

struct Student {
    int id;
    float gpa;
};

template<class T>
class Store
{
private:
    T item;
    bool haveValue;
public:
    Store();
    T &getElem();
    void putElem(const T &x);
    ~Store() {}
};
template<class T>
Store<T>::Store():haveValue(false) { }

template<class T>
T &Store<T>::getElem() {
    if(!haveValue){
        cout << "No item present!" << endl;
        exit(1);
    }
    return item;
}

template<class T>
void Store<T>::putElem(const T &x){
    haveValue = true;
    item = x;
}

int main()
{
    Store<int>s1,s2;
    s1.putElem(3);
    s2.putElem(-7);
    cout << s1.getElem() << "###"<<s2.getElem() << endl;

    Student g={1000,23};
    Store<Student> s3;
    s3.putElem(g);
    cout << s3.getElem().id << "///" << s3.getElem().gpa << endl;

    Store<double> s4;
    cout << s4.getElem() << endl;
}
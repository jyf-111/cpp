#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

template<class T>
class IncrementIterator : public iterator<random_access_iterator_tag, T , ptrdiff_t , const T * , const T &> {
private:
    T value;
public:
    typedef IncrementIterator<T>Self;
    IncrementIterator(const T& value = T()) :value(value) { }
    bool operator == (const Self& rhs) const {return value==rhs.value;}
    bool operator != (const Self& rhs) const {return value!=rhs.value;}
    Self& operator++ () { value++; return *this;}
    Self operator++(int) {
        Self tmp = *this;
        ++(*this);
        return tmp;
    }
    const T & operator * () const {return value;}
    const T * operator -> () const {return &value;}
    Self& operator += (int n) const {value+=n; return *this;}
    Self& operator [] (int n) const {value+=n; return *this;}
};

int main()
{
    copy(IncrementIterator<int>(),IncrementIterator<int>(10),ostream_iterator<int>(cout," "));
    cout << endl;
    int s[] = { 5,8,7,4,2,6,10,3};
    transform(s,s+sizeof(s)/sizeof(int),IncrementIterator<int>(),ostream_iterator<int>(cout," "),plus<int>());
}
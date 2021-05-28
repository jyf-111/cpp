#include<iostream>
using namespace std;

template<unsigned M,unsigned N>
struct Permutation {
    enum { value = Permutation<M-1,N-1>::value + Permutation<M,N-1>::value };
};

template<unsigned N>
struct Permutation<1,N> {
    enum { value = N};
};

template<unsigned N>
struct Permutation<N,N> {
    enum { value = 1};
};

template<unsigned N>
struct Permutation<0,N> {
    enum { value = 1};
};

int main()
{
    cout << Permutation<1,5>::value << endl;
}
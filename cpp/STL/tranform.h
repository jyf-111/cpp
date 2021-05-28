#include<iostream>

using namespace std;

template<class InputIt,class OutputIt,class Unary_Function>
OutputIt transform(InputIt first,InputIt last,OutputIt result,Unary_Function op) {
    for(;first!=last ; ++first ,++result) {
        *result = op(*first);
    }
    return result;
}

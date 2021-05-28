#include<iostream>
#include"Stack_partial_special.h"
using namespace std;
//偏特化目标函数总会生成，所以放在源文件中
template<>
class Stack<bool,32> {
private:
    unsigned list;
    int top;
public:
    Stack();
    void push(const bool &item);
    bool pop();
    void clear();
    const bool& peek()const;
    bool isEmpty()const;
    bool isFull()const;
    ~Stack() {}
};
//全特化是对类，成员不用template<>
void Stack<bool,32>::push(const bool &item) {
    assert(!isFull());
    ++top;
    list = (list << 1) | (item ? 1 : 0);
}

bool Stack<bool,32>::pop() {
    assert(!isEmpty());
    bool result = (list & 1)==1;
    list >>= 1;
    --top;
    return result;
}
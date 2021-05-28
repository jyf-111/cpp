#ifndef STACK_H
#define STACK_H
#include<cassert>

template<class T,int SIZE = 50>
class Stack
{
private:
    T list[SIZE];
    int top;
public:
    Stack();
    void push(const T &item);
    T pop();
    void clear();
    const T& peek()const;
    bool isEmpty()const;
    bool isFull()const;
    ~Stack() {}
};

template<class T,int SIZE>
Stack<T,SIZE>::Stack() :top=-1 { }

template<class T,int SIZE>
void Stack<T,SIZE>::push(const T &item) {
    assert(!isFull());
    list[++top] = item;
}

template<class T,int SIZE>
T Stack<T,SIZE>::pop(){
    assert(!isEmpty());
    return list[top--];
}

template<class T,int SIZE>
const T& Stack<T,SIZE>::peek()const{
    assert(!isEmpty());
    return list[top];
}

template<class T,int SIZE>
bool Stack<T,SIZE>::isEmpty()const {
    return top == -1;
}

template<class T,int SIZE>
bool Stack<T,SIZE>::isFull()const {
    return top == SIZE-1;
}

template<class T,int SIZE>
void Stack<T,SIZE>::clear() {
    top == -1;
}


//偏特化
template<int SIZE>
class Stack<bool,SIZE> {
private:
    enum{
        UNIT_BITS=sizeof(unsigned)*8,
        ARRAY_SIZE=(SIZE-1)/UNIT_BITS+1
    };
    unsigned list[ARRAY_SIZE];
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
template<int SIZE>
void Stack<bool,SIZE>::push(const bool &item) {
    assert(!isFull());
    ++top;
    int index = top/UNIT_BITS;
    list[index] = list[index]<<1 | (item?1:0);
}

template<int SIZE>
bool Stack<bool,SIZE>::pop() {
    assert(!isEmpty());
    int index = top--/UNIT_BITS;
    bool result = (list[index] & 1)==1;
    list >>= 1;
    return result;
}

#endif
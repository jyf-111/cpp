#ifndef QUEUE_H
#define QUEUE_H

template<class T,int SIZE = 50>
class Queue
{
private:
    int front,rear,count;
    T list[SIZE];
public:
    Queue();
    void insert(const T &item);
    T remove();
    void clear();
    const T& getFront()const;

    int getLenth()const;
    bool isEmpty()const;
    bool isFull()const;
    ~Queue() {}
};

template<class T,int SZIE>
Queue<T,SZIE>::Queue():front(0),rear(0),count(0) { }

template<class T,int SIZE>
void Queue<T,SIZE>::insert(const T &item){
    assert(count!=SIZE);
    count++;
    list[rear] = item;
    rear = (rear+1)%SIZE;
}
template<class T,int SIZE>
T Queue<T,SIZE>::remove(){
    assert(count!=0);
    int temp = front;
    count--;
    front = (front+1)%SIZE;
    return list[temp];
}

template<class T,int SIZE>
const T& Queue<T,SIZE>::getFront()const{
    return list[front];
}

template<class T,int SIZE>
int Queue<T,SIZE>::getLenth()const{
    return count;
}

template<class T,int SIZE>
bool Queue<T,SIZE>::isEmpty()const{
    return count == 0;
}

template<class T,int SIZE>
bool Queue<T,SIZE>::isFull()const{
    return count==SIZE;
}

template<class T,int SIZE>
void Queue<T,SIZE>::clear(){
    front = 0;
    rear = 0;
    count = 0;
}

#endif
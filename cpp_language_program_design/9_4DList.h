#ifndef DLIST
#define DLIST
#include<iostream>
#include<cassert>
using namespace std;


template<class T>
class DNode {
public:
    typedef class DNode<T>* ptrToDNode;
    ptrToDNode pre;
    ptrToDNode next;
public:
    T data;
    DNode() : pre(nullptr),next(nullptr),data(0) { }
    DNode(T data,ptrToDNode pre,ptrToDNode next);
    ~DNode() { delete pre,next; }
};

template<class T>
DNode<T>::DNode(T data,ptrToDNode pre,ptrToDNode next):DNode() {
    this->data = data;
    this->pre = pre;
    this->next = next;
}

template<class T>
class DoubleLink {
private:
    int count;
    DNode<T> *phead;
    DNode<T> * get_node(int index);
public:
    DoubleLink();
    ~DoubleLink();

    int size();
    bool is_empty();
    T get(int index);
    T get_first();
    T get_last();

    int insert(int index,T t);
    int insert_first(T t);
    int append_last(T t);

    int del(int index);
    int delete_first();
    int delete_last();
    void printList();
    int getCount() const {
        return count;
    }
};

template<class T>
DoubleLink<T>::DoubleLink() : count(0) {
    phead = new DNode<T>;
    phead->pre = phead->next = phead;
}

template<class T>
DoubleLink<T>::~DoubleLink() {
    DNode<T>* ptemp;
    DNode<T>* pnode = phead->next;
    while(pnode != phead){
        ptemp = pnode;
        pnode = pnode->next;
        delete ptemp;
    }
    delete phead;
    phead = nullptr;
}

template<class T>
int DoubleLink<T>::size() {
    return count;
}

template<class T>
bool DoubleLink<T>::is_empty() {
    return count == 0;
}
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index) {
    assert(index>=0 && index<count);
    if(index <= count/2){
        int i=0; 
        DNode<T>* pindex = phead->next;
        while(i++ < index){
            pindex = pindex->next;
        }
        return pindex;
    }
    int j=0 ;
    int rindex = count - index - 1 ;
    DNode<T>* pindex = phead->pre;
    while(j++ < rindex) {
        pindex = pindex->pre;
    }
    return pindex;
}

template<class T>
T DoubleLink<T>::get(int index){
    return get_node(index)->data;
}

template<class T>
T DoubleLink<T>::get_first() {
    return get_node(0)->data;
}

template<class T>
T DoubleLink<T>::get_last() {
    return get_node(count-1)->data;
}

template<class T>
int DoubleLink<T>::insert(int index,T t) {
    if(index == 0) {
        return insert_first(t);
    }
    DNode<T>* pindex = get_node(index);
    DNode<T>* pnode = new DNode<T>(t,pindex->pre,pindex);
    pindex->pre->next = pnode;
    pnode->next->pre = pnode;
    count++;

    return 0;
}

template<class T>
int DoubleLink<T>::insert_first(T t) {
    DNode<T>* pnode  = new DNode<T>(t, phead, phead->next);
	phead->next->pre = pnode;
	phead->next = pnode;
	count++;
 
	return 0;
}

template<class T>
int DoubleLink<T>::append_last(T t) 
{
	DNode<T>* pnode = new DNode<T>(t, phead->pre, phead);
	phead->pre->next = pnode;
	phead->pre = pnode;
	count++;
 
	return 0;
}
 
template<class T>
int DoubleLink<T>::del(int index) {
    DNode<T>* pindex = get_node(index);
    pindex->next->pre = pindex->pre;
    pindex->pre->next = pindex->next;
    delete pindex;
    count--;
    return 0;
}

template<class T>
int DoubleLink<T>::delete_first(){
    return del(0);
}

template<class T>
int DoubleLink<T>::delete_last() {
    return del(count-1);
}

template<class T>
void DoubleLink<T>::printList() {
    for(int i=0;i<count;i++){
        cout << get_node(i)->data << ' ';
    }
    cout << endl;
}
#endif


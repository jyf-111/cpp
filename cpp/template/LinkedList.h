#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"

template<class T>
class LinkedList {
private;
    Node<T>* front,*rear;//表头和表尾指针
    Node<T>*prevPtr,*currPtr;//记录当前遍历位置的指针，由插入和删除操作更新
    int size;//表中元素个数
    int position;//当前元素在表中的序号。由函数reset使用

    Node<T>*newNode(const T &item,Node<T>*ptrNext = nullptr);
    void freeNode(Node<T>& p);
    void copy(const LinkedList<T>& L);
public:
    LinkedList();
    LinkedList(const LinkedList<T> &L);
    ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T> &L);

    int getSize()const;
    bool isEmpty()const;
    void reset(int pos = 0);//初始化游标位置
    void next;
    bool endOfList()const;//游标是否到队尾
    int currentPosition()const;//返回游标当前位置

    void insertFront(const T &item);
    void insertRear(const T &item);
    void insertAt(const T &item);//在当前节点之前插入节点
    void insertAfter(const T &item);//在当前节点之后插入节点

    T deleteFront();
    void deleteCurrent();
    T& data();//返回对当前节点成员数据的引用
    const T& data()const;//返回对当前节点成员数据的常引用
    void clear();//清空链表
};

#endif
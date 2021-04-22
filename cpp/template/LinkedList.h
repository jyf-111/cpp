#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"

template<class T>
class LinkedList {
private;
    Node<T>* front,*rear;//��ͷ�ͱ�βָ��
    Node<T>*prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
    int size;//����Ԫ�ظ���
    int position;//��ǰԪ���ڱ��е���š��ɺ���resetʹ��

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
    void reset(int pos = 0);//��ʼ���α�λ��
    void next;
    bool endOfList()const;//�α��Ƿ񵽶�β
    int currentPosition()const;//�����α굱ǰλ��

    void insertFront(const T &item);
    void insertRear(const T &item);
    void insertAt(const T &item);//�ڵ�ǰ�ڵ�֮ǰ����ڵ�
    void insertAfter(const T &item);//�ڵ�ǰ�ڵ�֮�����ڵ�

    T deleteFront();
    void deleteCurrent();
    T& data();//���ضԵ�ǰ�ڵ��Ա���ݵ�����
    const T& data()const;//���ضԵ�ǰ�ڵ��Ա���ݵĳ�����
    void clear();//�������
};

#endif
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct HNode *Heap;
typedef Heap MaxHeap,MinHeap;

struct HNode {
    ElementType *Data;
    int Size;
    int Capacity;
};

#define MAXDATA 10000;

MaxHeap CreateHeap( int Maxsize) {
    MaxHeap H = new struct HNode;
    H->Data = new ElementType[Maxsize+1];
    H->Capacity = Maxsize;
    H->Size = 0;
    H->Data[0] = Maxsize;//из╠Ь
    return H;
}

bool IsFull(MaxHeap H){
    return H->Size == H->Capacity;
}

bool IsEmpty(MaxHeap H){
    return H->Size == 0;
}

bool Insert(MaxHeap H,ElementType X) {
    int i;
    if(IsFull(H)) {
        cout << "the heap is full" << endl;
        return false;
    }
    i = ++H->Size;
    for(;H->Data[i/2]<X;i/=2){
        H->Data[i]=  H->Data[i/2];
    }
    H->Data[i]= X;
    cout << "yes" << endl; 
    return true;
}

#define ERROR -1

ElementType DeleteMax(MaxHeap H) {
    int Parent , Child;
    ElementType MaxItem,X;

    if(IsEmpty(H)){
        cout << " the heap is empty" << endl;
        return ERROR;
    }
        MaxItem = H->Data[1];
        X = H->Data[H->Size--];
        for(Parent = 1;Parent*2<=H->Size;Parent = Child) {
            Child = Parent * 2;
            if((Child!=H->Size)&&H->Data[Child]<H->Data[Child+1]){
                Child++;
            }
            if(X>=H->Data[Child])break;
            else H->Data[Parent] = H->Data[Child];
        }
        H->Data[Parent] = X;
        return MaxItem;
}


int main()
{
    MaxHeap H;
    H = CreateHeap(3);
    for(int i = 0 ; i<3; ++i){
        Insert(H,i);
    }
}
#include<iostream>
using namespace std;
typedef struct HNode* Heap;
using ElementType = int;
#define MAXDATA 100000
struct HNode {
    ElementType *data;
    int Size;
    int Capacity;
};

Heap CreateHeap(int SIZE){
    Heap H;
    H = new struct HNode;
    H->data = new ElementType[SIZE+1];
    H->Capacity = SIZE;
    H->Size = 0;
    H->data[0] = MAXDATA;
    return H;
}

void InsertHeap(Heap H,ElementType X){
    int i = ++H->Size;
    for(; X > H->data[i/2] ; i/=2){
        H->data[i] = H->data[i/2];
    }
    H->data[i] = X;
}

ElementType Delete(Heap H) {
    int Parent ,Child;
    ElementType MaxItem ,X;
    MaxItem = H->data[1];
    X = H->data[H->Size--];
    for(Parent = 1 ; Parent*2 <=H->Size; Parent = Child){
        Child = Parent*2;
        if(Parent*2!=H->Size&&H->data[Child]<H->data[Child+1]){
            Child++;
        }
        if(X>=H->data[Child])break;
        else H->data[Parent] = H->data[Child];
    }
    H->data[Parent] = X;
    return MaxItem;
}

void percDown(Heap H,int p) {
    int Parent ,Child;
    ElementType MaxItem ,X;
    MaxItem = H->data[p];
    X = H->data[H->Size--];
    for(Parent = p ; Parent*2 <=H->Size; Parent = Child){
        Child = Parent*2;
        if(Parent*2!=H->Size&&H->data[Child]<H->data[Child+1]){
            Child++;
        }
        if(X>=H->data[Child])break;
        else H->data[Parent] = H->data[Child];
    }
    H->data[Parent] = X;
}

void buildHeap(Heap H){
    for(int i = H->Size/2 ; i>0 ; --i){
        percDown(H,i);
    }
}

int main()
{
    Heap H;
    H = CreateHeap(10);
    for(int i = 0 ;i <10 ; ++i){
        InsertHeap(H,i);
    }
    for(int j = 0 ;j <10 ;j++){
    Delete(H);
    for(auto i =1; i<=H->Size ;++i){
        cout << H->data[i] << ' ';
    }
    cout << endl;
    }
}
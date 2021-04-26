/*双端队列*/
#include<iostream>
#include<cstdlib>
#define Maxsize 10
using namespace std;
using ElementType = int;
using DStack = struct SNode *;

struct SNode
{
     ElementType data[Maxsize];
     int top[2];
};

DStack InitDStack()
{
    DStack stack = (DStack)malloc(sizeof(struct SNode));
    stack->top[0] = -1;
    stack->top[1] = Maxsize;
    return stack;
}

int Pop(DStack stack,int i)
{
    int num;
    switch(i)
    {
        
        case 0 :
            if(stack->top[0]==-1){
                cout << "stack No 0 is empty,pop fail" << endl;  
            }else{
                num = stack->data[(stack->top[0])--];
            }
            break;
        case 1 :
            if(stack->top[1]==Maxsize){
                cout << "stack No 1 is empty,pop fail" << endl; 
            }else{
                num = stack->data[(stack->top[1])++];
            }
            break;
        default:
            
            break;
    }
    return num;
}

void Push(DStack stack,int i,ElementType X)
{
    switch(i)
    {
        case 0:
            if(stack->top[0]+1 == stack->top[1]){
                cout << "the doubel side stack is full,push fail" << endl;
            }else{
                stack->data[++(stack->top[0])] = X;
            }
            break;
        case 1:
            if(stack->top[0] == stack->top[1]-1){
                cout << "the doubel side stack is full,push fail" << endl;
            }else{
                stack->data[--(stack->top[1])] = X;
            }
            break;
        default:
            break;
    }
}
int main()
{
    DStack stack;
    stack = InitDStack();
    
    for(auto i =0;i < Maxsize/2;++i){
        Push(stack,0,i);
        Push(stack,1,Maxsize-i);
    }
    
    for(auto i =0;i < Maxsize/2;++i){
        cout<<Pop(stack,0)<<" ";
    }
    cout <<endl;
    
    for(auto i =0;i < Maxsize/2;++i){
        cout<<Pop(stack,1) <<" "; 
    }
    return 0;
}
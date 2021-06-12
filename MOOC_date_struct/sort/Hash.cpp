/*
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10
​4
​​ ) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/

#include<iostream>
#include<cmath>
using namespace std;

typedef struct HashTbl *HashTable;
#define Empty 0
#define Legitimate 1
typedef unsigned int ElementType;

struct Cell {
    ElementType Element;
    int Info;
};

struct HashTbl {
    int TableSize;
    Cell *TheCells;
}H;
typedef int Position;
#define MAXTABLESIZE 1000000
int NextPrime(int N) {
    int i, p =(N%2) ? N+2 : N+1;
    while(p<MAXTABLESIZE) {
        for(i = (int)sqrt(p) ; i>2 ; --i) {
            if(!(p%i)) break;
        }
        if(i == 2)break;
        else p+=2;
    }
    if(N<2) p = 2;
    if(N>2 && N<=3) p = 3;
    return p;
}

HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    
    H = (HashTable)malloc(sizeof(struct HashTbl));
    
    H->TableSize = NextPrime(TableSize);
    H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
    
    for(i=0 ; i< H->TableSize ; ++i ) {
        H->TheCells[i].Info = Empty;
    }
    return H;
}

int Hash(int Key,int P) {
    return Key % P;
}

Position Find(ElementType Key , HashTable H) { 
    Position CurrentPos,NewPos;
    int CNum = 0;
    NewPos = CurrentPos = Hash(Key,H->TableSize);
    while(H->TheCells[NewPos].Info != Empty && H->TheCells[NewPos].Element != Key) {
        NewPos = CurrentPos + ( CNum + 1) * ( CNum + 1);
        while(NewPos >= H->TableSize){
            NewPos -=H->TableSize;
        }
        CNum++;
        if(CNum == H->TableSize/2) return -1;
    }
    return NewPos;
}

void Insert(ElementType Key ,HashTable H,int spaceFlag) {
    Position Pos;
    Pos = Find(Key,H);
    if(H->TheCells[Pos].Info != Legitimate) {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
        if(spaceFlag ==0) {
            if(Pos != -1){
                cout << Pos << " ";
            }else{
                cout << '-' << " ";
            }
        }else{
            if(Pos != -1){
                cout << Pos;
            }else{
                cout << '-';
            }
        }
    }
}

int main()
{
    int M,N;
    cin >> M >> N;
    HashTable myTable = InitializeTable(M);
    int key;
    for(int i=0 ; i<N-1 ; i++ ) {
        cin >> key;
        Insert(key,myTable,0);;
    }
    cin >> key;
    Insert(key,myTable,1);
    return 0;
}
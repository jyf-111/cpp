/*
实现QQ新帐户申请和老帐户登陆的简化版功能。最大挑战是：据说现在的QQ号码已经有10位数了。

输入格式:
输入首先给出一个正整数N（≤10
​5
​​ ），随后给出N行指令。每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。其中命令符为“N”（代表New）时表示要新申请一个QQ号，后面是新帐户的号码和密码；命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。QQ号码为一个不超过10位、但大于1000（据说QQ老总的号码是1001）的整数。密码为不小于6位、不超过16位、且不包含空格的字符串。

输出格式:
针对每条指令，给出相应的信息：

1）若新申请帐户成功，则输出“New: OK”；
2）若新申请的号码已经存在，则输出“ERROR: Exist”；
3）若老帐户登陆成功，则输出“Login: OK”；
4）若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；
5）若老帐户密码错误，则输出“ERROR: Wrong PW”。

输入样例:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com
输出样例:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK
*/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define KEYLENGTH 10
#define MAXD 5
typedef char ElementType[KEYLENGTH + 1];
typedef char Passwd[20];
typedef int Index;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    Passwd Password;
    PtrToLNode Next;
    int count;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef struct TblNode *HashTable;
struct TblNode {
    int TableSize;
    List Heads;
};
#define MAXTABLESIZE 1000000
int NextPrime(int N) {
    int i,p = (N%2) ? N+2 : N+1;
    while( p <= MAXTABLESIZE) {
        for(i = (int)sqrt(p);i>2;i--) {
            if(!(p%i)) break;
        }
        if( i==2 )break;
        else p+=2;
    }
    return p;
}

int Hash(int Key,int P) {
    return Key % P;
}

HashTable CreateTable(int TableSize) {
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = TableSize;
    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
    for( i=0 ; i<H->TableSize ; i++) {
        H->Heads[i].Data[0]='\0';
        H->Heads[i].Next=NULL;
        H->Heads[i].count = 0;
    }
    return H;
}
Position Find(HashTable H,ElementType Key) {
    Position P;
    Index Pos;

    if(strlen(Key)>5) {
        Pos = Hash(atoi(Key+strlen(Key)-5),H->TableSize);
    }else{
        Pos = Hash(atoi(Key),H->TableSize);
    }

    P = H->Heads[Pos].Next;
    while(P && strcmp(P->Data,Key)) {
        P = P->Next;
    }
    return P;
}

bool Insert(HashTable H,ElementType Key,int flag,char *passwd2) {
    Position P,NewCell;
    Index Pos;
    P = Find(H,Key);
    //cout << "%" << flag << endl;
    if(!P) {
        if(flag==1){
            cout << "ERROR: Not Exist" << endl;
            return false;
        }else{
            NewCell = (Position)malloc(sizeof(struct LNode));
            strcpy(NewCell->Data,Key);
            strcpy(NewCell->Password,passwd2);
            if (strlen(Key)>5)
				Pos = Hash(atoi(Key + strlen(Key) - 5), H->TableSize);
			else {
				Pos = Hash(atoi(Key), H->TableSize);
			}
            NewCell->Next = H->Heads[Pos].Next;
            H->Heads[Pos].Next = NewCell;
            cout << "New: OK" << endl;
            return true;

        }
    }else {
        if(flag==0) {
            cout << "ERROR: Exist" << endl;
            return false;
        }else {
            if(strcmp(P->Password,passwd2)==0) {
                cout << "Login: OK" << endl;
            }else {
                cout << "ERROR: Wrong PW" << endl;
            }
        }
    }
    return true;
}

int main()
{
    int N,i;
    HashTable H;
    cin >> N;

    H = CreateTable(100000);
    
    char op;
    ElementType currentQQ;
    Passwd currentPasswd;

    for(i=0 ; i<N ;i++) {
        cin >> op >> currentQQ >> currentPasswd;
        if(op == 'N') {
            Insert(H,currentQQ,0,currentPasswd);
        }else{
            Insert(H,currentQQ,1,currentPasswd);
        }
    }
    return 0;
    
}
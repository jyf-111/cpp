/*给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

输入格式:
输入首先给出正整数N（≤10
​5
​​ ），为通话记录条数。随后N行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

输出格式:
在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

输入样例:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
输出样例:
13588625832 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
#define KEYLENGTH 11 // 关键词字符串的最大长度 
#define MAXD 5 //
// 关键词类型用字符串 
typedef char ElementType[KEYLENGTH + 1];
typedef int Index; // 散列地址类型 
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
	int Count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef struct TblNode *HashTable;
struct TblNode { // 散列表结点定义 
	int TableSize; // 表的最大长度 
	List Heads; // 指向链表头结点的数组 
};
#define MAXTABLESIZE 1000000
int NextPrime(int N)
{ // 返回大于N且不超过MAXTABLESIZE的最小素数 
	int i, p = (N % 2) ? N + 2 : N + 1; //从大于N的下一个奇数开始 
	while (p <= MAXTABLESIZE) {
		for (i = (int)sqrt(p); i>2; i--)
			if (!(p%i)) break; // p不是素数 
		if (i == 2) break; // for正常结束，说明p是素数 
		else p += 2; // 否则试探下一个奇数 
	}
	return p;
}
int Hash(int Key, int P)
{ // 除留余数法法散列函数 
	return Key%P;
}
HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	for (i = 0; i<H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0'; H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0;
	}
	return H;
}
Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;
	// 初始散列位置 
	Pos = Hash(atoi(Key+KEYLENGTH-MAXD), H->TableSize);
	P = H->Heads[Pos].Next; // 从该链表的第1个结点开始 
							// 当未到表尾，并且Key未找到时
	while (P && strcmp(P->Data, Key))
		P = P->Next;
	return P; // 此时P或者指向找到的结点，或者为NULL 
}
bool Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	Index Pos;
	P = Find(H, Key);
	if (!P) { // 关键词未找到，可以插入 
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		// 初始散列位置 
		NewCell->Count = 1;
		Pos = Hash(atoi(Key+KEYLENGTH-MAXD), H->TableSize);
		// 将NewCell插入为H->Heads[Pos]链表的第1个结点 
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else { // 关键词已存在 
		P->Count++;
		return false;
	}
}
 
void ScanAndOutput(HashTable H)
{
	int i, MaxCnt = 0,PCnt = 0;
	ElementType MinPhone;
	List Ptr;
	MinPhone[0] = '\0';
	for (i = 0; i<H->TableSize; i++) { // 扫描链表 
		Ptr = H->Heads[i].Next;
		while (Ptr) {
			if (Ptr->Count > MaxCnt) { // 更新最大通话次数 
				MaxCnt = Ptr->Count;
				strcpy(MinPhone, Ptr->Data);
				PCnt = 1;
			}
			else if (Ptr->Count == MaxCnt) {
				PCnt++; // 狂人计数 
				if (strcmp(MinPhone, Ptr->Data)>0)
					strcpy(MinPhone, Ptr->Data); // 更新狂人的最小手机号码 
			}
			Ptr = Ptr->Next;
		}
	}
	printf("%s %d", MinPhone, MaxCnt);
	if (PCnt > 1) printf(" %d", PCnt);
	printf("\n");
}
 
int main()
{
	int N, i;
	ElementType Key;
	HashTable H;
	scanf("%d", &N);
	H = CreateTable(N * 2); /* 创建一个散列表 */
	for (i = 0; i<N; i++) {
		scanf("%s", Key); Insert(H, Key);
		scanf("%s", Key); Insert(H, Key);
	}
	ScanAndOutput(H);
	//DestroyTable(H);
	system("pause");
	return 0;
}
 
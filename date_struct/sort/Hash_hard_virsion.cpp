/*
Given a hash table of size N, we can define a hash function H(x)=x%N. Suppose that the linear probing is used to solve collisions, we can easily obtain the status of the hash table with a given sequence of input numbers.

However, now you are asked to solve the reversed problem: reconstruct the input sequence from the given status of the hash table. Whenever there are multiple choices, the smallest number is always taken.

Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), which is the size of the hash table. The next line contains N integers, separated by a space. A negative integer represents an empty cell in the hash table. It is guaranteed that all the non-negative integers are distinct in the table.

Output Specification:
For each test case, print a line that contains the input sequence, with the numbers separated by a space. Notice that there must be no extra space at the end of each line.

Sample Input:
11
33 1 13 12 34 38 27 22 32 -1 21
Sample Output:
1 13 12 21 33 34 38 27 22 32
*/
#include <iostream>
#include <queue>
using namespace std;
#define MYINFINITY 65535
#define MaxVertexNum 1000
 
// 邻接表存储 - Kruskal最小生成树算法 
 
//-------------------- 顶点并查集定义 --------------------
typedef int ElementType; // 默认元素可以用非负整数表示 
typedef int SetName;     // 默认用根结点的下标作为集合名称 
typedef int DataType;        // 顶点存储的数据类型设为字符型 
 
queue<int> myQueue;
int mySeq[MaxVertexNum];
int TopOrder[MaxVertexNum];
int Indegree[MaxVertexNum];
// 边的定义
typedef struct ENode *PtrToENode;
struct ENode {
	int V1, V2;      // 有向边<V1, V2> 
};
typedef PtrToENode Edge;
//邻接点的定义 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	int AdjV;        // 邻接点下标 
	PtrToAdjVNode Next;    // 指向下一个邻接点的指针 
};
//顶点表头结点的定义
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;	// 边表头指针 
	DataType Data;				// 存顶点的数据 
								// 注意：很多情况下，顶点无数据，此时Data可以不用出现 
} AdjList[MaxVertexNum];		// AdjList是邻接表类型 
								//图结点的定义 
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;			// 顶点数 
	int Ne;			// 边数   
	AdjList G;		// 邻接表 
};
typedef PtrToGNode LGraph; // 以邻接表方式存储的图类型 
 
LGraph CreateGraph(int VertexNum)
{ //初始化一个有VertexNum个顶点但没有边的图 
	LGraph Graph;
 
	Graph = (LGraph)malloc(sizeof(struct GNode)); // 建立图 
	Graph->Nv = VertexNum;
	//初始化邻接表头指针 
	for (int V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}
 
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	//将V2插入V1的表头 
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
}
 
int Hash(int Key, int P)
{ // 除留余数法散列函数 
	return Key%P;
}
 
//N表示一共有几个读入数据，NReal表示表里面一共几个数据（注意因为可能存在 -1）
LGraph BuildGraph(int &N,int &NReal)
{
	LGraph Graph;
	Edge E;
	int neNum = 0;	//边数
	cin >> N;		//读入顶点个数 
	Graph = CreateGraph(N); //初始化有Nv个顶点但没有边的图 
	for (int i = 0;i < N;i++) {
		cin >> mySeq[i];
		Graph->G[i].Data = mySeq[i];
		if (mySeq[i] >= 0)
			NReal++;
	}
	//初始化Indegree[] 
	for (int V = 0; V < Graph->Nv; V++) {
		Indegree[V] = 0;
	}
	//虽然可以和上上面的for循环合二为一，但是这里为了表示更清楚，就不合二为一了。
	for (int i = 0;i < N;i++) {
		int tempHash = Hash(mySeq[i], N);
		if (mySeq[i] >= 0 && tempHash != i) {
			for (int j = i;j != tempHash;)
			{
				j = (j + N - 1) % N;
				E = (Edge)malloc(sizeof(struct ENode)); //建立边结点
				E->V1 = j;
				E->V2 = i;
				InsertEdge(Graph, E);
				Indegree[i]++;
			}		
		}
		else if(mySeq[i] < 0){
			Indegree[i] = MYINFINITY;
		}
	}
	return Graph;
}
 
int FindMin(LGraph Graph)//寻找目前入度为零并且数值最小的数
{
	int i, index = -1, min = MYINFINITY;
	for (i = 0;i < Graph->Nv;i++)
	{
		if (Indegree[i] == 0 && Graph->G[i].Data < min && Graph->G[i].Data>=0)
		{
			min = Graph->G[i].Data;
			index = i;
		}
	}
	return index;
}
 
//邻接表存储 - 拓扑排序算法 
int TopSort(LGraph Graph, int TopOrder[])
{ //对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 
	int cnt;
	int V;
	PtrToAdjVNode W;		
 
	//下面进入拓扑排序 
	cnt = 0;
	int minV = FindMin(Graph);
	myQueue.push(minV);
	while (!myQueue.empty()) {
		V = myQueue.front(); //弹出一个入度为0的顶点 
		//cout << V << endl;
		myQueue.pop();
		Indegree[V] = MYINFINITY;
		TopOrder[cnt++] = Graph->G[V].Data; //将之存为结果序列的下一个元素 
		//对V的每个邻接点W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			--Indegree[W->AdjV];
		}
	
		minV = FindMin(Graph);
		if (minV == -1)break;
		myQueue.push(minV);
		
	} //while结束
 
	return cnt;
}
 
int main(void) {
 
	int N=0, NReal=0;
	LGraph myGraph = BuildGraph(N, NReal);
	
 
	int cnt = TopSort(myGraph, TopOrder);
	for (int i = 0;i < cnt -1;i++) {
		cout << TopOrder[i] << " ";
	}cout << TopOrder[cnt -1];
	
	
	system("pause");
	return 0;
}
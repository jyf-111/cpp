#include <iostream>
#include <queue>
using namespace std;
 
#define MaxVertexNum 1000
typedef int Vertex;
#define MYINFINITY 60000000
// 邻接表存储 - Kruskal最小生成树算法 
 
//-------------------- 顶点并查集定义 --------------------
typedef Vertex ElementType; // 默认元素可以用非负整数表示 
typedef Vertex SetName;     // 默认用根结点的下标作为集合名称 
typedef ElementType SetType[MaxVertexNum]; // 假设集合元素下标从0开始 							    
typedef int WeightType;       // 边的权值设为整型 
typedef char DataType;        // 顶点存储的数据类型设为字符型 
Vertex Earliest[MaxVertexNum];
Vertex Latest[MaxVertexNum];
queue<Vertex> myQueue;
//下面三个数组是为了生成反向AOE图的
Vertex V1Array[MaxVertexNum];
Vertex V2Array[MaxVertexNum];
WeightType WeightArray[MaxVertexNum];
//存储关键活动的
int keyActivityNum = 0;
struct keyActivity {
	Vertex Vstart;
	Vertex Vend;
};
keyActivity myKeyActivity[MaxVertexNum];
// 边的定义
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // 有向边<V1, V2> 
	WeightType Weight;  // 权重 
};
typedef PtrToENode Edge;
//邻接点的定义 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // 邻接点下标 
	WeightType Weight;  // 边权重 
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
	Vertex V;
	LGraph Graph;
 
	Graph = (LGraph)malloc(sizeof(struct GNode)); // 建立图 
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化邻接表头指针 
	//注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
 
	return Graph;
}
 
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
 
	//插入边 <V1, V2> 
	//为V2建立新的邻接点 
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//将V2插入V1的表头 
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
 
	//注意拓扑排序是用的有向图
 
	//若是无向图，还要插入边 <V2, V1> 
	//为V1建立新的邻接点 
	//NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	//NewNode->AdjV = E->V1;
	//NewNode->Weight = E->Weight;
	//将V1插入V2的表头 
	//NewNode->Next = Graph->G[E->V2].FirstEdge;
	//Graph->G[E->V2].FirstEdge = NewNode;
}
 
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
 
	cin >> Nv;   //读入顶点个数 
	Graph = CreateGraph(Nv); //初始化有Nv个顶点但没有边的图 
 
	cin >> Graph->Ne;   //读入边数 
	if (Graph->Ne != 0) { //如果有边 
		E = (Edge)malloc(sizeof(struct ENode)); //建立边结点 
												//读入边，格式为"起点 终点 权重"，插入邻接矩阵 
		for (i = 0; i<Graph->Ne; i++) {
			cin >> E->V1 >> E->V2 >> E->Weight;
			E->V1--;
			E->V2--;
			V1Array[i] = E->V1;
			V2Array[i] = E->V2;
			WeightArray[i] = E->Weight;
			//注意：如果权重不是整型，Weight的读入格式要改 
			InsertEdge(Graph, E);
		}
	}
 
	//如果顶点有数据的话，读入数据 
	//for (V = 0; V<Graph->Nv; V++)
	//cin >> Graph->G[V].Data;
 
	return Graph;
}
 
LGraph BuildBackGraph(LGraph Graph1)
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv = Graph1->Nv, i;
	Graph = CreateGraph(Nv); //初始化有Nv个顶点但没有边的图
	if (Graph1->Ne != 0) { //如果有边 
		E = (Edge)malloc(sizeof(struct ENode)); //建立边结点 
												//读入边，格式为"起点 终点 权重"，插入邻接矩阵 
		for (i = 0; i<Graph1->Ne; i++) {
			E->V1 = V2Array[i];
			E->V2 = V1Array[i];
			E->Weight = WeightArray[i];
			//注意：如果权重不是整型，Weight的读入格式要改 
			InsertEdge(Graph, E);
		}
	}
 
	//如果顶点有数据的话，读入数据 
	//for (V = 0; V<Graph->Nv; V++)
	//cin >> Graph->G[V].Data;
 
	return Graph;
}
 
//返回最大的元素
Vertex getMaxElement(Vertex arr[],int N) {
	Vertex maxElement = 0;
	for (int i = 0; i < N; i++)
		if (maxElement < arr[i]) {
			maxElement = arr[i];
		}
			
	return maxElement;
}
 
//邻接表存储 - 拓扑排序算法 
bool TopSort(LGraph Graph, Vertex TopOrder[])
{ //对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
 
	//初始化Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//遍历图，得到Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //对有向边<V, W->AdjV>累计终点的入度 
	//将所有入度为0的顶点入列 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			myQueue.push(V);
	//下面进入拓扑排序 
	cnt = 0;
	while (!myQueue.empty()) {
		V = myQueue.front(); //弹出一个入度为0的顶点 
		myQueue.pop();
		TopOrder[cnt++] = V; //将之存为结果序列的下一个元素 
							 //对V的每个邻接点W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//若删除V使得W->AdjV入度为0 
				myQueue.push(W->AdjV); //则该顶点入列 
			if ((Earliest[V] + W->Weight)>Earliest[W->AdjV]) {
				Earliest[W->AdjV] = Earliest[V] + W->Weight;
			}
		}
 
	} //while结束
 
	if (cnt != Graph->Nv)
		return false; //说明图中有回路, 返回不成功标志 
	else
		return true;
}
 
//邻接表存储 - 反向查找时间算法 
bool keyRoute(LGraph Graph, int showestTime)
{ //对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 
	int Indegree[MaxVertexNum];
	Vertex V;
	PtrToAdjVNode W;
 
	//初始化Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//遍历图，得到Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //对有向边<V, W->AdjV>累计终点的入度 
								 //将所有入度为0的顶点入列 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0) {
			myQueue.push(V);
			Latest[V] = showestTime;
		}
		else {
			Latest[V] = MYINFINITY;
		}
			
	//下面进入拓扑排序 
	while (!myQueue.empty()) {
		V = myQueue.front(); //弹出一个入度为0的顶点 
		myQueue.pop();
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//若删除V使得W->AdjV入度为0 
				myQueue.push(W->AdjV); //则该顶点入列 
			if ((Latest[V] - W->Weight)<Latest[W->AdjV]) {
				Latest[W->AdjV] = Latest[V] - W->Weight;
			}
		}
 
	} //while结束
	return true;
}
 
//邻接表存储 - 再次正向去寻找的机动时间的算法 
void cal4KeyRoute(LGraph Graph)
{ //对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
 
	//初始化Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//遍历图，得到Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //对有向边<V, W->AdjV>累计终点的入度 
								 //将所有入度为0的顶点入列 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			myQueue.push(V);
	//下面进入拓扑排序 
	cnt = 0;
	while (!myQueue.empty()) {
		V = myQueue.front(); //弹出一个入度为0的顶点 
		myQueue.pop();
		//对V的每个邻接点W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//若删除V使得W->AdjV入度为0 
				myQueue.push(W->AdjV); //则该顶点入列 
			if ((Latest[W->AdjV] - W->Weight)<=Earliest[V]) { //注意不是输出有机动时间的，而是输出没有机动时间的
				//cout << (V) << "->" << (W->AdjV)<< " "<< W->Weight << endl;
				myKeyActivity[keyActivityNum].Vstart = (V + 1);
				myKeyActivity[keyActivityNum].Vend = (W->AdjV + 1);
				keyActivityNum++;
			}
		}
	} //while结束
	//cout << endl;
}
 
//只对起始点进行排序，不打乱输入反向的顺序（题目要求的）
void mySort(void) {
	for(int i = 0;i<keyActivityNum-1;i++)
		for (int j = 0;j<keyActivityNum-i-1;j++) {
			if (myKeyActivity[j].Vstart > myKeyActivity[j + 1].Vstart) {
				Vertex temp;
				temp = myKeyActivity[j].Vstart;
				myKeyActivity[j].Vstart = myKeyActivity[j + 1].Vstart;
				myKeyActivity[j + 1].Vstart = temp;
				temp = myKeyActivity[j].Vend;
				myKeyActivity[j].Vend = myKeyActivity[j + 1].Vend;
				myKeyActivity[j + 1].Vend = temp;
			}
		}
}
 
int main(void) {
 
	LGraph myGraph = BuildGraph();
	Vertex TopOrder[MaxVertexNum];
	bool flag = TopSort(myGraph, TopOrder);
	Vertex showestTime = getMaxElement(Earliest, myGraph->Nv);
	
	if (true == flag) {
		cout << showestTime << endl;
		//继续处理
		LGraph backGraph = BuildBackGraph(myGraph);
		keyRoute(backGraph, showestTime);
		//for (int i = 0;i < myGraph->Nv;i++) {
		//	cout << Latest[i] <<" ";
		//}cout << endl;
		cal4KeyRoute(myGraph);
		mySort();
		for (int i = 0;i < keyActivityNum;i++) {
			cout << myKeyActivity[i].Vstart << "->" << myKeyActivity[i].Vend << endl;
		}
	}
	else {
		cout << "0";
	}
 
	system("pause");
	return 0;
}
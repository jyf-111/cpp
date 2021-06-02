#include <iostream>
#include <queue>
using namespace std;
 
#define MaxVertexNum 1000
typedef int Vertex;
#define MYINFINITY 60000000
// �ڽӱ�洢 - Kruskal��С�������㷨 
 
//-------------------- ���㲢�鼯���� --------------------
typedef Vertex ElementType; // Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ 
typedef Vertex SetName;     // Ĭ���ø������±���Ϊ�������� 
typedef ElementType SetType[MaxVertexNum]; // ���輯��Ԫ���±��0��ʼ 							    
typedef int WeightType;       // �ߵ�Ȩֵ��Ϊ���� 
typedef char DataType;        // ����洢������������Ϊ�ַ��� 
Vertex Earliest[MaxVertexNum];
Vertex Latest[MaxVertexNum];
queue<Vertex> myQueue;
//��������������Ϊ�����ɷ���AOEͼ��
Vertex V1Array[MaxVertexNum];
Vertex V2Array[MaxVertexNum];
WeightType WeightArray[MaxVertexNum];
//�洢�ؼ����
int keyActivityNum = 0;
struct keyActivity {
	Vertex Vstart;
	Vertex Vend;
};
keyActivity myKeyActivity[MaxVertexNum];
// �ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // �����<V1, V2> 
	WeightType Weight;  // Ȩ�� 
};
typedef PtrToENode Edge;
//�ڽӵ�Ķ��� 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // �ڽӵ��±� 
	WeightType Weight;  // ��Ȩ�� 
	PtrToAdjVNode Next;    // ָ����һ���ڽӵ��ָ�� 
};
//�����ͷ���Ķ���
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;	// �߱�ͷָ�� 
	DataType Data;				// �涥������� 
								// ע�⣺�ܶ�����£����������ݣ���ʱData���Բ��ó��� 
} AdjList[MaxVertexNum];		// AdjList���ڽӱ����� 
//ͼ���Ķ��� 
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;			// ������ 
	int Ne;			// ����   
	AdjList G;		// �ڽӱ� 
};
typedef PtrToGNode LGraph; // ���ڽӱ�ʽ�洢��ͼ���� 
 
LGraph CreateGraph(int VertexNum)
{ //��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ 
	Vertex V;
	LGraph Graph;
 
	Graph = (LGraph)malloc(sizeof(struct GNode)); // ����ͼ 
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӱ�ͷָ�� 
	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
 
	return Graph;
}
 
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
 
	//����� <V1, V2> 
	//ΪV2�����µ��ڽӵ� 
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//��V2����V1�ı�ͷ 
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
 
	//ע�������������õ�����ͼ
 
	//��������ͼ����Ҫ����� <V2, V1> 
	//ΪV1�����µ��ڽӵ� 
	//NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	//NewNode->AdjV = E->V1;
	//NewNode->Weight = E->Weight;
	//��V1����V2�ı�ͷ 
	//NewNode->Next = Graph->G[E->V2].FirstEdge;
	//Graph->G[E->V2].FirstEdge = NewNode;
}
 
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
 
	cin >> Nv;   //���붥����� 
	Graph = CreateGraph(Nv); //��ʼ����Nv�����㵫û�бߵ�ͼ 
 
	cin >> Graph->Ne;   //������� 
	if (Graph->Ne != 0) { //����б� 
		E = (Edge)malloc(sizeof(struct ENode)); //�����߽�� 
												//����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� 
		for (i = 0; i<Graph->Ne; i++) {
			cin >> E->V1 >> E->V2 >> E->Weight;
			E->V1--;
			E->V2--;
			V1Array[i] = E->V1;
			V2Array[i] = E->V2;
			WeightArray[i] = E->Weight;
			//ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� 
			InsertEdge(Graph, E);
		}
	}
 
	//������������ݵĻ����������� 
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
	Graph = CreateGraph(Nv); //��ʼ����Nv�����㵫û�бߵ�ͼ
	if (Graph1->Ne != 0) { //����б� 
		E = (Edge)malloc(sizeof(struct ENode)); //�����߽�� 
												//����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� 
		for (i = 0; i<Graph1->Ne; i++) {
			E->V1 = V2Array[i];
			E->V2 = V1Array[i];
			E->Weight = WeightArray[i];
			//ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� 
			InsertEdge(Graph, E);
		}
	}
 
	//������������ݵĻ����������� 
	//for (V = 0; V<Graph->Nv; V++)
	//cin >> Graph->G[V].Data;
 
	return Graph;
}
 
//��������Ԫ��
Vertex getMaxElement(Vertex arr[],int N) {
	Vertex maxElement = 0;
	for (int i = 0; i < N; i++)
		if (maxElement < arr[i]) {
			maxElement = arr[i];
		}
			
	return maxElement;
}
 
//�ڽӱ�洢 - ���������㷨 
bool TopSort(LGraph Graph, Vertex TopOrder[])
{ //��Graph������������,  TopOrder[]˳��洢�����Ķ����±� 
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
 
	//��ʼ��Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//����ͼ���õ�Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //�������<V, W->AdjV>�ۼ��յ����� 
	//���������Ϊ0�Ķ������� 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			myQueue.push(V);
	//��������������� 
	cnt = 0;
	while (!myQueue.empty()) {
		V = myQueue.front(); //����һ�����Ϊ0�Ķ��� 
		myQueue.pop();
		TopOrder[cnt++] = V; //��֮��Ϊ������е���һ��Ԫ�� 
							 //��V��ÿ���ڽӵ�W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//��ɾ��Vʹ��W->AdjV���Ϊ0 
				myQueue.push(W->AdjV); //��ö������� 
			if ((Earliest[V] + W->Weight)>Earliest[W->AdjV]) {
				Earliest[W->AdjV] = Earliest[V] + W->Weight;
			}
		}
 
	} //while����
 
	if (cnt != Graph->Nv)
		return false; //˵��ͼ���л�·, ���ز��ɹ���־ 
	else
		return true;
}
 
//�ڽӱ�洢 - �������ʱ���㷨 
bool keyRoute(LGraph Graph, int showestTime)
{ //��Graph������������,  TopOrder[]˳��洢�����Ķ����±� 
	int Indegree[MaxVertexNum];
	Vertex V;
	PtrToAdjVNode W;
 
	//��ʼ��Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//����ͼ���õ�Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //�������<V, W->AdjV>�ۼ��յ����� 
								 //���������Ϊ0�Ķ������� 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0) {
			myQueue.push(V);
			Latest[V] = showestTime;
		}
		else {
			Latest[V] = MYINFINITY;
		}
			
	//��������������� 
	while (!myQueue.empty()) {
		V = myQueue.front(); //����һ�����Ϊ0�Ķ��� 
		myQueue.pop();
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//��ɾ��Vʹ��W->AdjV���Ϊ0 
				myQueue.push(W->AdjV); //��ö������� 
			if ((Latest[V] - W->Weight)<Latest[W->AdjV]) {
				Latest[W->AdjV] = Latest[V] - W->Weight;
			}
		}
 
	} //while����
	return true;
}
 
//�ڽӱ�洢 - �ٴ�����ȥѰ�ҵĻ���ʱ����㷨 
void cal4KeyRoute(LGraph Graph)
{ //��Graph������������,  TopOrder[]˳��洢�����Ķ����±� 
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
 
	//��ʼ��Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;
 
	//����ͼ���õ�Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; //�������<V, W->AdjV>�ۼ��յ����� 
								 //���������Ϊ0�Ķ������� 
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			myQueue.push(V);
	//��������������� 
	cnt = 0;
	while (!myQueue.empty()) {
		V = myQueue.front(); //����һ�����Ϊ0�Ķ��� 
		myQueue.pop();
		//��V��ÿ���ڽӵ�W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0)//��ɾ��Vʹ��W->AdjV���Ϊ0 
				myQueue.push(W->AdjV); //��ö������� 
			if ((Latest[W->AdjV] - W->Weight)<=Earliest[V]) { //ע�ⲻ������л���ʱ��ģ��������û�л���ʱ���
				//cout << (V) << "->" << (W->AdjV)<< " "<< W->Weight << endl;
				myKeyActivity[keyActivityNum].Vstart = (V + 1);
				myKeyActivity[keyActivityNum].Vend = (W->AdjV + 1);
				keyActivityNum++;
			}
		}
	} //while����
	//cout << endl;
}
 
//ֻ����ʼ��������򣬲��������뷴���˳����ĿҪ��ģ�
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
		//��������
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
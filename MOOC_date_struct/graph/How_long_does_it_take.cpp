/*
Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (¡Ü100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N?1), and M, the number of activities. Then M lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

Output Specification:
For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".

Sample Input 1:
9 12
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
5 4 0
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
Sample Output 1:
18
Sample Input 2:
4 5
0 1 1
0 2 2
2 1 3
1 3 4
3 2 5
Sample Output 2:
Impossible
*/
#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 1000
typedef int Vertex;

typedef Vertex ElemenType;
typedef Vertex SetName;
typedef ElemenType SetType[MaxVertexNum];
typedef int WeightType;
typedef char DataType;
Vertex Earliest[MaxVertexNum];
queue<Vertex> myQueue;
// ????
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
//?????? 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};
//?????????
typedef struct VNode {
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];
//?????? 
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum) {
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V = 0 ; V<Graph->Nv ; V++) {
        Graph->G[V].FirstEdge = nullptr;
    }

    return Graph;
}

void InsertEdge(LGraph Graph,Edge E) {
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
}

LGraph BuildGraph() {
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    cin >> Nv;
    Graph = CreateGraph(Nv);

    cin >> Graph->Ne;
    if(Graph->Ne!=0) {
        E = (Edge)malloc(sizeof(struct ENode));

        for(i=0 ; i<Graph->Ne ; ++i) {
            cin >> E->V1 >> E->V2 >> E->Weight;
            InsertEdge(Graph , E);
        }

    }
    return Graph;
}

Vertex getMaxElement(Vertex arr[],int N) {
    Vertex MaxElement = 0;
    for(int i=0 ; i<N ; i++) {
        if(MaxElement < arr[i]){
            MaxElement = arr[i];
        }
    }
    return MaxElement;
}

bool TopSort(LGraph Graph , Vertex TopOrder[]) {
    int Indegree[MaxVertexNum],cnt;
    Vertex V;
    PtrToAdjVNode W;

    for(auto &i:Indegree) {
        i = 0;
    }

    for(V = 0; V<Graph->Nv ; V++) {
        for(W = Graph->G[V].FirstEdge;W;W = W->Next) {
            Indegree[W->AdjV]++;
        }
    }
    for(V = 0;V<Graph->Nv ; V++) {
        if(Indegree[V]==0){
            myQueue.push(V);
        }
    }
    cnt = 0;
    while(!myQueue.empty()) {
        V = myQueue.front();
        myQueue.pop();
        TopOrder[cnt++] = V;

        for(W = Graph->G[V].FirstEdge;W;W = W->Next) {
            if(--Indegree[W->AdjV]==0){
                myQueue.push(W->AdjV);
            }
            if((Earliest[V]+W->Weight)>Earliest[W->AdjV]){
                Earliest[W->AdjV] = Earliest[V] + W->Weight;
            }
        }
    }
    if(cnt!=Graph->Nv){
        return false;
    }else{
        return true;
    }
}

int main()
{
    LGraph myGraph = BuildGraph();
    Vertex TopOrder[MaxVertexNum];
    bool flag = TopSort(myGraph,TopOrder);
    Vertex showestTime = getMaxElement(Earliest,myGraph->Nv);
    if(true == flag) {
        cout << showestTime;
    }else{
        cout << "Impossible";
    }
}
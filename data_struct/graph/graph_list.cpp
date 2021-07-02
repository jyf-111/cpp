#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode {
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum) {
    Vertex V;
    LGraph Graph = new struct GNode;
    Graph->Nv = VertexNum;
    Graph->Ne=0;
    for(V=0;V<VertexNum;V++){
        Graph->G[V].FirstEdge = nullptr;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E) {
    PtrToAdjVNode NewNode = new struct AdjVNode;
    NewNode->AdjV = E->V2;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    NewNode->Weight = E->Weight;
    Graph->G[E->V1].FirstEdge = NewNode;
/*
    NewNode = new struct AdjVNode;
    NewNode->AdjV=E->V1;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    NewNode->Weight = E->Weight;
    Graph->G[E->V2].FirstEdge = NewNode;*/
}

LGraph BuildGraph() {
    LGraph Graph;
    Edge E = new struct ENode;
    Vertex V;
    int Nv,Ne,i;
    cin >> Nv >> Ne;

    Graph = CreateGraph(Nv);
    Graph->Ne = Ne;
    Graph->Nv= Nv;
    for(V=0 ;V<Graph->Ne;V++)
    {
        cin >> E->V1 >> E->V2 >> E->Weight;
        InsertEdge(Graph,E);
    }
    return Graph;
}
int Visited[100] = {0};
void DFS(LGraph Graph,Vertex V) {
    Visited[V] = true;
    cout << V << " ->";
    for(PtrToAdjVNode W = Graph->G[V].FirstEdge;W;W = W->Next){
        if(!Visited[W->AdjV]){
            DFS(Graph,W->AdjV);
        }
    }
}

void DepthFirstSearch(LGraph Graph,Vertex V) {
    stack<Vertex> S;
    int Visited[MaxVertexNum] = {0};

    S.push(V);
    while(!S.empty()) {
        V = S.top();
        S.pop();
        if(!Visited[V]) {
            cout << V << "->";
            Visited[V] = true;
            PtrToAdjVNode p = Graph->G[V].FirstEdge;
            while(p) {
                if(!Visited[p->AdjV])
                    S.push(p->AdjV);
                p = p->Next;
            }
        }
    }
}

void BFS(LGraph Graph,Vertex V) {
    bool Visited[MaxVertexNum] = {0};
    queue<Vertex> Q;
    Visited[V] = true;
    cout << V << " ->";
    Q.push(V);
    while(!Q.empty()) {
        V = Q.front();
        Q.pop();
        for(PtrToAdjVNode W = Graph->G[V].FirstEdge ; W ; W = W->Next) {
            if(!Visited[W->AdjV]) {
                cout << W->AdjV << "->";
                Visited[W->AdjV] = true;
                Q.push(W->AdjV);
            }
        }
    }
}
int a[MaxVertexNum] ;
void DFS_path(LGraph Graph,int u,int v);
void one_path(LGraph Graph,int u,int v) {
    
    for(auto &i:a){
        i  =-1;
    }
    a[u] = -2;
    DFS_path(Graph,u,v);
}
void DFS_path(LGraph Graph,int u,int v){
        for(PtrToAdjVNode p = Graph->G[u].FirstEdge ; p ; p = p->Next) {

            if(a[p->AdjV]==-1){
                a[p->AdjV] = u;
                if(p->AdjV == v){
                    while(a[v]!=-2) {
                        cout << v << "<-";
                        v = a[v];
                    }
                }else {
                    
                    DFS_path(Graph,p->AdjV,v);
                }
            }
            
        }
}

void FindId(LGraph G,int indegree[]) {
    int i;
    PtrToAdjVNode p;
    for(int i=0;i<MaxVertexNum;i++) {
        indegree[i] = 0;
    }
    for(i = 0;i<G->Nv;i++) {
        p = G->G[i].FirstEdge;
        while(p) {
            indegree[p->AdjV]++;
            p = p->Next;
        }
    }
}


void TopSort(LGraph Graph) {
    int indegree[MaxVertexNum];
    FindId(Graph,indegree);
    stack<Vertex> S;
    for(int i=0;i<Graph->Nv;i++) {
        if(indegree[i]==0) {
            S.push(i);
        }
    }
    while(!S.empty()) {
        Vertex V = S.top();
        S.pop();
        cout << V << "->" ;
        for(PtrToAdjVNode p = Graph->G[V].FirstEdge ; p ;p = p->Next) {
            indegree[p->AdjV]--;
            if(indegree[p->AdjV]==0) S.push(p->AdjV);
        }
    }
} 

int ve[MaxVertexNum]={0};
stack<Vertex> T;
void TopOrder(LGraph Graph,stack<Vertex> *T) {
    stack<Vertex> S;
    int indegree[MaxVertexNum];
    FindId(Graph,indegree);
    for(int i=0;i<Graph->Nv;i++) {
        if(indegree[i]==0) S.push(i);
    }
    while(!S.empty()) {
        Vertex V = S.top();
        S.pop();
        T->push(V);
        for(PtrToAdjVNode p = Graph->G[V].FirstEdge ; p ; p = p->Next) {
            indegree[p->AdjV]--;
            if(indegree[p->AdjV]==0) {
                S.push(p->AdjV);
            }
            if(ve[V]+p->Weight > ve[p->AdjV]) {
                ve[p->AdjV] = ve[V] + p->Weight;
            }
        }
    }
}

void CriticalPath(LGraph Graph) {
    stack<Vertex> T;//返回逆序拓扑排序的栈
    int vl[MaxVertexNum] ;
    
    TopOrder(Graph,&T);
    for(auto &i:vl) {
        i = ve[Graph->Nv-1];
    }
    while(!T.empty()) {
        Vertex V = T.top();
        T.pop();
        for(PtrToAdjVNode p = Graph->G[V].FirstEdge ; p ; p = p->Next) {
            if(vl[p->AdjV]-p->Weight < vl[V] ) {
                vl[V] = vl[p->AdjV] - p->Weight;
            }
        }
    }
    for(int i=0;i<Graph->Nv;i++) {
        for(PtrToAdjVNode p = Graph->G[i].FirstEdge ; p; p =p->Next) {
            if(ve[i]+p->Weight == vl[p->AdjV]) {
                cout << "(" << i<< "," << p->AdjV << ")" << endl;
            }
        }
    }
}

int main()
{
/*
8 10
0 1 1
0 2 2
1 3 3
1 4 4
2 5 5
2 6 6
3 7 7
4 7 8
5 7 9
6 7 10
*/
    LGraph Graph = BuildGraph();
    DFS(Graph,0);
    cout << endl;
    for(int i=0 ;i<Graph->Nv;i++) {
        PtrToAdjVNode p= Graph->G[i].FirstEdge;
        cout << i<<" : ";
        while(p) {
            cout << p->AdjV << " ";
            p = p->Next;
        }
        cout << endl;
    }
    cout << endl;
    BFS(Graph,0);

    cout << endl; 
    DepthFirstSearch(Graph,0);
    cout << endl;
    one_path(Graph,0,7);
    cout << endl << "TopSort : ";
    TopSort(Graph);
    cout << endl;
    
    TopOrder(Graph,&T);
    for(int i=0 ;i<Graph->Nv;i++) {
        cout << ve[i] << " ";
    }
    cout << endl << "T : ";
    while(!T.empty()) {
        cout << T.top() << ' ';
        T.pop();
    }
    cout << endl << "critical Path : " << endl;
    CriticalPath(Graph);
}
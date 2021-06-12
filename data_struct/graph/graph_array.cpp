#include<iostream>
#define Maxsize 100
typedef int Vertex;
#include<queue>
using namespace std;

struct ENode {
    int V1,V2;
    int Weight;
};
typedef struct ENode* Edge;

struct MGraph {
    int G[Maxsize][Maxsize];
    int Nv;
    int Ne;
};
typedef struct MGraph* Graph;

Graph CreateGraph(int Nv) {
    Graph Graph = new struct MGraph;
    Graph->Nv = Nv;
    Graph->Ne=0;
    for(Vertex V=0;V<Nv;V++){
        for(Vertex W=0;W<Nv;W++) {
            Graph->G[V][W] = INT_MAX;
        }
    } 
    return Graph;
}

void Insert(Graph Graph,Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

Graph BuildGraph() {
    int Nv;
    cin >> Nv;
    Graph Graph = CreateGraph(Nv);
    cin >> Graph->Ne;
    Edge E= new struct ENode;
    for(int i=0;i<Graph->Ne;i++){
        cin >> E->V1 >> E->V2 >> E->Weight;
        Insert(Graph,E);
    }
    return Graph;
}

void DFS(Graph Graph,Vertex V) {
    static bool Visited[100] = {0};
    Visited[V] = true;
    cout << V << "->" ;
    for(Vertex W=0;W<Graph->Nv;W++) {
        if(!Visited[W] && Graph->G[V][W]<INT_MAX) {
            //cout << "->" << W ;
            DFS(Graph,W);
        }
    }
}

void BFS(Graph Graph,Vertex V){
    bool Visited[Graph->Nv]={false};
    Visited[V] = true;
    cout << V;
    queue<Vertex> Q;
    Q.push(V);
    while(!Q.empty()) {
        V = Q.front();
        Q.pop();
        for(Vertex W=0;W<Graph->Nv;W++){
            if(Graph->G[V][W]<INT_MAX && !Visited[W]){
                cout << "->" << W;
                Visited[W]=true;
                Q.push(W);
            }
        }
    }
}

struct {
    int adjvex;
    int lowcost;
}closedge[Maxsize];

void Prim(Graph Graph,int u) {
    closedge[u].lowcost =0;
    for(int i=0 ;i<Graph->Nv;i++){
        if(i!=u){
            closedge[i].lowcost = Graph->G[u][i];
            
            closedge[i].adjvex = u;
        }
    }
    for(int e=1;e<Graph->Nv ;e++) {
        int v;
        int min = 9999;
        for(int j=0 ;j<Graph->Nv ;j++) {
            if(closedge[j].lowcost<min && closedge[j].lowcost!=0) {
                min = closedge[j].lowcost;
                v = j;
            }
        }
        u = closedge[v].adjvex;
        cout <<"(" << u <<"," << v <<")" << endl;
        closedge[v].lowcost = 0;
        for(int i=0;i<Graph->Nv;i++){
            if(Graph->G[v][i]<closedge[i].lowcost) {
                closedge[i].lowcost = Graph->G[v][i];
                closedge[i].adjvex = v;
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
    Graph Graph = BuildGraph();
    
    DFS(Graph,0);
    cout << endl;
    BFS(Graph,0);
    Prim(Graph,0);
}


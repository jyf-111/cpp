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
            Graph->G[V][W] = 9999;
        }
    } 
    return Graph;
}

void Insert(Graph Graph,Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    //Graph->G[E->V2][E->V1] = E->Weight;
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

int FindMin(Graph Graph,int dist[],bool collect[]) {
    int min=999,m=-1;
    for(int i=0 ;i<Graph->Nv;i++) {
        if(dist[i]<min && !collect[i] ) {
            min = dist[i];
            m = i;
        }
    }
    return m;
}

void Dijkstra(Graph Graph,Vertex S) {
    bool collect[Maxsize] ;
    for(auto &i:collect) {
        collect[i] = false;
    }
    int dist[Maxsize];
    int path[Maxsize];
    Vertex V,W;
    for(V = 0;V<Graph->Nv;V++) {
        dist[V] = Graph->G[S][V];
        if(dist[V]<INT_MAX) {
            path[V] = S;
        }else{
            path[V] = -1;
        }
    }
    path[S] = -1;
    collect[S] = true;
    while(1) {
        V = FindMin(Graph,dist,collect);
        if(V==-1) break;
        collect[V] = true;
        for(W = 0;W<Graph->Nv;W++) {
            if(!collect[W] && Graph->G[V][W]<INT_MAX) {
                if(dist[V]+Graph->G[V][W] < dist[W]) {
                    dist[W] = dist[V]+Graph->G[V][W];
                    path[W] = V;
                }
            }
        }
    }
    for(int i=0 ;i<Graph->Nv;i++) {
        cout <<dist[i] << " ";
    }
}

void Floyd(Graph Graph) {
    int dist[Maxsize][Maxsize];
    int path[Maxsize][Maxsize];
    for(int V = 0;V<Graph->Nv;V++) {
        for(int W = 0;W<Graph->Nv;W++) {
            if(V==W) dist[V][W] = 0;
            else 
            dist[V][W] = Graph->G[V][W];
            path[V][W] = -1; 
        }
    }
    int k,v,w;
        for(k = 0; k < Graph->Nv; k++){
        //v为起点 
        for(v = 0 ; v < Graph->Nv; v++){
            //w为终点 
            for(w =0; w < Graph->Nv; w++){
                if(dist[v][w] > (dist[v][k] + dist[k][w])){
                    dist[v][w] = dist[v][k] + dist[k][w];//更新最小路径 
                    path[v][w] = k;//更新最小路径中间顶点 
                }
            }
        }
    }

    for(int V = 0;V<Graph->Nv;V++) {
        for(int W = 0;W<Graph->Nv;W++) {
            cout << dist[V][W] << " "; 
        }
        cout << endl;
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
    cout << endl << "Dijkstra : " << endl;
    Dijkstra(Graph,0);
    cout << endl;

    Floyd(Graph);
}


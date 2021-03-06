#include<iostream>
#define MAXSIZE 100
#define INFINITY 1000
using namespace std;

typedef int Vertex;

typedef struct ENode *Edge;
struct ENode {
    Vertex V1;
    Vertex V2;
    int weight;
};

typedef struct GNode *Graph;
struct GNode {
    int a[MAXSIZE][MAXSIZE];
    int Nv;
    int Ne;
};

Graph CreateGraph(int Nv) {
    Graph graph = new struct GNode;
    graph->Nv = Nv;
    graph->Ne = 0;
    for(Vertex V = 0 ; V<Nv ;V++) {
        for(Vertex W = 0 ; W<Nv ;W++) {
            if(V==W) graph->a[V][W] = 0;
            else graph->a[V][W] = INFINITY;
        }
    }
    return graph;
}

void Insert(Graph graph,Edge edge) {
    graph->a[edge->V1][edge->V2] = edge->weight;
}

Graph BuildGraph() {
    int Nv;
    cin >> Nv;
    Graph graph = CreateGraph(Nv);
    cin >> graph->Ne;
    Edge edge = new struct ENode;
    for(int i=0;i<graph->Ne;i++) {
        cin >> edge->V1 >> edge->V2 >> edge->weight;
        Insert(graph,edge);
    }
    return graph;
}

void PrintGraph(Graph graph) {
    for(Vertex V = 0 ;V <graph->Nv ;V++) {
        for(Vertex W = 0; W<graph->Nv ;W++) {
            cout.width(5);
            cout << graph->a[V][W];
        }
        cout << endl;
    }
}

int FindMin(Graph graph ,bool collected[],int dist[]) {
    int min = INFINITY;
    int num = -1;
    Vertex V;
    for(V = 0 ; V < graph->Nv ;V++) {
        if( collected[V]==false && dist[V] < min) {
            min = dist[V];
            num = V;
        }
    }
    return num;
}

bool Prim(Graph graph) {
    int dist[MAXSIZE] = {0};
    bool collected[MAXSIZE] = {false};

    for(Vertex V = 0 ; V<graph->Nv ;V++) {
        dist[V] = graph->a[0][V];
    }
    //dist[0] = 0;
    collected[0] = true;
    for(int i=1 ;i<graph->Nv ;i++) {
        Vertex V = FindMin(graph,collected,dist);
        collected[V] = true;
        for(Vertex W = 0 ;W<graph->Nv ;W++) {
            if(collected[W]==false && graph->a[V][W] < dist[W]) {
                dist[W] = graph->a[V][W];
            }
        }
        
    }
    
    for(Vertex V = 0 ;V<graph->Nv ;V++) {
        if(collected[V]==0) {
            cout << "min Tree is not exist" << endl;
            return false;
        }
    }
    for(Vertex V = 0; V<graph->Nv ;V++) {
            cout << dist[V] << " ";
        }
    cout << endl;
    
    return true;
}

void FloydPath(Vertex path[][100],Vertex V,Vertex W) {
    if(path[V][W]==-1) {
        cout << "(" << V << "," << W << ")";
    }
    else{
        FloydPath(path,V,path[V][W]);
        FloydPath(path,path[V][W],W);
    }
    
}

void Floyd(Graph graph) {
    Vertex path[MAXSIZE][MAXSIZE] ;
    int dist[MAXSIZE][MAXSIZE] ;
    for(Vertex V = 0; V<graph->Nv ;V++) {
        for(Vertex W=0 ;W<graph->Nv ;W++) {
            path[V][W] = -1;
            dist[V][W] = graph->a[V][W];
        }
    }

    for(Vertex K = 0;K<graph->Nv;K++) {
        for(Vertex V = 0; V<graph->Nv ;V++) {
            for(Vertex W=0 ;W<graph->Nv ;W++) {
                if(dist[V][K]+dist[K][W] < dist[V][W]) {
                    dist[V][W] = graph->a[V][K] + graph->a[K][W];
                    path[V][W] = K; 
                }
            }
        }
    }
    FloydPath(path,0,7);
}



int main()
{
    Graph graph = BuildGraph();
    //PrintGraph(graph);
    Prim(graph);
    Floyd(graph);
}

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
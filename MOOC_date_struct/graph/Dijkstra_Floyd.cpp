#include<iostream>
#include<queue>
using namespace std;

#define Vertex int
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1,V2;
    int Weight;
};
typedef PtrToENode Edge;

typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    int G[100][100];
} graph ;
typedef PtrToGNode Graph;

int visited[100]={0};
int dist[100];
int path[100];

void BFS(Vertex S){
    queue<Vertex> Q;
    Q.push(S);
    visited[S]=1;
    while(!Q.empty()) {
        Vertex temp = Q.front();
        Q.pop();
        for(int i=0 ;i < graph.Nv;i++){
            if(graph.G[temp][i]<INT_MAX && !visited[i]){
                Q.push(i);
                visited[i]=1;
            }
        }
    }
}

Vertex FindMinDist(int collected[]) {
    Vertex MinV,V;
    int MinDist = INT_MAX;
    for(V=0 ; V<graph.Nv;V++){
        if(collected[V]==false && dist[V]<MinDist){
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist<INT_MAX){
        return MinV;
    }else{
        return -1;
    }
}

bool Dijkstra(Vertex S) {
    int collected[100];
    Vertex V,W;
    for(int i=0;i<graph.Nv;i++){
        dist[i]=graph.G[S][i];
        if(dist[i]<INT_MAX){
            path[i]=S;
        }else{
            path[i]=-1;
        }
        collected[i]=false;
    }
    dist[S]=0;
    collected[S]=true;
    while(1) {
        V = FindMinDist(collected);
        if(V == -1)break;
        collected[V]=true;
        for(W=0;W<graph.Nv;W++) {
            if(collected[W]==false && graph.G[V][W]<INT_MAX) {
                if(graph.G[V][W]<0){
                    return false;
                }
                if(dist[V]+graph.G[V][W] < dist[W]){
                    dist[W] = dist[V]+graph.G[V][W];
                    path[W] = V;
                }
            }
            return true;
        }

    }
}

bool Floyd(Graph G,Vertex path[][100]){
    for(int i=0;i<G->Nv;i++){
        for(int j=0;j<G->Nv;j++){
            path[i][j]=-1;
        }
    }
    for(Vertex k=0;k<G->Nv;k++){
        for(int i=0;i<G->Nv;i++){
            for(int j=0;j<G->Nv;j++){
                if(G->G[i][k]+G->G[k][j] < G->G[i][j]){
                    G->G[i][j] = G->G[i][k]+G->G[k][j];
                    if(i==j && G->G[i][j]<0){
                        return false;
                    }
                    path[i][j] = k;
                }
            }

    }
    }
    return true;
}
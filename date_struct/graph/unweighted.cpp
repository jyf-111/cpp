#include<iostream>
#include<queue>
#define Vertex int
using namespace std;
//边
typedef struct ENode* Edge;
struct ENode {
    Vertex V1,V2;
    int Weight;
};
//邻接点
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    int Weight;
    struct AdjVNode* Next;
};

//表头
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
}AdjList[10];

int visited[10] ={ 0 };
int dist[10] ;
int path[10] ;


void DFS(AdjList G,Vertex V) {
    PtrToAdjVNode W;
    visited[V] = 1;
    for(W = G->FirstEdge ; W ;W=W->Next){
        if(visited[W->AdjV]==0){
            DFS(G,W->AdjV);
        }
    }
}

void unweight(AdjList G,Vertex s) {//s是根节点
    queue<int> Q;
    Vertex V;
    PtrToAdjVNode W;
    for(auto &i:dist){
        i=-1;
    }
    for(auto &i:path){
        i=-1;
    }
    dist[s]=0;
    Q.push(s);
    while(!Q.empty()){
        Vertex temp = Q.front();
        Q.pop();
        for(W = G[temp].FirstEdge; W ;W = W->Next) {
            if(dist[W->AdjV]==-1){
                dist[W->AdjV]=dist[temp]+1;
                path[W->AdjV]=temp;
                Q.push(W->AdjV);
            }
        }
    }
}
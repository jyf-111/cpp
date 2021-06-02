/*矩阵实现*/
#include<iostream>
using namespace std;
#define Vertex int
#define Maxsize 10
//边的定义
typedef struct ENode* Edge;
struct ENode {
    Vertex V1,V2;
    int weight;
};

int G[Maxsize][Maxsize];
int dist[Maxsize];
Vertex path[Maxsize];

void createGraph() {
    for(auto &i:G){
        for(auto &j:i){
            j = INT_MAX;
        }
    }
    for(int i=0;i<Maxsize;i++){
        G[i][i]=0;
    }
    for(auto &i:dist){
        i = INT_MAX;
    }
    for(auto &i:path){
        i = -1;
    }
}

Vertex findMin(bool collected[]) {
    Vertex Min=-1;
    int minnum = INT_MAX;
    for(int i=0;i<Maxsize;i++) {
        if(false==collected[i]&&dist[i]<minnum){
            minnum = dist[i];
            Min = i;
        }
    }
    return Min;
}

void Dijkstra(Vertex S) {
    bool collected[Maxsize];
    for(auto &i:collected){
        i = false;
    }
    Vertex V,W;
    for(V=0;V<Maxsize;V++){
        dist[V] = G[S][V];
        if(dist[V]<INT_MAX){
            path[V] = S;
        }else{
            path[V] = -1;
        }
    }
    path[S] = -1;
    collected[S]=true;
    while(1){
        V = findMin(collected);
        if(-1==V)break;
        for(W=0;W<Maxsize;W++){
            if(collected[W]==false && G[V][W]<INT_MAX){
                if(dist[V]+G[V][W]<dist[W]){
                    dist[W] = dist[V] +G[V][W];
                    path[W] = V;
                }
            }
        }
    }
}

int main()
{
    createGraph();
    Dijkstra(1);
}
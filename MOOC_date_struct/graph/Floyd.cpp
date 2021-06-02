#include<iostream>
using namespace std;
#define Maxsize 10
#define Vertex int
int path[Maxsize][Maxsize];

struct ENode {
    Vertex V1,V2;
    int weight;
};

int G[Maxsize][Maxsize];

void Floyd(){
    for(Vertex k;k<Maxsize;k++){
        for(Vertex i;i<Maxsize;i++){
            for(Vertex j;j<Maxsize;j++){
                if(G[i][k]+G[k][j]<G[i][j]){
                    G[i][j] = G[i][k]+G[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}
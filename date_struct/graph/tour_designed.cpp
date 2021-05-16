/*有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:
输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N?1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。随后的M行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

输出格式:
在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

输入样例:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出样例:
3 40*/

#include<iostream>
#define Maxsize 500
#define MAX 60000
using namespace std;
struct Edge {
    int length;
    int cost;
};
Edge G[Maxsize][Maxsize];

void initgraph(int N,int M) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                G[i][j].length=0;
                G[i][j].cost = 0;
            }
            else {
                G[i][j].length = MAX;
                G[i][j].cost = MAX;
            }
        }
    }
    int i,j,length,cost;
    for(int c=0;c<M;c++){
        cin >> i >> j >> length >> cost;
        G[j][i].length = G[i][j].length = length;
        G[j][i].cost = G[i][j].cost = cost; 
    }
    
}

int FindminV(int N,bool collected[],int dist[]) {
    int MinV = MAX,V,min=-1;
    for(V=0;V<N;V++){
        if(collected[V]==false && dist[V]<MinV){
            MinV = dist[V]; 
            min = V;
        }
    }
    return min;
}

void dijkstra(int N,int S,int D){
    int *path = new int[N];
    int *dist = new int[N];
    bool *collected = new bool[N];
    int *cost = new int[N];;
    for(int i=0;i<N;i++){
        if(G[S][i].length<MAX){
            path[i] = S;
        }else{
            path[i] = -1;
        }
        dist[i] = G[S][i].length;
        cost[i] = G[S][i].cost;
        collected[i] = false;
    }
    collected[S] = true;
    path[S] = -1;
    dist[S] = 0;
    cost[S] = 0;
    while(1){
        int V,W;
        V = FindminV(N,collected,dist);
        //cout << V << endl;
        if(V == -1)break;
        collected[V] = true;
        for(W=0 ; W<N ;W++){
            if(G[V][W].length < MAX &&  collected[W]==false){
                if(dist[V]+G[V][W].length < dist[W]) {
                    dist[W] = dist[V]+G[V][W].length;
                    path[W] = V;
                    cost[W] = cost[V] + G[V][W].cost;

                }else if(dist[V]+G[V][W].length == dist[W] && (cost[V] + G[V][W].cost < cost[W])){
                    cost[W] = cost[V] + G[V][W].cost;
                    path[W] = V;
                }
            }
        }
        
    }
    
    cout << dist[D] <<' ' << cost[D];
    delete []path;
    delete []dist;
    delete []cost;
    delete []collected;
}

int main()
{
    int N;
    int M;
    int S;
    int D;
    cin >> N >> M >> S >> D;
    initgraph(N,M);
    dijkstra(N,S,D);
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << G[i][j].cost << " ";
        }
        cout << endl;
    }*/

}
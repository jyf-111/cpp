/*����һ���Լ�����·��ͼ�����֪�����м�ĸ��ٹ�·���ȡ��Լ��ù�·Ҫ��ȡ�Ĺ�·�ѡ�������Ҫ��дһ�����򣬰���ǰ����ѯ���ο���һ�������غ�Ŀ�ĵ�֮������·���������������·��������̵ģ���ô��Ҫ�������˵�һ��·����

�����ʽ:
����˵�����������ݵĵ�1�и���4��������N��M��S��D������N��2��N��500���ǳ��еĸ�����˳�������еı��Ϊ0~(N?1)��M�Ǹ��ٹ�·��������S�ǳ����صĳ��б�ţ�D��Ŀ�ĵصĳ��б�š�����M���У�ÿ�и���һ�����ٹ�·����Ϣ���ֱ��ǣ�����1������2�����ٹ�·���ȡ��շѶ�м��ÿո�ֿ������־�Ϊ�����Ҳ�����500�����뱣֤��Ĵ��ڡ�

�����ʽ:
��һ�������·���ĳ��Ⱥ��շ��ܶ���ּ��Կո�ָ��������β�����ж���ո�

��������:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
�������:
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
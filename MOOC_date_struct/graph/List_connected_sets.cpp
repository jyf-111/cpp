/*
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N?1编号。进行搜索时，
假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v
?1
??  v
?2
??  ... v
?k
??  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool vis[15];
bool G[15][15];
int N,E;

void dfs(int x);
void bfs(int x);

int main()
{
    cin >> N >> E;
    for(int i = 0 ; i < E ; ++i) {
        int a,b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
    }
    memset(vis,0,sizeof(vis));
    for(int i = 0 ; i<N ; ++i) {
        if(!vis[i]){
            cout <<"{ ";
            dfs(i);
            cout <<'}'<<endl;
        }
    }

    memset(vis,0,sizeof(vis));
    for(int i = 0 ; i<N ; ++i) {
        if(!vis[i]){
            cout <<"{ ";
            bfs(i);
            cout <<'}'<<endl;
        }
    }
}

void dfs(int x){
    if(vis[x])return;
    cout<<x<<' ';
    vis[x]=true;
    for(int i =0;i<N;i++){
        if(G[x][i])
        dfs(i);
    }
    return ;
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        cout << p << ' ';
        for(int i = 0 ;i<N;i++){
            if(G[p][i]&&!vis[i]){
                q.push(i);
                vis[i]= true;
            }
        }
    }
}
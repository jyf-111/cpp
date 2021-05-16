/*
����һ����N�������E���ߵ�����ͼ������DFS��BFS�ֱ��г������е���ͨ�������趥���0��N?1��š���������ʱ��
�����������Ǵӱ����С�Ķ������������ŵ�����˳������ڽӵ㡣
�����ʽ:
�����1�и���2������N(0<N��10)��E���ֱ���ͼ�Ķ������ͱ��������E�У�ÿ�и���һ���ߵ������˵㡣ÿ���е�����֮����1�ո�ָ���

�����ʽ:
����"{ v
?1
??  v
?2
??  ... v
?k
??  }"�ĸ�ʽ��ÿ�����һ����ͨ���������DFS�Ľ���������BFS�Ľ����

��������:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
�������:
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
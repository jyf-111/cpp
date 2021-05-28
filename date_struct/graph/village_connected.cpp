/*现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，求使每个村落都有公路连通所需要的最低成本。

输入格式:
输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；随后的M行对应M条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。为简单起见，城镇从1到N编号。

输出格式:
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出?1，表示需要建设更多公路。

输入样例:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
输出样例:
12
*/

#include<iostream>
#include<algorithm>
using namespace std;

#define N 1005

struct edg {
    int a,b,w;

    bool operator < (const edg &p) const {
        return w<p.w;
    }
}edges[N*6];
int n,m,fa[N];
int ans,cnt;
int find(int x) {
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal() {
    sort(edges,edges+m);
    for(int i=0 ;i<m ; ++i) {
        int a=edges[i].a;
        int b=edges[i].b;
        int w=edges[i].w;
        int faa=find(a);
        int fbb=find(b);
        if(faa!=fbb){
            fa[faa] = fbb;
            ans+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return -1;
    return ans;
}

int main()
{
    for(int i=0 ; i<N ; i++) {
        fa[i]=i;
    }
    cin >> n >>m;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin >>a>>b>>w;
        edges[i]={a,b,w};
    }
    cout << kruskal();
}
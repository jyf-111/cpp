#include<iostream>
using namespace std;
#define MAXN 10000+10

int par[MAXN],Rank[MAXN];
typedef struct {
    int a;
    int b;
    int price;
}Node;
Node a[MAXN];

int cmp(const void* a,const void *b) {
    return ((Node*)a)->price - ((Node*)b)->price;
}

void Init(int n) {
    for(int i=0;i<n;i++) {
        Rank[i] = 0;
        par[i] = 0;
    }
}

int find_1(int x) {
    int root = x;
    while(root != par[root]) root = par[root];
    while(x!=root) {
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}
int find_2(int x) {
    if(x==par[x]) return x;
    else{
        return par[x] = find_2(par[x]);
    }
}

void unite(int x,int y) {
    x = find_1(x);
    y = find_1(y);
    if(Rank[x]<Rank[y]) {
        par[x] = y;
    }else{
        par[y] = x;
        if(Rank[x]==Rank[y]) Rank[x]++;
    }
}

int Kruskal(int n,int m) {
    int nEdge = 0,res = 0;
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0 ; i<n && nEdge!=m-1 ;i++) {
        if(find_2(a[i].a)!=find_2(a[i].b)) {
            unite(a[i].a,a[i].b);
            res +=a[i].price;
            nEdge++;
        }
    }
    if(nEdge<m-1) return res = -1;
    else return res;
}

int main()
{
    int n,m,ans;//n为边的数量，m为村庄的数量
    scanf("%d%d",&n,&m);

    
        Init(m);
        for(int i=0 ; i<n ;i++) {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].price);
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n,m);
        if(ans==-1) printf("?\n");
        else printf("%d\n",ans);
    
    return 0;
}
/*
10 8 
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
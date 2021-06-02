/*���д�����·��ͳ�����ݱ��У��г����п��ܽ���ɱ�׼��·����������·�ĳɱ�����ʹÿ�����䶼�й�·��ͨ����Ҫ����ͳɱ���

�����ʽ:
�������ݰ���������Ŀ������N����1000���ͺ�ѡ��·��ĿM����3N��������M�ж�ӦM����·��ÿ�и���3�����������ֱ��Ǹ�����·ֱ����ͨ����������ı���Լ��õ�·�Ľ���Ԥ��ɱ���Ϊ������������1��N��š�

�����ʽ:
������ͨ��Ҫ����ͳɱ�������������ݲ����Ա�֤��ͨ�������?1����ʾ��Ҫ������๫·��

��������:
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
�������:
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
/*�����ȿռ䡱�����ֳ��������ȷָ���Six Degrees of Separation�������ۡ�������ۿ���ͨ�׵ز���Ϊ��
������κ�һ��İ����֮����������˲��ᳬ��������Ҳ����˵�����ͨ�����������ܹ���ʶ�κ�һ��İ���ˡ�����ͼ1��ʾ��


ͼ1 ���ȿռ�ʾ��ͼ
�����ȿռ䡱������Ȼ�õ��㷺����ͬ���������ڵõ�Խ��Խ���Ӧ�á�������ʮ��������ͼ��֤�������ʼ�����������ѧ��Ŭ��׷���Ŀ�ꡣ
Ȼ��������ʷ��ԭ���������о�����̫��ľ����Ժ����ѡ����ŵ����˵�������Ҫ�����ڵ绰�����š�΢���Լ��������ϼ�ʱͨ�ŵȹ��ߣ�
�ܹ������罻�����ϵ��һ�������Ѿ���ʹ�á����ȿռ䡱���۵���֤��Ϊ���ܡ�

�������һ���罻����ͼ�������ÿ���ڵ������ϡ����ȿռ䡱���۵Ľ��ռ��������İٷֱȡ�

�����ʽ:
�����1�и����������������ֱ��ʾ�罻����ͼ�Ľ����N��1<N��10^3����ʾ������������M����33��N����ʾ�罻��ϵ������
����M�ж�ӦM���ߣ�ÿ�и���һ�����������ֱ��Ǹ�����ֱ����ͨ���������ı�ţ��ڵ��1��N��ţ���

�����ʽ:
��ÿ����������ý����벻����6�Ľ����ռ��������İٷֱȣ���ȷ��С�����2λ��ÿ����ڵ����һ�У���ʽΪ�������:���ո񣩰ٷֱ�%����

��������:
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
�������:
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%*/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int a[1010][1010]={0};
int visited[1010]={0};
int N;//�ڵ���
int M;//����

int BFS(int v) {
    queue<int> Q;
    int count = 1;
    int level = 0;
    int tail ;
    int last = v;
    if(visited[v] != 1){
        Q.push(v);
        visited[v]=1;
    }
    while(!Q.empty()) {
        int temp = Q.front();
        Q.pop();
        for(int i=0 ; i<N ; ++i) {
            if(visited[i]!=1&&a[temp][i]==1){
                Q.push(i);
                visited[i]=1;
                count++;
                tail = i;
            }
        }
        if(temp == last){
            level++;
            last = tail;
        }
        if(level==6){
            break;
        }
    }
    return count;
}

int main()
{
    cin >> N >> M;
    for(int i=0 ; i<M ; ++i) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i=0 ; i<N ; i++){
        int sum=BFS(i);
        float percentage=sum*100.0/N;
        printf("%d: %.2f%\n",i+1,percentage);
        memset(visited,0,sizeof(visited));
    }

}

#include<iostream>
#include<cstring>
using namespace std;
#define N 20
#define M 2*N-1

typedef struct {
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode,HuffmanTree[M+1];

int w[]={5,7,3,2,8};

void select(HuffmanTree ht,int n,int *s1,int *s2) {
    int min1 = 100000;
    for(int i=1;i<=n;i++){
        if(ht[i].parent==0) {
            if(ht[i].weight<min1){
                min1 = ht[i].weight;
                *s2 = *s1;
                *s1 = i;
            }
        }
    }
    
    //cout << "s1 : " << ht[*s1].weight << " s2 : " << ht[*s2].weight << endl;
}

void CrtHuffmanTree(HuffmanTree ht,int w[],int n) {
    for(int i = 1; i<=n ; i++) {
        ht[i] = {w[i-1],0,0,0};
    }
    int m = 2*n-1;
    for(int i = n+1 ; i<=m ; ++i) {
        ht[i] = {0,0,0,0};
    }
    for(int i = n+1 ; i<=m ; ++i) {
        int s1,s2;
        select(ht,i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight+ht[s2].weight;
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].LChild = s1;
        ht[i].RChild = s2;
    }
}

typedef char * HuffmanCode[N+1];

void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n) {
    char * cd = (char *)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    for(int i=1;i<=n;i++) {
        int start = n-1;
        int c= 1;
        int p = ht[i].parent;
        while(p!=0) {
            --start;
            if(ht[p].LChild==c){
                cd[start] = '0';
            }
            else cd[start] = '1';
            c = p;
            p = ht[p].parent;
            
        }
        hc[i] = (char *)malloc((n-start)*sizeof(char));
        hc[i][n-start-1] = '\0';
        strcpy(hc[i],&cd[start]);
    }
    free(cd);
}

int main()
{
    HuffmanTree H;
    HuffmanCode Hf;
    CrtHuffmanTree(H,w,sizeof(w)/sizeof(int));
    CrtHuffmanCode(H,Hf,5);
    for(int i= 1;i<=sizeof(w)/sizeof(int);i++) {
        printf("%s\n",Hf[i]);
    }
}

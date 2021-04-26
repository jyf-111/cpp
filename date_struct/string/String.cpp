#include<iostream>
#include<cstring>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40/* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
typedef char String[MAXSIZE+1];/*  0�ŵ�Ԫ��Ŵ��ĳ��� */

/* ����һ����ֵ����chars�Ĵ�T */
Status StrAssign(String T, char *chars)
{
	/*strlen-->����ַ�������*/
    int i;
    if(strlen(chars)>MAXSIZE)return ERROR;
    else {
        T[0] = strlen(chars);
        for(i = 1 ; i<=T[0] ; ++i) {
            T[i] = *(chars+i-1);
        }
        return OK;
    }
}

/* �ɴ�S���Ƶô�T */
Status StrCopy(String T,String S) {
    for(int i = 0 ; i <= S[0] ; ++i){
        T[i] = S[i];
    }
    return OK;
}

/* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
Status StrEmpty(String S) {
    if(0==S[0]){
        return TRUE;
    }else{
        return FALSE;
    }
}

/*  ��ʼ����: ��S��T���� */
/*  �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
int StrCompare(String S,String T) {
    for(int i = 1 ; i <= S[0]&&i<=T[0] ; ++i) {
        if(S[i]!=T[i]){
            return S[i]-T[i];
        }
    }
    return S[0]-T[0];
}

/* ���ش���Ԫ�ظ��� */
int StrLength(String S) {
    return S[0];
}

/* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
stat ClearString(String S) {
    S[0] = 0;
}

/* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
Status Concat(String T,String S1,String S2) {
    int i;
    if(S1[0]+S2[0]<=MAXSIZE){
        /*  δ�ض� */
        for(i = 1; i < S1[0];++i) {
            T[i]=S1[i];
        }
        for(i = 1; i<S2[0];++i){
            T[S1[0]+i] = S2[i];
        }
        T[0] = S1[0]+S2[0];
        return TRUE;
    }else{
        /*  �ض�S2 */
        for(i = 1;i<S1[0];++i){
            T[i] = S1[i];
        }
        for(i = 1;i<=MAXSIZE-S1[0];++i){
            T[S1[0]+i] = S2[i];
        }
        T[0] = MAXSIZE;
        return FALSE;
    }
}

/* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
Status SubString(String Sub,String S,int pos,int len) {
    int i;
    if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1) {
        return ERROR;
    }
    for(i = 1 ; i<=len ; ++i){
        Sub[i] = S[pos+i-1];
    }
    Sub[0] = len;
    return OK;
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
/* ����,T�ǿ�,1��pos��StrLength(S)�� */
int Index(String S,String T,int pos) {
    int i = pos;/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
    int j = 1;	/* j�����Ӵ�T�е�ǰλ���±�ֵ */
    while(i<=S[0]&&j<=T[0]){/* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
        if(S[i]==T[j]){	/* ����ĸ�������� */
            ++i;
            ++j;
        }else{	/* ָ��������¿�ʼƥ�� */
            i = i - j + 2;/* i�˻ص��ϴ�ƥ����λ����һλ */
            j = 1;/* j�˻ص��Ӵ�T����λ */
        }
    }
    if(j>T[0]){
        return i-T[0];
    }else{
        return 0;
    }
}

/*  TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ��� */
/*  �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 */
int Index2(String S,String T,int pos) {
    int n,m,i;
    String sub;
    i = pos;
    if(pos>0){
        n = StrLength(S);
        m = StrLength(T);
        while( i <= n-m+1) {
            SubString(sub,S,i,m);
            if(StrCompare(sub,T)!=0){
                ++i;
            }else{
                return i;
            }
        }
    }
    return 0;
}

/*  ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
/*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
Status StrInsert(String S,int pos,String T) {
    int i;
    if(pos<1||pos>S[0]+1){
        return ERROR;
    }
    if(S[0]+T[0]<=MAXSIZE){
        /*  ��ȫ���� */
        for(i = S[0];i>=pos;i--){
            S[i+T[0]] = S[i];
        }
        for(i = pos;i<pos+T[0];i++){
            S[i] = T[i-pos+1];
        }
        S[0] = S[0]+T[0];
        return TRUE;
    }else{
        /*  ���ֲ��� */
        for(i = MAXSIZE;i>=pos;i--){
            S[i] = S[i-T[0]];
        }
        for(i = pos;i<pos+T[0];i++){
            S[i] = T[i-pos+1];
        }
        S[0] = MAXSIZE;
        return FALSE;
    }
}

/*  ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
/*  �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
Status StrDelete(String S,int pos ,int len) {
    int i;
    if(pos <1 ||pos > S[0]-len +1 ||len < 0) {
        return ERROR;
    }
    for(i = pos + len ; i<=S[0] ;++i){
        S[i-len] = S[i];
    }
    S[0]-=len;
    return OK;
}

/*  ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
/*  �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
Status Replace(String S,String T,String V) {
    int i = 1;
    if(StrEmpty(T))return ERROR;
    do {
        i = Index(S,T,i);
        if(i){
            StrDelete(S,i,StrLength(T));
            StrInsert(S,i,V);
            i +=StrLength(V);
        }
    }while(i);
    return OK;
}

/*  ����ַ���T */
void StrPrint(String T) {
    int i ;
    for(i = 1; i<=T[0] ;++i){
        std::cout << T[i] ;
    }
    std::cout << std::endl;
}

/*�Ӵ����滻*/
Status RepStr1(String T, int i,int j,String V) {
    int k;
    String str;
    str[0] = 0;
    if(i <=0||i>T[0]||i+j-1>T[0]){
        return FALSE;
    }
}
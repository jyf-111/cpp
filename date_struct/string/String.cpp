#include<iostream>
#include<cstring>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40/* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
typedef char String[MAXSIZE+1];/*  0号单元存放串的长度 */

/* 生成一个其值等于chars的串T */
Status StrAssign(String T, char *chars)
{
	/*strlen-->检测字符串长度*/
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

/* 由串S复制得串T */
Status StrCopy(String T,String S) {
    for(int i = 0 ; i <= S[0] ; ++i){
        T[i] = S[i];
    }
    return OK;
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String S) {
    if(0==S[0]){
        return TRUE;
    }else{
        return FALSE;
    }
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(String S,String T) {
    for(int i = 1 ; i <= S[0]&&i<=T[0] ; ++i) {
        if(S[i]!=T[i]){
            return S[i]-T[i];
        }
    }
    return S[0]-T[0];
}

/* 返回串的元素个数 */
int StrLength(String S) {
    return S[0];
}

/* 初始条件:串S存在。操作结果:将S清为空串 */
stat ClearString(String S) {
    S[0] = 0;
}

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status Concat(String T,String S1,String S2) {
    int i;
    if(S1[0]+S2[0]<=MAXSIZE){
        /*  未截断 */
        for(i = 1; i < S1[0];++i) {
            T[i]=S1[i];
        }
        for(i = 1; i<S2[0];++i){
            T[S1[0]+i] = S2[i];
        }
        T[0] = S1[0]+S2[0];
        return TRUE;
    }else{
        /*  截断S2 */
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

/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
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

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(String S,String T,int pos) {
    int i = pos;/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
    int j = 1;	/* j用于子串T中当前位置下标值 */
    while(i<=S[0]&&j<=T[0]){/* 若i小于S的长度并且j小于T的长度时，循环继续 */
        if(S[i]==T[j]){	/* 两字母相等则继续 */
            ++i;
            ++j;
        }else{	/* 指针后退重新开始匹配 */
            i = i - j + 2;/* i退回到上次匹配首位的下一位 */
            j = 1;/* j退回到子串T的首位 */
        }
    }
    if(j>T[0]){
        return i-T[0];
    }else{
        return 0;
    }
}

/*  T为非空串。若主串S中第pos个字符之后存在与T相等的子串， */
/*  则返回第一个这样的子串在S中的位置，否则返回0 */
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

/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
/*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
Status StrInsert(String S,int pos,String T) {
    int i;
    if(pos<1||pos>S[0]+1){
        return ERROR;
    }
    if(S[0]+T[0]<=MAXSIZE){
        /*  完全插入 */
        for(i = S[0];i>=pos;i--){
            S[i+T[0]] = S[i];
        }
        for(i = pos;i<pos+T[0];i++){
            S[i] = T[i-pos+1];
        }
        S[0] = S[0]+T[0];
        return TRUE;
    }else{
        /*  部分插入 */
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

/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
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

/*  初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
/*  操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
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

/*  输出字符串T */
void StrPrint(String T) {
    int i ;
    for(i = 1; i<=T[0] ;++i){
        std::cout << T[i] ;
    }
    std::cout << std::endl;
}

/*子串的替换*/
Status RepStr1(String T, int i,int j,String V) {
    int k;
    String str;
    str[0] = 0;
    if(i <=0||i>T[0]||i+j-1>T[0]){
        return FALSE;
    }
}
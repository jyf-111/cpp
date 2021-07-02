#include<cstdio>
int main()
{
    FILE* fp = fopen("./data.txt","r");
    while(!feof(fp)) {
        char ch;
        fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
}
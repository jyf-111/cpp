/*���һ������
	int bracketmatch(char *str) 
�ú����Ĺ����ж���str�ַ����������ı��ʽ��Բ���š������š��������Ƿ�Ϸ���Ҳ��������ƥ�䡣�������ַ������κδ���
(1+35))  ���Ϸ�
[3]+{444}-[(333)]�Ϸ���
{1+[233}-]���Ϸ�
�Ϸ�����1�����Ϸ�����0*/

#include<stdio.h>
int bracketmatch(char *str) {
	char c[100];
	int top = -1;
	int p=0;
	while(str[p]!='\0') {
		switch(str[p]) {
			case '(' : 
			case '[' :
			case '{' :
					c[++top] = str[p]; break;
			case ')' :
			case ']' :
			case '}' :
					if(top==-1) return 0;
					if(c[top]=='('&& str[p]==')' || c[top]=='['&& str[p]==']' || c[top]=='{'&& str[p]=='}') {
						top--;
					}else{
						return 0;
					}
					break;
			default : break;
		}
		p++;
	}
	if(top==-1)
		return 1;
	else return 0;
}
//���µ�main����ִ�к�
int main(int argc, char* argv[])
{
	char *str="(1+5)*6 + ({3-5 + [5*9] +4}-6)";
	char *str1="(1+5)*6 + ({3-5 + [5*9] +4}-6)}"; 
	if(bracketmatch(str))
		printf("str bracket match OK!\n");
	else
		printf("str bracket match ERROR!\n");

	if(bracketmatch(str1))
		printf("str1 bracket match OK!\n");
	else
		printf("str1 bracket match ERROR!\n");

	return 0;
}
/*ִ�еĽ��Ϊ
str bracket match OK!
str1 bracket match ERROR!*/

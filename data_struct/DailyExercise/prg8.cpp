/*���һ������
	int stackinoutright(char inoutop[]) 
������I��O�ֱ��ʾ��ջ�ͳ�ջ��ջ�ĳ�̬����̬��Ϊ�գ���ջ�ͳ�ջ�Ĳ������пɱ�ʾΪI��O��ɵ�һ���ַ�������Ϊinoutop�ַ�����
�ú������������ж�������еĲ����Ƿ�Ϸ���������кϷ��򷵻�0������Ϊ�Ƿ����У�����-1

���µ�main����ִ�к�*/
#include<iostream>
using namespace std;

int stackinoutright(char inoutop[])  {
	int i_count=0;
	int o_count=0;
	int p=0;
	while(inoutop[p]!='\0') {
		if(inoutop[p]=='I') {
			i_count++;
		}
		if(inoutop[p]=='O') {
			o_count++;
		}
		if(o_count > i_count) {
			return -1;
		}
		p++;
	}
	if(i_count==o_count) {
		return 0;
	}else{
		return -1;
	}
	
}

int main(int argc, char* argv[])
{
	printf("%d    %d     %d\n", stackinoutright("IIOOIIO"), stackinoutright("IIIOOIOOIIIIOOOIOO"),  stackinoutright("IIIIIIIIOOIOOOO"));

	return 0;
}
/*
ִ�еĽ��Ϊ
-1    0     -1
*/
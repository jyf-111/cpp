/*���һ������nosame,������ʽ���£�
int nosame(int *a, int m, int n)
a��һ��ָ���ά������Ԫ�ص�ָ�룬��ָ�������m+1�У�n+1�У����е�0�к͵�0�е�������Ч��Ҳ����ֻ��Ҫ�ж�1--m�к�1--n�е����ݾͿ��ԣ�
�������������������������ͬ���򷵻�0�����򷵻�-1*/
#include<iostream>
using namespace std;

int nosame(int *a, int m, int n) {
	//a[i][j] = a[i*(n+1)+j];
	for(int i=7 ;i<=(m+1)*(n+1) ;i++) {
		if(i%6 ==0)
			continue;
		for(int j=i+1;j<=(m+1)*(n+1) ;j++) {
			if(j%6 ==0)
				continue;
			if(a[i]==a[j] ) {
				return -1;
			}
		}
	}
	return 0;
}

/*
���µ�main����ִ�к�* 
*/
int main(int argc, char* argv[])
{
	int a[5][6]={
		{0},
		{0,1,2,3,4,5},
		{0,11,12,13,14,15},
		{0,21,22,23,24,25},
		{0,31,32,33,34,35}
	};

	printf("%d\n", nosame((int *)a, 4,5));
	return 0;
}
/*
ִ�еĽ��Ϊ
0
*/
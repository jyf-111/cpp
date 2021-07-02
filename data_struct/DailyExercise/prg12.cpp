/*���һ������
	Reqalphaarray(DIMLIMIT  arraylimit[], int alphaarray[], int n , int L)
�书�������nά�����ÿһά��alphaֵ��Ҳ����ÿһά�е���Ԫ�ص��ֽ�����
arraylimit���飬��ʾ������ÿһά���������±ꡣL��ʾ�����У������Ԫ�ص��ֽ�����*/
#include<iostream>
#define N 100
using namespace std;

/*����DIMLIMIT�����½ṹ�壺*/
typedef struct{
	int c;           //����
	int d;           //����
} DIMLIMIT;

//��ȡarraylimit���ݺ������£�
void Inputarraylimit(DIMLIMIT  arraylimit[], int *n)
{
	int i;

	printf("Please Input dimension number\n");
	scanf("%d", n);
	for(i = 1; i <= *n; i++)
	{
		scanf("%d %d", &(arraylimit[i].c), &(arraylimit[i].d));
	}

}

//��ʾalphaֵ��������
void Printalphaarray(int alphaarray[], int n)
{
	int i;

	for(i = 1; i <=n; i++)
	{
		printf("alphaarray[%d] = %d\n", i, alphaarray[i]);
	}
}

void Reqalphaarray(DIMLIMIT  arraylimit[], int alphaarray[], int n , int L) {
	for(int i=1;i<=n;i++) {
		alphaarray[i] = L;
		for(int j=i+1 ;j<=n;j++) {
			alphaarray[i] *= (arraylimit[j].d-arraylimit[j].c+1);
		}
	}
}
//��ִ�����µ�main������
int main(int argc, char* argv[])
{
	int n;   //ʵ��ά��
	DIMLIMIT arraylimit[N];      //����������
	int alphaarray[N];           //alphaarray
	int L =  4;

	Inputarraylimit(arraylimit, &n);
	Reqalphaarray(arraylimit, alphaarray, n , L);
	Printalphaarray(alphaarray, n);
	return 0;
}
/*
�������Ϊ
4 5 6 7 10 -1 23 3 9
ִ�еĽ��Ϊ
alphaarray[1] = 2800
alphaarray[2] = 700
alphaarray[3] = 28
alphaarray[4] = 4
*/
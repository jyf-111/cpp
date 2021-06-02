/*给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：

数据1：只有1个元素；
数据2：11个不相同的整数，测试基本正确性；
数据3：103个随机整数；
数据4：104个随机整数；
数据5：105个随机整数；
数据6：105个顺序整数；
数据7：105个逆序整数；
数据8：105个基本有序的整数；
数据9：105个随机正整数，每个数字不超过1000。
输入格式:
输入第一行给出正整数N（≤10
?5
?? ），随后一行给出N个（长整型范围内的）整数，其间以空格分隔。

输出格式:
在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。

输入样例:
11
4 981 10 -17 0 -20 29 50 8 43 -5
输出样例:
-20 -17 -5 0 4 8 10 29 43 50 981
*/
#include <iostream>
#include <queue>
using namespace std;
 
#define MaxVertexNum 100005
typedef int ElementType;
ElementType myArray[MaxVertexNum];
 
void Swap(ElementType& A, ElementType& B) {
	ElementType C = A;
	A = B;
	B = C;
}
 
void Bubble_Sort(ElementType A[], int N)
{
	int flag;
	for (int P = N - 1; P >= 0; P--) {
		flag = 0;
		for (int i = 0; i<P; i++) { // 一趟冒泡 
			if (A[i] > A[i + 1]) {
				Swap(A[i], A[i + 1]);
				flag = 1; // 标识发生了交换 
			}
		}
		if (flag == 0) break; // 全程无交换
	}
}
 
void InsertionSort(ElementType A[], int N)
{ 
	// 插入排序 
	int P, i;
	ElementType Tmp;
 
	for (P = 1; P<N; P++) {
		Tmp = A[P]; // 取出未排序序列中的第一个元素
		for (i = P; i>0 && A[i - 1]>Tmp; i--)
			A[i] = A[i - 1]; //依次与已排序序列中元素比较并右移
		A[i] = Tmp; // 放进合适的位置 
	}
}
 
 
//希尔排序 - 用Sedgewick增量序列 
void ShellSort(ElementType A[], int N)
{ 
	int Si, D, P, i;
	ElementType Tmp;
	// 这里只列出一小部分增量 
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
 
	for (Si = 0; Sedgewick[Si] >= N; Si++)
		; // 初始的增量Sedgewick[Si]不能超过待排序列长度 
 
	for (D = Sedgewick[Si]; D>0; D = Sedgewick[++Si])
		for (P = D; P<N; P++) { // 插入排序
			Tmp = A[P];
			for (i = P; i >= D && A[i - D]>Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	//查看步骤
	//设一共71个数据，
	//D = 41,P=41, 0,41  1 42 一直到 30 71
	//D = 19,P=0 19,1 20……,19 38,20 39,21 40……
}
 
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}
 
void PercDown(ElementType A[], int p, int N)
{ // 改编代码4.24的PercDown( MaxHeap H, int p )    
  // 将N个元素的数组中以A[p]为根的子堆调整为最大堆 
	int Parent, Child;
	ElementType X;
 
	X = A[p]; // 取出根结点存放的值 
	for (Parent = p; (Parent * 2 + 1)<N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child]<A[Child + 1]))
			Child++;  // Child指向左右子结点的较大者 
		if (X >= A[Child]) break; // 找到了合适位置 
		else  // 下滤X 
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}
 
void HeapSort(ElementType A[], int N)
{ // 堆排序 
	int i;
 
	for (i = N / 2 - 1; i >= 0; i--)// 建立最大堆 
		PercDown(A, i, N);
 
	for (i = N - 1; i>0; i--) {
		// 删除最大堆顶 
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}
 
// 归并排序 - 递归实现 
// L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ // 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列
	int LeftEnd, NumElements, Tmp;
	int i;
 
	LeftEnd = R - 1; // 左边终点位置 
	Tmp = L;         // 有序序列的起始位置 
	NumElements = RightEnd - L + 1;
 
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; // 将左边元素复制到TmpA 
		else
			TmpA[Tmp++] = A[R++]; // 将右边元素复制到TmpA 
	}
 
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; // 直接复制左边剩下的 
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; // 直接复制右边剩下的 
 
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; // 将有序的TmpA[]复制回A[] 
}
 
void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ // 核心递归排序函数 
	int Center;
 
	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);              // 递归解决左边 
		Msort(A, TmpA, Center + 1, RightEnd);     // 递归解决右边 
		Merge(A, TmpA, L, Center + 1, RightEnd);  // 合并两段有序序列 
	}
}
 
void MergeSort(ElementType A[], int N)
{ // 归并排序 
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));
 
	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("空间不足");
}
 
// 归并排序 - 循环实现 
// 这里Merge函数在递归版本中给出 
// length = 当前有序子列的长度
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ // 两两归并相邻有序子列 
	int i, j;
 
	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) // 归并最后2个子列
		Merge(A, TmpA, i, i + length, N - 1);
	else // 最后只剩1个子列
		for (j = i; j < N; j++) TmpA[j] = A[j];
}
 
void Merge_Sort(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;
 
	length = 1; // 初始化子序列长
	TmpA = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("空间不足");
}
 
int main(void) {
	int N;cin >> N;
	for (int i = 0;i < N;i++)
		cin>>myArray[i];
 
	//进行排序
	//Bubble_Sort(myArray,N);//冒泡排序
	InsertionSort(myArray, N);//插入排序
	//ShellSort(myArray, N);//希尔排序
	//HeapSort(myArray, N);//堆排序
	//MergeSort(myArray, N);//归并排序，递归版本
	//Merge_Sort(myArray, N);//归并排序，非递归版本
 
 
	for (int i = 0;i < N - 1;i++)
		cout << myArray[i] << " ";
	cout << myArray[N - 1];
 
	system("pause");
	return 0;
}
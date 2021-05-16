/*According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (��100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6*/
#include<iostream>
using namespace std;

#define MaxVertexNum 105

typedef int ElementType;
ElementType myArray[MaxVertexNum];
ElementType myArray_1[MaxVertexNum];
ElementType myArray_2[MaxVertexNum];

int Insertflag = 0;

bool isSame(ElementType A[],ElementType B[],int N) {
    for(int i=0 ;i<N ;i++) {
        if(A[i]!=B[i]) return false;
    }
    return true;
}

void InsertionSort(ElementType A[], int N)
{ 
	// �������� 
	int P, i;
	ElementType Tmp;
    int flag = 0;
	for (P = 1; P<N; P++) {
		Tmp = A[P]; // ȡ��δ���������еĵ�һ��Ԫ��
		for (i = P; i>0 && A[i - 1]>Tmp; i--)
			A[i] = A[i - 1]; //������������������Ԫ�رȽϲ�����
		A[i] = Tmp; // �Ž����ʵ�λ�� 
        if(flag) break;
        if(isSame(A,myArray_2,N)){
            flag = 1;
            Insertflag = 1;
        }
	}
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ // �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ����������
	int LeftEnd, NumElements, Tmp;
	int i;
 
	LeftEnd = R - 1; // ����յ�λ�� 
	Tmp = L;         // �������е���ʼλ�� 
	NumElements = RightEnd - L + 1;
 
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; // �����Ԫ�ظ��Ƶ�TmpA 
		else
			TmpA[Tmp++] = A[R++]; // ���ұ�Ԫ�ظ��Ƶ�TmpA 
	}
 
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; // ֱ�Ӹ������ʣ�µ� 
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; // ֱ�Ӹ����ұ�ʣ�µ� 
 
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; // �������TmpA[]���ƻ�A[] 
}
 // �鲢���� - ѭ��ʵ�� 
// ����Merge�����ڵݹ�汾�и��� 
// length = ��ǰ�������еĳ���
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ // �����鲢������������ 
	int i, j;
 
	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) // �鲢���2������
		Merge(A, TmpA, i, i + length, N - 1);
	else // ���ֻʣ1������
		for (j = i; j < N; j++) TmpA[j] = A[j];
}
 
void Merge_Sort(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;
 
	length = 1; // ��ʼ�������г�
	TmpA = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
        int flag = 0;
        int f =0;
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
            if(isSame(A,myArray_2,N)){
                flag = 1;
            }
            if(f==1)break;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
            if(isSame(A,myArray_2,N))f =1;
            if(flag==1)break;
		}
		free(TmpA);
	}
	else printf("�ռ䲻��");
}
 
int main()
{
    int N;
    cin >> N;
    for(int i=0 ; i<N ; i++ ) {
        cin >> myArray[i];
        myArray_1[i] = myArray[i];
    }

    for(int i=0 ; i<N ; i++) {
        cin >> myArray_2[i];
    }
    
    InsertionSort(myArray_1,N);
    if(Insertflag) {
        cout << "Insertion Sort" << endl;
        for(int i=0 ; i<N ; i++) {
            if(i<N-1)
                cout << myArray_1[i] << ' ';
            else 
                cout << myArray_1[i];
        }
    }else{
        cout << "Merge Sort" << endl;
        Merge_Sort(myArray,N);
        for(int i=0 ; i<N ; i++) {
            if(i<N-1)
                cout << myArray[i] << ' ';
            else 
                cout << myArray[i];
        }
    }
}

    

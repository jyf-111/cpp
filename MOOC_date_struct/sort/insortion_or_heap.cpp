/*According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/
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
	// 插入排序 
	int P, i;
	ElementType Tmp;
    int flag = 0;
	for (P = 1; P<N; P++) {
		Tmp = A[P]; // 取出未排序序列中的第一个元素
		for (i = P; i>0 && A[i - 1]>Tmp; i--)
			A[i] = A[i - 1]; //依次与已排序序列中元素比较并右移
		A[i] = Tmp; // 放进合适的位置 
        if(flag) break;
        if(isSame(A,myArray_2,N)){
            flag = 1;
            Insertflag = 1;
        }
	}
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
    int flag = 0;
	for (i = N / 2 - 1; i >= 0; i--){// 建立最大堆 
		PercDown(A, i, N);
        if(flag==1)break;
        if(isSame(A,myArray_2,N)) flag=1;
 }
	for (i = N - 1; i>0; i--) {
		// 删除最大堆顶 
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
        if(flag==1)break;
        if(isSame(A,myArray_2,N)) {
            flag = 1;
        }
	}
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
        cout << "Heap Sort" << endl;
        HeapSort(myArray,N);
        for(int i=0 ; i<N ; i++) {
            if(i<N-1)
                cout << myArray[i] << ' ';
            else 
                cout << myArray[i];
        }
    }
}

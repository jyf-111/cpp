#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void TreeSelectSort(int a[],int n) {
	int leafnum = n;
	int h = ceil(log(n)/log(2))+1;
	int numh = pow(2,h)-1;
	int numh1 = pow(2,h-1)-1;

	int* record = new int [numh+1];

	memset(record,0,(numh+1)*sizeof(int));

	for(int i = 1;i<=leafnum;i++) {
		record[numh1+i] = a[i-1];
	}

	int count = 0;

	for(int i = numh1;i>0;i--) {
			record[i] = record[2*i] < record[2*i+1] ? record[2*i] : record[2*i+1];
	}

	while(count < n){	
		a[count++] = record[1];
		int p = 1;
		while(2*p <= numh) {
			p = record[2*p]==record[1]?2*p : 2*p+1;
		}
		record[p] = INT_MAX;
		for(p/=2;p>0;p/=2) {
			record[p] = record[2*p] < record[2*p+1] ? record[2*p] : record[2*p+1];
		}
	}

	delete [] record;
}

int main()
{
	int a[] ={10,6,7,1,3,9,4,2};
	TreeSelectSort(a,sizeof(a)/sizeof(decltype(a[0])));
	cout <<endl;
	for(auto i:a) {
		cout << i << ' ';
	}
}
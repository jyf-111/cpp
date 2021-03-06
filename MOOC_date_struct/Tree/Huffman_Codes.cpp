/*In 1953, David A. Huffman published his paper ??A Method for the Construction of Minimum-Redundancy Codes??, and hence printed his name in the history of computer science. As a professor who gives the final exam problem on Huffman codes,
I am encountering a big problem: the Huffman codes are NOT unique. For example, given a string ??aaaxuaxz??, we can observe that the frequencies of the characters ??a??, ??x??, ??u?? and ??z?? are 4, 2, 1 and 1, respectively. 
We may either encode the symbols as {??a??=0, ??x??=10, ??u??=110, ??z??=111}, or in another way as {??a??=1, ??x??=01, ??u??=001, ??z??=000}, both compress the string into 14 bits. Another set of code can be given as {??a??=0, ??x??=11, ??u??=100, ??z??=101},
but {??a??=0, ??x??=01, ??u??=011, ??z??=001} is NOT correct since ??aaaxuaxz?? and ??aazuaxax?? can both be decoded from the code 00001011001001. The students are submitting all kinds of codes, and I need a computer program to help me determine which ones are correct and which ones are not.

Input Specification:
Each input file contains one test case. For each case, the first line gives an integer N (2??N??63), then followed by a line that contains all the N distinct characters and their frequencies in the following format:

c[1] f[1] c[2] f[2] ?? c[N] f[N]

where c[i] is a character chosen from {??0?? - ??9??, ??a?? - ??z??, ??A?? - ??Z??, ??_??}, and f[i] is the frequency of c[i] and is an integer no more than 1000. The next line gives a positive integer M (??1000), then followed by M student submissions. Each student submission consists of N lines, each in the format:

c[i] code[i]

where c[i] is the i-th character and code[i] is an non-empty string of no more than 63 '0??s and '1??s.

Output Specification:
For each test case, print in each line either ??Yes?? if the student??s submission is correct, or ??No?? if not.

Note: The optimal solution is not necessarily generated by Huffman algorithm. Any prefix code with code length being optimal is considered correct.

Sample Input:

7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
4
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
A 000
B 001
C 010
D 011
E 100
F 101
G 110
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11

Sample Output:

Yes
Yes
No
No
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct input {
	char ch;
	int weight;
}in[100];//??ʼ???У?ȷ???ַ???Ƶ?ʣ?Ȩ?أ?
struct check {
	char ch;
	string code;
}ck[100];;//?ȴ???????????
bool cmp(check a,check b) {
	return a.code.size()<b.code.size();//???ȴ?С????????
}
int cnt(char ch,int N){//????ch?????ַ???ԭʼ?????е?λ??
	for(int i = 0;i<N;i++){
		if(in[i].ch==ch){
			return i;
		}
	}
	return -1;
}

bool frontSq(int n){//???????????ж??Ƿ?????????һ??string????????һ??string??ǰ׺
	sort(ck,ck+n,cmp);
	for(int i =0 ;i<n;i++){
		string temp = ck[i].code;
		for(int j =i+1;j<n;j++){
			if(ck[j].code.substr(0,temp.size())==temp)return true;
		}
	}
	return false;
}

int main()
{
	int N;
	cin >> N;//???ȶ??? ??С???󣬷??????ǹ??????????? ?ɽ?greater??Ϊless????Ϊ?Ӵ???С
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i = 0;i<N;i++){
		cin >>in[i].ch >> in[i].weight;
		q.push(in[i].weight);
	}
	int best = 0;//????????????WPL
	int m = 0;
	while(!q.empty()){
		int a = 0;
		int b = 0;
		a = q.top();
		q.pop();
		if(!q.empty()){
			b = q.top();
			q.pop();
			q.push(a+b);
		}
		m = a+b;
		best+=m;
	}
	best-=m;//m??????һ?Σ?cut??
    // ???ݻ????????Ĺ???????weight
	int t;
	cin >> t;
	while(t--){
		int cost=0;
		for(int j =0;j<N;j++){
			cin>>ck[j].ch>>ck[j].code;
			cost+=ck[j].code.size()*in[cnt(ck[j].ch,N)].weight;
		}
		if(cost==best){
			if(frontSq(N)){//????WPLһ????Ҫ??ǰ׺?ٴ??ж?
				printf("No\n");
			}else{
				printf("Yes\n");
			}
		}else{
			printf("No\n");
		}
	}
}
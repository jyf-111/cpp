/*
The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (��10
?4
?? ), the total number of users, K (��5), the total number of problems, and M (��10
?5
?? ), the total number of submissions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submission in the following format:

user_id problem_id partial_score_obtained
where partial_score_obtained is either ?1 if the submission cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:
For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -

PAT��ranklist����״̬�б����ɵģ�������ʾ���ύ�ķ�������һ�Σ���Ӧ��ΪPAT����ranklist��

������:
ÿ�������ļ�����һ����������������ÿ���������һ�а���3����������N(��104)���û�������K(��5)������������M(��10^5)���Լ��ύ��Ʒ��������Ȼ������û�id�Ǵ�00001��N��5λ���֣�������id�Ǵ�1��K�ġ���һ�а���K��������p[i] (i=1����������p[i]��Ӧ��i����������֡���������M�У�ÿһ�ж�������һ���ύ����Ϣ����ʽ����:

user_id problem_id partial_score_obtained

����partial_score_Ϊ- 1(����ύ��������ͨ��������)������Ϊ[0,p[problem_id]]��Χ�ڵ�������һ���е��������ֶ��ÿո������

����淶:
����ÿ��������������Ӧ�ð������¸�ʽ���ranklist:

user_id total_score s[1]��s [K]
1
���и���total_score����rank��������ͬtotal_score�������û������ͬ��rank;s[i]�ǵ�i������õ��Ĳ��ַ���������û���δ�ύ������Ľ�����������������Ӧλ�ô�ӡ��-��������û�Ϊ���һ�������ύ�˶�������������ô��������߷֡�

ranklist���밴�ȵķǵݼ�˳���ӡ�����ھ�����ͬ������û�������������������������������ǵ���˳�����������Ȼ�����������밴��id�ĵ���˳���ӡ��������Щ����û���ύ���κο���ͨ���������Ľ���������ˣ����ߴ���û���ύ���κν���������ˣ����ǲ�����ʾ��ranklist�ϡ����Ա�֤������һ���û�������ʾ��ranklist�ϡ�

��������:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0

�������:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 42
5 00004 40 15 0 25 -
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct result4a {
    int question[6];
    int total;
    int allRightNum;
    int ID;
    int flag;
};

bool compareAB(result4a a,result4a b) {
    if(a.total > b.total) return true;
    else if(a.total <b.total) return false;
    else {
        if(a.allRightNum > b.allRightNum) return true;
        else if(a.allRightNum <b.allRightNum) return false;
        else {
            if(a.ID<b.ID) return true;
            else return false;
        }
    }
}

int main()
{
    int N;//������
    int K;//������
    int M;//���ύ��
    cin >> N >> K >> M ;
    int QtotalScore[6];
    for(int i=1;i<=K;i++) {
        cin >> QtotalScore[i];
    }

    vector<result4a> myResult(N+1);
    for(int i=1;i<=N;++i) {
        myResult[i].ID = 100000;
        myResult[i].allRightNum = 0;
        myResult[i].total = 0;
        myResult[i].flag = 0;
        for(auto &j:myResult[i].question){
            j = -1;
        }
    }
    int stuID,qNum,qScore;
    for(int i = 0;i < M ; ++i ) {
        cin >> stuID >> qNum >> qScore;
        myResult[stuID].ID = stuID;
        if(-1 == qScore) {
            if(-1==myResult[stuID].question[qNum])
                myResult[stuID].question[qNum] = 0;
        }else{
            myResult[stuID].flag = 1;
            if(myResult[stuID].question[qNum] < qScore){
                if(myResult[stuID].question[qNum]==-1)
                    myResult[stuID].question[qNum] = 0;
                myResult[stuID].total+=qScore-myResult[stuID].question[qNum];
                myResult[stuID].question[qNum] = qScore;
                if(qScore == QtotalScore[qNum]) {
                    myResult[stuID].allRightNum++;
                }
            }	
        }
    }

    sort(myResult.begin()+1,myResult.end(),compareAB);

    int tempValue = myResult[1].total;
    int tempi = 1;
    for(int i=1; i<=N ;i++) {
        if(myResult[i].flag!=0) {
            if(myResult[i].total==tempValue);else {
                tempValue = myResult[i].total;
                tempi = i;
            }
            printf("%d %05d %d", tempi,myResult[i].ID, myResult[i].total);
            for(int j=1; j<=K ; ++j) {
                if(myResult[i].question[j] != -1) {
                    cout << " " << myResult[i].question[j];
                }else{
                    cout << " -";
                }
            }
            cout << endl;
        }
    }
}
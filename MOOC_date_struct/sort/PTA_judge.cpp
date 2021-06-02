/*
The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (≤10
?4
?? ), the total number of users, K (≤5), the total number of problems, and M (≤10
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

PAT的ranklist是由状态列表生成的，其中显示了提交的分数。这一次，您应该为PAT生成ranklist。

输入规格:
每个输入文件包含一个测试用例。对于每种情况，第一行包含3个正整数，N(≤104)，用户总数，K(≤5)，问题总数，M(≤10^5)，以及提交作品的总数。然后假设用户id是从00001到N的5位数字，而问题id是从1到K的。下一行包含K个正整数p[i] (i=1，…，其中p[i]对应第i个问题的满分。接下来是M行，每一行都给出了一个提交的信息，格式如下:

user_id problem_id partial_score_obtained

其中partial_score_为- 1(如果提交甚至不能通过编译器)，或者为[0,p[problem_id]]范围内的整数。一行中的所有数字都用空格隔开。

输出规范:
对于每个测试用例，您应该按照以下格式输出ranklist:

user_id total_score s[1]…s [K]
1
其中根据total_score计算rank，具有相同total_score的所有用户获得相同的rank;s[i]是第i个问题得到的部分分数。如果用户从未提交过问题的解决方案，则必须在相应位置打印“-”。如果用户为解决一个问题提交了多个解决方案，那么将计算最高分。

ranklist必须按秩的非递减顺序打印。对于具有相同级别的用户，必须根据完美解决的问题的数量按非递增顺序排序。如果仍然有领带，则必须按其id的递增顺序打印。对于那些从来没有提交过任何可以通过编译器的解决方案的人，或者从来没有提交过任何解决方案的人，他们不能显示在ranklist上。可以保证至少有一个用户可以显示在ranklist上。

样例输入:
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

样例输出:
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
    int N;//总人数
    int K;//总题数
    int M;//总提交数
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
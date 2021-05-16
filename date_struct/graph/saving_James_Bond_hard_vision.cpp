/*This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the diameter of 15. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him a shortest path to reach one of the banks. The length of a path is the number of jumps that James has to make.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (¡Ü100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:
For each test case, if James can escape, output in one line the minimum number of jumps he must make. Then starting from the next line, output the position (x,y) of each crocodile on the path, each pair in one line, from the island to the bank. If it is impossible for James to escape that way, simply give him 0 as the number of jumps. If there are many shortest paths, just output the one with the minimum first jump, which is guaranteed to be unique.

Sample Input 1:
17 15
10 -21
10 21
-40 10
30 -50
20 40
35 10
0 -10
-25 22
40 -40
-30 30
-10 22
0 11
25 21
25 10
10 10
10 35
-30 10
Sample Output 1:
4
0 11
10 21
10 35
Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
0
*/
 
#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

queue<int> Q;
int dist[102] ;
int path[102];

int N;//öùÓãÊý
int D;//×î´óÌøÔ¶

struct Node {
    int x,y;
    Node():x(0),y(0) { }
}Graph[102];

void Initgraph() {
    cin >> N >> D;
    for(int i=1 ; i<=N ; ++i) {
        cin >> Graph[i].x >> Graph[i].y;
    }
    for(auto &i:path){
        i = -1;
    }
    for(auto &i :dist){
        i = -1;
    }
}

bool isBorder(Node S) {
    if(D>=50-7.5) return true;
    int x = abs(S.x) + D;
    int y = abs(S.y) + D;
    if(x>=50 || y>=50) return true;
    else return false;
}

bool reach(Node s1,Node s2){
    if(s1.x==0 && s1.y==0){
        if(sqrt(pow(s2.x,2)+pow(s2.y,2)) <= D+15/2 ){
            
            return true;
        }else{
            return false;
        }
    }
    
    if(sqrt(pow(s1.x-s2.x,2)+pow(s1.y-s2.y,2)) <= D){
        
        return true;
    }else{
        return false;
    }
}

void unweighted() {
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()) {
        int temp = Q.front();
        Q.pop();

        for(int i=1; i<=N ; ++i) {
            if((abs(Graph[i].x)<=7.5 && abs(Graph[i].y)<=7.5) || (abs(Graph[i].x)>=50 && abs(Graph[i].y)>=50)){
                continue;
            }
            if(reach(Graph[temp],Graph[i]) && dist[i] == -1){
                dist[i] = dist[temp] +1;
                Q.push(i);
                path[i] = temp;
            }
        }
    }

}

int getfirst(int i){
    while(path[i]!=0) {
        i = path[i];
    }
    return dist[i];
}

void check() {
    int i;
    int minnum = 60000;
    int n;
    for( i=1 ; i<=N ;++i){
        if(isBorder(Graph[i]) && path[i]!= -1){
            dist[i]++;
            if(getfirst(i)<minnum){
                n = i;
                minnum = i;
            }
        }
    }
    if(minnum<60000)
        i = n;
    else 
        i = 0;
    cout << dist[i] << endl;
    if(i==0) return ;
    stack<int> S;
    S.push(i);
    while(path[i]!=0) {
        S.push(path[i]);
        i = path[i];
    }
    while(!S.empty()) {
        cout << Graph[S.top()].x << " " << Graph[S.top()].y << endl;
        S.pop();
    }
    
}
int main()
{
    Initgraph();
    if(D>=50-7.5){
        cout << "1";
        return 0;
    }
    unweighted();
    
    check();

    
}

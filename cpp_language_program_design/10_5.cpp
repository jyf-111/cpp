#include<iostream>
#include<queue>
#include<iterator>
using namespace std;

template<int m,int n>
int Joseph() {
    queue<int> q;
    for(int i=1 ; i<=n ; ++i ) {
        q.push(i);
    }
    while(q.size()>1){
        for(int i=0 ;i<m-1 ;i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    return q.front();
}

int main()
{
    cout << Joseph<5,10>();
}
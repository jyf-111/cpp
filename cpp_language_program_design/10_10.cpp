#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    set<int> s1,s2;
    while(1) {
        cin >> n;
        if(n==0)break;
        s1.insert(n);
    }
    while(1){
        cin >> n;
        if(n==0)break;
        s2.insert(n);
    }

    vector<int> result;
    //交集
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                    insert_iterator<vector<int> >(result,result.begin()));
    for(auto i:result) {
        cout << i << " ";
    }
    cout << endl;

    result.erase(result.begin(),result.end());
    //并集
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),
                    insert_iterator<vector<int> >(result,result.begin()));
    for(auto i:result) {
        cout << i << " ";
    }
    cout << endl;

    result.erase(result.begin(),result.end());
    //差集
    set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),
                    insert_iterator<vector<int> >(result,result.begin()));
    for(auto i:result) {
        cout << i << " ";
    }
    cout << endl;
}
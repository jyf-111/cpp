#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<list>
using namespace std;

int main()
{
    int array[] ={1,1,1,5,3,4,4,5,3};
    vector<int> s(array,array+sizeof(array)/sizeof(int));

    sort(s.begin(),s.end());//只能去重相邻，所以先排序

    auto p = unique(s.begin(),s.end());

    s.erase(p,s.end());

    copy(s.begin(),s.end(),ostream_iterator<int>(cout,"\t"));
    cout << endl;

    list<int> l(array,array+sizeof(array)/sizeof(int));
    l.sort();
    l.unique();
    
    copy(l.begin(),l.end(),ostream_iterator<int>(cout,"\t"));

}
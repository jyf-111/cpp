#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    int intArr[] = {30,90,10,40,70,50,20,80};
    const int N = sizeof(intArr)/sizeof(int);
    vector<int> a(intArr,intArr+N);

    copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\t"));
    cout << endl;

    sort(a.begin(),a.end(),greater<int>());
    copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\t"));
    cout << endl;

}
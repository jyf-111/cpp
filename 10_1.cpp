#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>

using namespace std;


int main()
{
    const int N = 5;
    vector<int> s(N);

    for(auto &si:s) {
        cin >> si;
    }

    transform(s.begin(),s.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout << endl;
    return 0;
}
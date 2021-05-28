#include<iostream>
#include<set>
#include<iterator>
#include<utility>
using namespace std;

int main()
{
    set<double> s;
    while(true) {
        double v;
        cin >> v;
        if( v==0 ) break;
        auto r = s.insert(v);
        if(!r.second) {
            cout << v << " is duplicated" << endl;
        }
    }
    auto iter1 = s.begin();
    auto iter2 = s.end();
    double medium = (*iter1 + *(--iter2)) / 2;

    cout << "<=medium: " ;
    copy(s.begin(),s.upper_bound(medium),ostream_iterator<double>(cout,"\t"));
    cout << endl;

    cout << ">=medium: ";
    copy(s.lower_bound(medium),s.end(),ostream_iterator<double>(cout,"\t"));
    cout << endl;
    return 0;
}
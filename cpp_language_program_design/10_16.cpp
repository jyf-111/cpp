#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

template<class InputIt ,class OutputIt>
void mySort(InputIt first,InputIt last,OutputIt result) {

    sort(first,last);
}

int main()
{
    double a[5] = {1.2,2.4,0.8,3.3,3.2};
    vector<double> s(a,a+5);
    //mySort(a,a+5,ostream_iterator<double>(cout," "));

    mySort(s.begin(),s.end(),s.begin());cout << endl;
    copy(s.begin(),s.end(),ostream_iterator<double>(cout,"\t"));
    cout << endl;

    //mySort(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));
    
    cout << endl;
    return 0;
}
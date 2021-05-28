#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
    int iarray[] = {26,17,15,22,23,33,32,40};
    vector<int>ivector(iarray,iarray+sizeof(iarray)/sizeof(int));

    vector<int>::iterator p = max_element(ivector.begin(),ivector.end());
    int n = p-ivector.begin();
    cout << "max element : " << *p << " found at " << n << endl;

    vector<int>ivector1(5);
    partial_sort_copy(ivector.begin(),ivector.end(),ivector1.begin(),ivector1.end());
    copy(ivector1.begin(),ivector1.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    sort(ivector.begin(),ivector.end());
    copy(ivector.begin(),ivector.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    cout << *lower_bound(ivector.begin(),ivector.end(),15) << endl;
    cout << *upper_bound(ivector.begin(),ivector.end(),32) << endl;

    cout << binary_search(ivector.begin(),ivector.end(),33) << endl;

    vector<int>ivector2(13);
    merge(ivector.begin(),ivector.end(),ivector1.begin(),ivector1.end(),ivector2.begin());
    copy(ivector2.begin(),ivector2.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    nth_element(ivector2.begin(),ivector2.begin()+5,ivector2.end());
    copy(ivector2.begin(),ivector2.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    stable_sort(ivector2.begin(),ivector2.end());
    copy(ivector2.begin(),ivector2.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int iarray3[] = {1,3,5,7,2,4,6,8};
    vector<int>ivector3(iarray3,iarray3+sizeof(iarray3)/sizeof(int));
    inplace_merge(ivector3.begin(),ivector3.begin()+4,ivector3.end());
    copy(ivector3.begin(),ivector3.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int iarray4[] = {1,3,5,7,1,5,9,3};
    vector<int>ivector4(iarray4,iarray4+sizeof(iarray4)/sizeof(int));
    cout << lexicographical_compare(ivector3.begin(),ivector3.end(),ivector4.begin(),ivector4.end()) << endl;

    return 0;
}
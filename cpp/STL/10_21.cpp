#include<iostream>
#include<numeric>
#include<functional>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
    int iarray[] = {1,2,3,4,5};
    vector<int> ivector(iarray,iarray+sizeof(iarray)/sizeof(int));

    cout << accumulate(ivector.begin(),ivector.end(),0) << endl;
    cout << inner_product(ivector.begin(),ivector.end(),ivector.begin(),0) << endl;
    partial_sum(ivector.begin(),ivector.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    adjacent_difference(ivector.begin(),ivector.end(),ostream_iterator<int>(cout," "));

}

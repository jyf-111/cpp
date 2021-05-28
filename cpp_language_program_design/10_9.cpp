#include<iostream>
#include<iterator>
using namespace std;

int main()
{
    int iarray1[] = {1,2,3,4,5};
    int iarray2[] = {6,7,8,9,10};

    swap(iarray1,iarray2);

    copy(iarray1,iarray1+sizeof(iarray1)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(iarray2,iarray2+sizeof(iarray2)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;


    iter_swap(iarray1,iarray2);
    copy(iarray1,iarray1+sizeof(iarray1)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(iarray2,iarray2+sizeof(iarray2)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;

    swap_ranges(iarray1,iarray1+sizeof(iarray1)/sizeof(int),iarray2);
    copy(iarray1,iarray1+sizeof(iarray1)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;
    copy(iarray2,iarray2+sizeof(iarray2)/sizeof(int),ostream_iterator<int>(cout," "));
    cout << endl;
}
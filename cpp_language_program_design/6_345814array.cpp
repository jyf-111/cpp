#include<iostream>
using namespace std;

int main()
{
    int array[] = {1,2,3,4,5};
    for(auto i : array) {
        cout << i << endl;
    }
    cout << sizeof(array)/sizeof(int) << endl;
    int myarray[5][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9},
                        {10,11,12},
                        {13,14,15}};

    for(auto &i:myarray) {
        for(auto j:i) {
            cout << j << " ";
            if(j%3==0){
                cout << endl;
            }
        }
    }

    int *p = new int [10];
    int a = 5.5;
    int *b = &a;
    cout << "double * = " << sizeof(b) << endl;
    cout << "double a = " << sizeof(*b) << endl;
}
#include<iostream>
#include<array>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    array<double,4> a{1.23,35.36,653.7};

    array<string,4> s{"jiang","yu","feng","!!!!!!"};

    cout.fill('*');
    //cout.width(10);
    for(auto i:a){
        cout.width(10);
        cout << i << endl;
    }

    for(auto i = 0; i<4 ; ++i) {
        cout << setw(6) << s[i] << setw(10) << a[i] << endl;
    }

    for(auto i = 0; i<4 ; ++i) {
        cout<< setw(6) << setiosflags(ios_base::left) << s[i] 
        << setw(10) << resetiosflags(ios_base::left) << a[i] << endl;
    }

    double x = 3466.9768;

    cout << setiosflags(ios_base::fixed) << x << resetiosflags(ios_base::fixed)<<endl;
    //cout << setiosflags(ios_base::scientific)<< x << resetiosflags(ios_base::scientific)<< endl;
    cout << setprecision(1) << x << endl;   
}
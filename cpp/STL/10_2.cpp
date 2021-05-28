#include<iostream>

#include<iterator>
#include<algorithm>


using namespace std;

double square(double x) {
    return x*x;
}

int main()
{
    transform(istream_iterator<double>(cin),istream_iterator<double>(),
                ostream_iterator<double>(cout,"\t"),square);
    cout << endl;
    return 0;
}
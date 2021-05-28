#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<iterator>
using namespace std;

struct randnum {
    int operator() ( ) { return rand()%10 ; }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));
    
    vector<int> s(30);
    generate(s.begin(),s.end(),randnum());
    copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
}
#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<iterator>
using namespace std;

class cal {
private:
    int x,y;
public:
    cal(int _x=0,int _y=0) : x(_x),y(_y) { }
    int calculate() {
        int sum = 1;
        for(int i=0 ; i<y ; ++i) {
            sum *= x;
        }
        return sum;
    }

};

int op(int n) {
    cout << "5^n: " << cal(5,n).calculate() << endl;
    cout << "n^7: " << cal(n,7).calculate() << endl;
    cout << "n^n: " << cal(n,n).calculate() << endl;
    cout << endl;
    return n;
}

struct randnum {
    int operator() ( ) { return rand()%10 ; }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));
    
    vector<int> s(30);
    generate(s.begin(),s.end(),randnum());
    copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));

    transform(s.begin(),s.end(),s.begin(),op);
}
#include<iostream>
#include<list>
#include<deque>
#include<iterator>
using namespace std;

template<class T>
void printContainer(const char* msg,const T& s) {
    cout << msg << ": ";
    copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main()
{
    deque<int> s;
    for(int i=0 ; i<10 ; ++i ){
        int x;
        cin >> x;
        s.push_front(x);
    }
    printContainer("deque at first",s);

    list<int> l(s.rbegin(),s.rend());
    printContainer("list at first",l);

    list<int>::iterator iter = l.begin();
    while(iter != l.end()) {
        int v = *iter;
        iter = l.erase(iter);
        l.insert(++iter,v);
    }
    printContainer("list at last",l);

    s.assign(l.begin(),l.end());
    printContainer("deque at last",s);
    return 0;
}
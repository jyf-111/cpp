#include<iostream>
#include<list>
#include<iterator>
#include<string>
using namespace std;

int main()
{
/*
    list<int> ilist{1,2,3};
//push_front
    ilist.push_front(-100);
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;

    for(int i=0 ; i < 4 ;i++){
        ilist.push_front( i );
    }
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;
//下面的操作相当于push_front (c++11)
    auto iter = ilist.begin();
    for( int i = 0 ; i < 4 ; i++){
        iter = ilist.insert( iter , i );
    }
    for(auto &i : ilist){
        cout << i << " ";
    }
    cout << endl;
*/
    string names1[] = {"Alice","Helen","Lucy","Susan"};
    string names2[] = {"Bob","David","Levin","Mike"};
    list<string>s1(names1,names1+4);
    list<string>s2(names2,names2+4);

    s2.splice(s2.end(),s1,s1.begin());
    list<string>::iterator iter1 = s1.begin();
    advance(iter1,2);
    list<string>::iterator iter2 = s2.begin();
    ++iter2;
    list<string>::iterator iter3 = iter2;
    advance(iter3,2);
    s1.splice(iter1,s2,iter2,iter3);

    copy(s1.begin(),s1.end(),ostream_iterator<string>(cout,"\t"));
    cout << endl;
    copy(s2.begin(),s2.end(),ostream_iterator<string>(cout,"\t"));
    cout << endl;
}
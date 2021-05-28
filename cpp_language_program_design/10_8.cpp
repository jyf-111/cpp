#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;

int main()
{
    /*
    multiset<string> ms;
    string s;
    do {
        cin >> s;
        ms.insert(s);
        cout << ms.count(s) << endl;
    }while(s != ".");  
    */
   map<string,int> m;
   string s;
   do {
       cin >> s;
       if(m.find(s)==m.end()){
           cout << "no" << endl;
           m.insert(make_pair(s,1));
       }else{
           cout << ++m.find(s)->second << endl;
       }
  
   }while(s!=".");  
}
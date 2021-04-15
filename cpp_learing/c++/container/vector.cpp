#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
//直接初始化
    vector<int> v1(10,1);
    v1 = {1,2,3,4,5,6,7,8,9};
    vector<int> v2{9,8,7,6,5};
/*    int i=0;
    for(auto &i : v1){
        cout << i << ' ';
    }
    cout << endl;
//Push_back
    while ( cin >> i ){
        v2.push_back( i );
    }
    for(auto &i : v2){      //如果循环里有push_back则不能使用基于范围的for循环
        cout << i << ' ';
    }

//迭代器
    for(auto i = v1.begin() ; i != v1.end() ; i++){
        cout << *i << ' ';
    }
    cout << endl;

//二分搜索
    auto beg = v1.cbegin() , end  =v1.cend();
    auto mid = (end - beg)/2 + v1.cbegin() ;
    while(mid != end ){
        if(*mid < 3){
            beg = mid+1;
        }else{
            end = mid;
        }
        if(*mid == 3){
            cout << mid - v1.cbegin() ;
            break;
        }
        mid = beg + (end - beg) / 2 ;
    }*/
//insert
    v1.insert(v1.begin(),{1,2,3});
    for( auto &i : v1 ){
        cout << i << " ";
    }
    cout << endl;

    v1.insert(v1.begin()+3,v2.begin()+1,v2.begin()+3);
    for(auto &i : v1){
        cout<< i << " ";
    }
    cout << endl;

}
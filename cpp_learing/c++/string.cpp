#include<iostream>
#include<string>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string word(10,'c');
    
    const char ch = 'c' ;
    cin >> word ;
    cout << word << endl ;
//无限次读入单词
    while( cin >> word ){
        cout << word << endl ;
    }
//无限次读入行
    while(getline(cin,word)){
        if(!word.empty()&&word.size() > 5)
        cout << word << endl ;
    }
//cctype函数库的使用
    cout << isalnum(ch) << endl ;
//基于范围的for循环遍历字符串(判断并修改)
    word += ",,,";
    for( auto &i : word ){

        i = toupper ( i ) ;

        if(ispunct(i)){
        i = 'f' ;
        cout << i << endl ;
        }
    }
    word[ 1 ] = 'N' ;
    cout << word << endl ;
    
//十进制转十六进制
    const string hexdigits("0123456789ABCDEF");
    cout << hexdigits.size() << endl;
    decltype(hexdigits.size()) n;//string::size_type
    string result;
    while( cin >> n ){
        if( n < hexdigits.size()){
            result += hexdigits[n];
        }
    }
    cout << result << endl ;
//insert
    word.insert(word.begin(),'f');
    cout << word << endl;
    return 0 ;
}
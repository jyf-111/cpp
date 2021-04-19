/*中缀表达式*/
/*无括号中缀表达式求值，以#结束*/
#include<iostream>
#include<stack>
using namespace std;

int Compare(const char top,const char ch) {
    int flag = 0;
    if(top=='='){
        flag = -1;
    }
    if(ch=='=') {
        flag = 1;

        return flag;
    }
    if((top=='+'||top=='-')&&(ch=='*'||ch=='/')){
        flag = -1;
    }
    if((top=='*'||top=='/')&&(ch=='+'||ch=='-')){
        flag = 1;
    }
    return flag;
}

int Execute(const int a,const char op,const int b) {
    int result = 0; 
    switch(op) {
        case '+': result = a+b;break;
        case '-': result = a-b;break;
        case '*': result = a*b;break;
        case '/': result = a/b;break;
        default : break;
    }
    return result;
}
int main()
{
    stack<char> OPTR;//运算符
    stack<int> OVS;//操作数
    OPTR.push('=');/*为了操作方便，先压入#*/
    char ch;
    ch = getchar();
    while(ch != '='||OPTR.top()!='=' ) {
        if(ch == '+'||ch=='-'||ch=='*'||ch=='/'||ch=='=') {
            //是操作符
            switch(Compare(OPTR.top(),ch)) {
                case -1: 
                    OPTR.push(ch);  
                    //cout << "OPTR top is "<<OPTR.top()<< endl;
                    ch = getchar();    
                    break;
                case 0:
                case 1:  
                    int b = OVS.top();
                    OVS.pop();
                    int a = OVS.top();
                    OVS.pop();
                    char op = OPTR.top();
                    OPTR.pop();
                    OVS.push(Execute(a,op,b));//a比b先进栈
                    break;
            }
        }else{
            //是操作数
            OVS.push(ch-'0');
            //cout << "OVS top is" << OVS.top() << endl;
            
            ch = getchar();
        }
    }
    cout << OVS.top() << endl;
    
    return 0;
}
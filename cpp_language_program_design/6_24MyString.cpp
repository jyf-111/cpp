#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
private:
    char* p;
    int len;
public:
    MyString( );
    MyString(int n);
    MyString(const char* temp);
    MyString(const MyString& a);
    ~MyString( );
    char& operator[](int n);
    MyString& operator=(const MyString& a);
    MyString operator+(const MyString& a);
    MyString& operator+= (const MyString& a);
    void Getlen() { cout << "len: " << len << endl;}
    void ShowString() {
        int i = 0;
        while(p[i]) {
            cout << p[i];
            i++;
        }
        cout << endl;
    }
};

MyString::MyString () {
    p = new char[1];
    p[0] = '\0';
    len = 0;
}
MyString::MyString (int n) {
    len = n;
    p = new char[n+1];
    for(int i = 0 ; i<=n ;++i) {
        p[i] = '\0';
    }
}

MyString::MyString (const char* temp) {
    int i;
    len = strlen(temp);
    p = new char[len+1];
    for(i=0; i<len ;++i) {
        p[i] = temp[i];
    }
    p[i] = '\0';
}

MyString::MyString(const MyString& a) {
    len = a.len;
    int i;
    p = new char[len+1];
    for(i = 0; i<len ; ++i) {
        p[i] = a.p[i];
    }
    p[i] = '\0';
}

MyString::~MyString() {
    delete []p;
    len = 0;
}

char& MyString::operator[](int n) {
    return p[n];
}

MyString& MyString::operator=(const MyString& a) {
    delete []p;
    len = a.len;
    p = new char [len+1];
    int i;
    for( i=0 ; i<len ; ++i) {
        p[i] = a.p[i];
    }
    p[i] = '\0';
    return *this;
}

MyString MyString::operator+(const MyString& a) {
    int total = len + a.len;
    MyString temp(total);
    int i;
    for(i=0 ; i<len ; ++i) {
        temp[i] = p[i];
    }
    for(int j=0;j<a.len;i++,j++) {
        temp[i] = a.p[j];
    }
    temp[i] = '\0';
    return temp;
}

MyString& MyString::operator+= (const MyString& a) {
    int total = len + a.len;
    MyString temp(total);
    int i;
    for(i=0 ; i<len ; ++i) {
        temp[i] = p[i];
    }
    for(int j=0;j<a.len;i++,j++) {
        temp[i] = a.p[j];
    }
    temp[i] = '\0';
    *this = temp;
    return *this;
}

int main() {
    MyString str1("Hello");
    cout << "str1: " << endl;
    str1.Getlen();
    str1.ShowString();

    MyString str2("world");
    cout << "str2:" << endl;
    str2.Getlen();
    str2.ShowString();

    MyString str3;
    cout << "str3 = str1 + str2 : " << endl;
    str3 = str1 + str2;
    str3.Getlen();
    str3.ShowString();

    MyString str4;
    cout << "str4 = str3" << endl;
    str4 = str3;
    str4.Getlen();
    str4.ShowString();

    return 0;
}


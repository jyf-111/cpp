#include<iostream>
#include<string>
using namespace std;

class document
{
private:
    string name;
public:
    document(string s) : name(s) { }
    void get() const { cout <<  &name << endl ;}
    ~document() {}
};

class Book : public document
{
private:
    int pageCount;
public:
    Book(int c) : document(" "), pageCount(c) {}
    void get() const { cout << this << endl<< &pageCount << endl ;}
    ~Book() {}
};

int main()
{
    Book b(100);
    document *p = &b;
    p->get();
}
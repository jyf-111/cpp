#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
    string name;
    string address;
    string city;
    int post;
public:
    Employee(/* args */):address("dasda"),city("sacc"),post(241) {}
    void setName(const string &s){
        name.erase();
        name.append(s);
    }
    void show() const {
        cout << name << endl
            << address << endl
            << city << endl
            << post;
    }
    ~Employee() {}
};

int main()
{
    Employee e;
    e.setName("wo");
    e.show();
}
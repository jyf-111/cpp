#include<iostream>
#include<string>
using namespace std;

class Cat {
private:
    string name;
    int age;
    static int numOfCats;
public:
    static void getNumOfCats() {
        cout << numOfCats << endl;
    }
};
int Cat::numOfCats = 10 ;

int main()
{
    Cat c;
    c.getNumOfCats();
}
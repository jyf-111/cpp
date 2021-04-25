#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct SalaryInfo {
    unsigned id;
    double salary;
};

int main()
{
    SalaryInfo employee1 = {6000001,8000};
    ofstream os("File1.txt",ios_base::out|ios_base::binary);
    os.write(reinterpret_cast<char*>(&employee1),sizeof(employee1));
    os.close();

    ifstream is("File1.txt",ios_base::in|ios_base::binary);
    if(is) {
        SalaryInfo employee2;
        is.read(reinterpret_cast<char*>(&employee2),sizeof(employee2));
        cout<<employee2.id << employee2.salary << endl;
    }else{
        cerr <<"Error" << endl;
    }
    is.close();
    return 0;
}
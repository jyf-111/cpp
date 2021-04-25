#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Date{
    int monday,day,year;
};

int main()
{
    cout.put('A');//精确输出
    Date dt = {6,10,92};
    string s = "hello world";
    ofstream myFile;//定义一个静态文件输出流对象
    myFile.open("File1.txt",ios_base::out);
        myFile.write(reinterpret_cast<char*>(&dt),sizeof(dt));
    myFile.close();

    string Filename = "File2.txt";
    myFile.open(Filename,ios_base::app);
        myFile.write(s.c_str(),sizeof(s));

    myFile.close();

}
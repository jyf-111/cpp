#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Date{
    int monday,day,year;
};

int main()
{
    cout.put('A');//��ȷ���
    Date dt = {6,10,92};
    string s = "hello world";
    ofstream myFile;//����һ����̬�ļ����������
    myFile.open("File1.txt",ios_base::out);
        myFile.write(reinterpret_cast<char*>(&dt),sizeof(dt));
    myFile.close();

    string Filename = "File2.txt";
    myFile.open(Filename,ios_base::app);
        myFile.write(s.c_str(),sizeof(s));

    myFile.close();

}
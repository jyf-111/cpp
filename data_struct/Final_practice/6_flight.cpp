/*1．	订票系统
功能要求：
（1）录入：可以录入航班情况，数据可以存储在一个数据文件中，数据结构自定；
（2）查询：可以查询某个航线的情况（如，输入航班号，查询起降时间，起飞抵达城市，航班票价，票价折扣，确定航班是否满仓）；可以输入起飞抵达城市，查询飞机航班情况；
（3）订票：（订票情况可以存在一个数据文件中，结构自己设定）可以订票，如果该航班已经无票，可以提供相关可选择航班；
（4）退票： 可退票，退票后修改相关数据文件；客户资料有姓名，证件号，订票数量及航班情况，订单要有编号。
（5）修改航班信息：当航班信息改变可以修改航班数据文件
请根据以上功能要求，设计航班信息，订票信息的存储结构，设计程序完成功能；
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;

struct Time {
    int hour;
    int minute;
    Time() = default;
    Time(int a,int b) : hour(a),minute(b) { }
    void Print() const {  cout.width(2) ;cout.fill(0);cout<<hour << ":";cout.width(2) ;cout.fill(0);cout << cout.width(2) << cout.fill(0)<< minute ;}
};

struct Flight {
    int num;
    Time upTime;
    Time downTime;
    char pos[20];
    char target[20];
    int price;
    int off;
    bool isFull;
    Flight() : upTime(0,0), downTime(0,0) {}
};

void Read(deque<Flight> &S) {
    
    FILE* fp = fopen("./data.txt","r");
    for(int i=0 ;!feof(fp);i++){
        Flight f;
        fscanf(fp,"%d %d %d %d %d %s %s %d %d %d",
            &f.num,&f.upTime.hour,&f.upTime.minute,&f.downTime.hour,&f.downTime.minute,f.pos,f.target,
            &f.price,&f.off,&f.isFull);
        S.push_back(f);

    cout << "["<<i << "]";
    }
    fclose(fp);
    //cout << "readeof" << endl;
    //cout << S.top().num;
}

void Print(deque<Flight> S) {
    while (!S.empty())
    {
        Flight f;
        f = S[0];
        S.pop_front();
        cout << f.num << " ";
        f.upTime.Print() ;cout<<" ";
        f.downTime.Print() ; cout<< " ";
        cout << f.pos << " ";
        cout << f.target << " ";
        cout << f.price << " ";
        cout << f.off << " ";
        cout << boolalpha<<f.isFull << endl;;
        cout << "-------------" << endl;
    }
    
}

void Find(deque<Flight> &S) {
    cout << "find in num : ";
    int num;
    cin >> num;
    for(int i=0 ;i<S.size();i++) {
        if(num == S[i].num) {
        Flight f = S[i];
        cout << f.num << " ";
        f.upTime.Print() ;cout<<" ";
        f.downTime.Print() ; cout<< " ";
        cout << f.pos << " ";
        cout << f.target << " ";
        cout << f.price << " ";
        cout << f.off << " ";
        cout << boolalpha<<f.isFull << endl;;
        cout << "-------------" << endl;
        break;
        }
    }
}

int main()
{
    deque<Flight> S;
    Read(S);
    Print(S);
    Find(S);
}
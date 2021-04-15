#include<iostream>
#include<cmath>
using namespace std;

class SavingsAccount { //储蓄类账户
 private:
    int id; //账号
    double balance; //余额
    double rate;    //年利率
    int lastDate;   //上次变更余额日期
    double accumulation;    //余额按日累加之和
    void record(int date,double amount);    //记录一笔账
    double accumulate(int date)const {    //获得到指定日期为止的存款金额累计值
        return accumulation + balance*(date-lastDate);
    }
 public:
    SavingsAccount(int date,int id,double rate);
    int getId() {return id;}
    double getBalance() {return balance;}
    double getRate() {return rate;}
    void deposit(int date,double amount);
    void withdraw(int date,double amount);
    void steele(int date);//结算利息，每年1月1日调用一次该函数
    void show();//显示账户信息
};

SavingsAccount::SavingsAccount(int date,int id,double rate) 
: id(id),balance(0),rate(rate),lastDate(date),accumulation(0) {

} 
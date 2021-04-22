#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
class SavingsAccount { //储蓄类账户
 private:
    int id; //账号
    double balance; //余额
    double rate;    //年利率
    int lastData;   //上次变更余额日期
    double accumulation;    //余额按日累加之和
    void record(int data,double amount);    //记录一笔账
    double accumulate(int data)const {    //获得到指定日期为止的存款金额累计值
        return accumulation + balance*(data-lastData);
    }
 public:
    SavingsAccount(int data,int id,double rate);
    int getId() {return id;}
    double getBalance() {return balance;}
    double getRate() {return rate;}
    void deposit(int data,double amount);
    void withdraw(int data,double amount);
    void settle(int data);//结算利息，每年1月1日调用一次该函数
    void show();//显示账户信息
};
#endif
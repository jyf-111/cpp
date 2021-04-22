#include<iostream>
#include<cmath>
#include"SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(int data,int id,double rate) 
: id(id),balance(0),rate(rate),lastData(data),accumulation(0) {
    cout << data << "\t#" << id << "\tis created" << endl;
} 

void SavingsAccount::record(int data,double amount) {
    accumulation = accumulate(data);
    lastData = data;
    amount = floor(amount*100+0.5)/100;//保留两位小数
    balance+=amount;
    cout << data << "\t#" << id << "\t" << amount <<"\t" << balance <<endl;
}

void SavingsAccount::deposit(int data,double amount) {
    record(data,amount);
}

void SavingsAccount::withdraw(int data,double amount) {
    if(amount > balance) {
        cout << "Error : no enough money" << endl;
    }else {
        record(data,-amount);
    }
}

void SavingsAccount::settle(int data) {
    double interest = accumulate(data)*rate/365;    //计算年利
    if(interest != 0) {
        record(data,interest);
    }
    accumulation = 0;
}
void SavingsAccount::show() {
    cout << "#" << id << "\tbalance: " << balance << endl;
}
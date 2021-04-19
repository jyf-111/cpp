#pragma once
#include<iostream>
#include<string>
class Date{
private:
  int year = 2019 , month = 1 , day = 1;
public:
  int getYear() { return year;}
  int getMonth(){ return month;}
  int getday() {return day; }
  void setYear(int y){year = y; }
  void setMonth(int m){month = m; }
  void setDay(int d){day = d;}
  Date() = default;
  Date(int y,int m,int d):year{y},month{m},day{d}{}
  std::string toString(){
    return (std::to_string(year)+"-"+std::to_string(month)+"-"+std::to_string(day));
  }
};

enum class Gender{
    male,
    female,
};
class Employee{
private:
    std::string name;
    Gender gender;
    Date* birthday;
    static int num;
public:
    void setName(std::string name_){name=name_;}
    void setGender(Gender gender){this->gender = gender;}
    void setBirthday(Date birthday){*(this->birthday) = birthday; }
    std::string getName() {return name;}
    Gender getGender(){return gender;}
    Date getBirthday(){ return *birthday ;}
    std::string toString() {
        return ( name +((gender==Gender::male?std::string(" male ") :std::string(" female "))+birthday->toString()));
    }
    Employee(std::string name,Gender gender ,Date birthday):name{name},gender{gender}{
      num++;
      this->birthday= new Date {birthday};
    }
    Employee():Employee("Alan",Gender::male,Date(2000,4,1)){}
    ~Employee(){
      num--;
      delete birthday;
      birthday=nullptr;
    }
};
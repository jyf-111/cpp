#include<iostream>
#include<string>
using namespace std;

enum class Gender {male ,female};
class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() : year(1990),month(1),day(1) { }
    Date(int year,int month,int day) : Date() {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void printDate()const { cout << year <<"-"<<month<<'-'<<day<<'-'; }
};
class Person {
private:
    string num;
    Gender gender;
    Date date;
    string ID;
public:
    Person(): gender(Gender::male) { }
    ~Person() { }
    Person(Person &P);
    Person(string num = nullptr,Gender gender= Gender::male,Date date = {1990,1,1} ,string ID = nullptr) {
        this->num = num;
        this->gender = gender;
        this->date = date;
        this->ID = ID;
    }
    void printPerson() const;
};

Person::Person(Person &P){
    swap(num,P.num);
    swap(gender,P.gender);
    swap(date,P.date);
    swap(ID,P.ID);
}

inline void Person::printPerson() const {
    cout << num << endl;
    cout << (gender==Gender::male?"male":"female") << endl;
    date.printDate();
    cout << endl;
    cout << ID << endl;
}

int main()
{

    Date d{2002,04,10};
    Person P ("100001",Gender::female,d,"3202112132423");
    P.printPerson();
}
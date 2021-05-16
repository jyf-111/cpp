#include<iostream>
using namespace std;

class DataType {
private:
    enum Type {INT,CHAR,FLOAT};
    union Data { 
        int i;
        char c;
        float f;
    };
    Type type : 2 ;
    Data data ;
public:
    DataType(int i) {
        type = INT;
        data.i = i;
    }
    DataType(char c) {
        type = CHAR;
        data.c = c;
    }
    DataType(float f) {
        type = FLOAT;
        data.f = f;
    }
    void show() const ;
};
inline void DataType::show() const {
    switch (type)
    {
    case INT:
        cout << data.i << endl;
        break;
    case CHAR:
        cout << data.c << endl;
        break;
    case FLOAT:
        cout << data.f << endl;
        break;
    default:
        break;
    }
}

int main()
{
    DataType a('c');
    a.show();
    DataType b(960);
    b.show();
    DataType c(265.26f);
    c.show();
}
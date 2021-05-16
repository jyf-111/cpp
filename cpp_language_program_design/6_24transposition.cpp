#include<iostream>
using namespace std;
typedef int ElementType;

void transpostion(ElementType** A,int dimension) {
    for(int i=0 ; i<dimension ; ++i) {
        for(int j=0 ; j<i ; ++j) {
            swap(A[i][j] , A[j][i]);
        }
    }
}

int main() {
    ElementType** A;
    A = new ElementType* [3];
    for(int i=0 ; i<3 ; ++i) {
        A[i] = new ElementType [3];
    }
    for(int i=0 ; i<3; ++i) {
        for(int j=0 ; j<3 ; ++j) {
            A[i][j] = i;
        }
    }
    for(int i=0 ; i<3; ++i) {
        for(int j=0 ; j<3 ; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;
    transpostion(A,3);

    for(int i=0 ; i<3; ++i) {
        for(int j=0 ; j<3 ; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i=0 ;i<3 ;i++){
        delete [] A[i];
    }
    delete []A;
}
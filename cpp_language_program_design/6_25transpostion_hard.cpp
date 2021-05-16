#include<iostream>
using namespace std;
typedef int ElementType;

ElementType** transpostion(ElementType** A,int row,int col) {
    ElementType** B;
    B = new ElementType* [col];
    for(int i=0 ; i<col ; ++i) {
        B[i] = new ElementType [row];
    }
    for(int i=0 ; i<row; ++i) {
        for(int j=0 ; j<col ; ++j) {
            B[j][i] = A[i][j];
        }
    }

    for(int i=0 ;i<3 ;i++){
        delete [] A[i];
    }
    delete []A;

    return B;
}

int main() {
    int row,col;
    cin >> row >> col;
    ElementType** A;
    A = new ElementType* [row];
    for(int i=0 ; i<row ; ++i) {
        A[i] = new ElementType [col];
    }
    for(int i=0 ; i<row; ++i) {
        for(int j=0 ; j<col ; ++j) {
            A[i][j] = i;
        }
    }
    for(int i=0 ; i<row; ++i) {
        for(int j=0 ; j<col ; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;
    ElementType **B;
    B = transpostion(A,row,col);

    for(int i=0 ; i<col; ++i) {
        for(int j=0 ; j<row ; ++j) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i=0 ;i<col ;i++){
        delete [] B[i];
    }
    delete []B;
}
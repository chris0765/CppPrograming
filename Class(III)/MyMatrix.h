#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

#include <iostream>
#include <string>

using namespace std;

class myMatrix{
public:
    myMatrix(int nRows = 1, int nCols = 1);
    myMatrix(int nRows, int nCols, int initValue);
    myMatrix(int nRows, int nCols, int *data);
    myMatrix(int nRows, int nCols, int **data);

    myMatrix(const myMatrix& mat);

    ~myMatrix();

    int getRows() const;
    int getCols() const;
    int* operator [](int i) const;
    int& operator ()(int i, int j) const;

    myMatrix operator +(const myMatrix& mat) const;
    myMatrix operator -(const myMatrix& mat) const;
    myMatrix operator *(const myMatrix& mat) const;
    myMatrix operator *(int value) const;
    friend myMatrix operator *(int value, const myMatrix& mat);

    myMatrix& operator =(const myMatrix& mat);
    myMatrix& operator +=(const myMatrix& mat);
    myMatrix& operator -=(const myMatrix& mat);
    myMatrix& operator *=(const myMatrix& mat);
    myMatrix& operator *=(int value);

    bool operator ==(const myMatrix& mat) const;
    bool operator !=(const myMatrix& mat) const;
    
    myMatrix operator -() const;

    myMatrix& transpose();

    friend ostream& operator <<(ostream& outStream, const myMatrix& mat);
    friend istream& operator >>(istream& inStream, myMatrix& mat);

private:
    int rows;
    int cols;
    int **pData;

    void allocateMemory();
    void deleteMemory();
    void errorMessage(string msg) const;
};

#endif
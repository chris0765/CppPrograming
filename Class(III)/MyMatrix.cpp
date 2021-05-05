#include "MyMatrix.h"

myMatrix::myMatrix(int nRows, int nCols):rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
}
myMatrix::myMatrix(int nRows, int nCols, int initValue):rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data):rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i*cols+j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data):rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i][j];
}
myMatrix::~myMatrix(){
    if(pData!=NULL)
        deleteMemory();
}
myMatrix::myMatrix(const myMatrix& mat):rows(mat.rows), cols(mat.cols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = mat.pData[i][j];
}
int myMatrix::getRows() const{
    return rows;
}
int myMatrix::getCols() const{
    return cols;
}
int* myMatrix::operator [](int i) const{
    if((i<0)||(i>=rows))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i];
}
int& myMatrix::operator ()(int i, int j) const{
    if((i<0)||(i>=rows)||(j<0)||(j>=cols))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i][j];
}
myMatrix myMatrix::operator +(const myMatrix& mat) const{
    if((rows!=mat.rows)||(cols!=mat.cols))
        errorMessage("cannot add two matrices of different size");
    myMatrix tmp(*this);
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            tmp[i][j] = tmp[i][j] + mat[i][j];
    return tmp;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const{
    if((rows!=mat.rows)||(cols!=mat.cols))
        errorMessage("cannot do subtraction between two matrices of different size");
    myMatrix tmp(*this);
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            tmp[i][j] = tmp[i][j] - mat[i][j];
    return tmp;
}
myMatrix myMatrix::operator *(const myMatrix& mat) const{
    if(cols!=mat.rows)
        errorMessage("cannot do multiplication between the given two matries");
    myMatrix tmp(rows, mat.cols, 0);
    for(int i=0; i<rows; i++)
        for(int j=0; j<mat.cols; j++)
            for(int k=0; k<cols; k++)
                tmp[i][j] = tmp[i][j] + pData[i][k] * mat[k][j];
    return tmp;
}
myMatrix myMatrix::operator *(int value) const{
    myMatrix tmp(*this);
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            tmp[i][j] = tmp[i][j] * value;
    return tmp;
}
myMatrix operator *(int value, const myMatrix& mat){
    return mat * value;
}
myMatrix& myMatrix::operator =(const myMatrix& mat){
    if(&mat == this)
        return *this;
    rows = mat.rows;
    cols = mat.cols;
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = mat[i][j];
    return *this;
}
myMatrix& myMatrix::operator +=(const myMatrix& mat){
    (*this) = (*this) + mat;
    return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat){
    (*this) = (*this) - mat;
    return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat){
    (*this) = (*this) * mat;
    return *this;
}
myMatrix& myMatrix::operator *=(int value){
    (*this) = (*this) * value;
    return *this;
}
bool myMatrix::operator ==(const myMatrix& mat) const{
    if((rows!=mat.rows)||(cols!=mat.cols))
        return false;
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            if(pData[i][j] != mat[i][j])
                return false;
    return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const{
    return !((*this) == mat);
}
myMatrix myMatrix::operator -() const{
    return (*this) * (-1);
}
myMatrix& myMatrix::transpose(){
    myMatrix tmp(cols, rows, 0);
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            tmp[j][i] = pData[i][j];
    (*this) = tmp;
    return *this;
}
void myMatrix::allocateMemory(){
    if(pData!=NULL)
        deleteMemory();
    pData = new int* [rows];
    if(pData==NULL){
        delete[] pData;
        errorMessage("Memory allocation error");
    }
    for(int i=0; i<rows; i++)
        pData[i] = new int[cols];
}
void myMatrix::deleteMemory(){
    delete [] pData[0];
    delete [] pData;
    pData = NULL;
}
void myMatrix::errorMessage(string str) const{
    cout<<"Error: "<<str<<endl;
    exit(1);
}
ostream& operator <<(ostream& outStream, const myMatrix& mat){
    outStream<<mat.rows<<"*"<<mat.cols<<endl;
    for(int i=0; i<mat.rows; i++){
        for(int j=0; j<mat.cols; j++)
            outStream<<mat[i][j]<<" ";
        outStream<<endl;
    }
    return outStream;
}
istream& operator >>(istream& inStream, myMatrix& mat){
    mat.deleteMemory();
    inStream>>mat.rows>>mat.cols;
    mat.allocateMemory();
    for(int i=0; i<mat.rows; i++)
        for(int j=0; j<mat.cols; j++)
            inStream>>mat[i][j];
    return inStream;
}
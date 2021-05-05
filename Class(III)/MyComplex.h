#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>

using namespace std;
class myComplex{
public:
    myComplex(int real = 0, int imag=0);
    myComplex(const myComplex& number);
    int getRealPart() const;
    int getImaginaryPart() const;
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);

    myComplex operator +(const myComplex& number) const;
    myComplex operator +(const int value) const;
    friend myComplex operator +(const int value, const myComplex& number);
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(const int value) const;
    friend myComplex operator -(const int value, const myComplex& number);
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(const int value) const;
    friend myComplex operator *(const int value, const myComplex& number);
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);
    myComplex& operator +=(const myComplex& number);
    myComplex& operator +=(int value);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;
    friend ostream& operator <<(ostream& outStream, const myComplex& number);
    friend istream& operator >>(istream& inStream, myComplex& number);
    myComplex operator -();
    myComplex operator ~();
    myComplex& operator ++();
    myComplex operator ++(int);
    myComplex& operator --();
    myComplex operator --(int);
private:
    int realPart;
    int imaginaryPart;
    int norm() const;
};

#endif
#include <iostream>

using namespace std;

enum COMPLEX_PART {RE, IM};

class Complex{
    double re, im;
public:
    friend Complex operator+(const Complex& a, const Complex& b);
    friend bool operator==(const Complex& a, const Complex& b);
    friend ostream& operator<<(ostream& os, const Complex& a);
    Complex(double r=0, double i=0): re(r), im(i){}
    ~Complex(){}
    double real(){return re;}
    double imag(){return im;}
    Complex& operator++(){re++; return *this;}
    Complex operator++(int){Complex t(*this); operator++(); return t;}
    Complex& operator+=(const Complex& a){re+=a.re; im+=a.im; return *this;}
    double& operator[](COMPLEX_PART idx){return (idx?im:re);}
    Complex& operator=(const Complex& a){re=a.re; im=a.im; return *this;}
};

Complex operator+(const Complex& a, const Complex& b){
    Complex result(a.re + b.re, a.im + b.re);
    return result;
}
bool operator==(const Complex& a, const Complex& b){
    return (a.re==b.re)&&(a.im==b.im);
}
ostream& operator<<(ostream& os, const Complex& a){
    os<<a.re<<" + "<<a.im<<"i";
    return os;
}

int main(){
    Complex x(2, 3);
    Complex y(-1, -3), z;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    z = x++;
    cout<<"x = "<<x<<endl;
    cout<<"z = "<<z<<endl;
    z = ++x;
    cout<<"x = "<<x<<endl;
    cout<<"z = "<<z<<endl;
    z+=x;
    cout<<"x = "<<x<<endl;
    cout<<"z = "<<z<<endl;
    z[IM] = x[RE];
    cout<<"z = "<<z<<endl;
    return 0;
}
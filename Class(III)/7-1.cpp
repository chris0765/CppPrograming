#include <iostream>

using namespace std;

class Complex{
    double re, im;
public:
    Complex(double r = 0, double i = 0): re(r), im(i){}
    ~Complex(){}
    double real() {return re;}
    double imag() {return im;}
    Complex add(const Complex& c) const;
    friend Complex operator+(const Complex& c, const Complex& d);
    void print() const{
        cout << re << " + " << im << "i" << endl;
    }
};

Complex operator+(const Complex& c, const Complex& d){
    Complex result(c.re+d.re, c.im+d.im);
    return result;
}

Complex Complex::add(const Complex& c) const{
    Complex result(re + c.re, im + c.im);
    return result;
}

int main()
{
    Complex x(2, 3);
    Complex y(-1, -3);
    Complex z;
    x.print();
    y.print();
    z = x+y;
    z.print();
    return 0;
}
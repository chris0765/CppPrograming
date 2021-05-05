#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class MyString{
    char *p;
public:
    MyString(const char *str = NULL);
    MyString(const MyString &s);
    ~MyString(){ delete[] p;}
    int size() const {return strlen(p);}
    friend ostream& operator<<(ostream& os, const MyString & s){
        os<<s.p;
        return os;
    }
    MyString& operator+=(const MyString& r){
        int len = size() + r.size() + 1;
        char *new_p = new char[len];
        strcpy(new_p, p);
        strcat(new_p, r.p);
        delete[] p;
        p = new_p;
        return *this;
    }
    friend MyString operator+(MyString s1, const MyString& s2){
        s1+=s2;
        return s1;
    }
    MyString& operator=(const MyString& s);
    char& operator[](int idx) const{
        assert(0<=idx&&idx<size());
        return p[idx];
    }
};

MyString::MyString(const char*str){
    if(!str){
        p = new char[1];
        p[0] = '\0';
    }
    else{
        p = new char[strlen(str)+1];
        strcpy(p, str);
    }
    cout<<this<<"["<<(str?str:"NULL")<<"] MyString(const char*)"<<endl;
}
MyString::MyString(const MyString& s){
    p = new char[s.size() + 1];
    strcpy(p, s.p);
    cout<<this<<"["<<s.p<<"] Mystring(const MyString&)"<<endl;
}
MyString& MyString::operator=(const MyString& s){
    if(&s != this){
        delete[] p;
        int len = s.size() + 1;
        p = new char[len];
        strcpy(p, s.p);
    }
    return *this;
}

int main(){
    char word[] = "april";
    const MyString m1("1st");
    MyString m2(word);
    MyString m3 = m1+m2;
    cout<<"m1: "<<m1<<endl;
    cout<<"m2: "<<m2<<endl;
    cout<<"m3: "<<m3<<endl;
    m2[1] = m1[0];
    cout<<"m2: "<<m2<<endl;
    m2+=m1;
    cout<<"m2: "<<m2<<endl;
    return 0;
}
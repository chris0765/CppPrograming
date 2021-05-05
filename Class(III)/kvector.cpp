#include <iostream>

using namespace std;

class Kvector{
private:
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector&v);
    ~Kvector();
    Kvector& operator=(const Kvector&v);
    bool operator==(const Kvector& v);
    bool operator!=(const Kvector& v);
    friend ostream& operator<<(ostream& os, const Kvector& v);
    int& operator[](int idx);
    int size() const{return len;};
    void print() const{
        for(int i=0; i<len; i++) cout<<m[i]<<" ";
        cout<<endl;
    }
    void clear(){
        delete[] m;
        m = NULL;
        len = 0;
    }
};

Kvector::Kvector(int sz, int value){
    len = sz;
    if(sz == 0) m = NULL;
    else{
        m = new int[sz];
        for(int i=0; i<sz; i++) m[i] = value;
    }
    cout<<this<<" : Kvector(int)"<<endl;
}
Kvector::Kvector(const Kvector& v){
    len = v.len;
    if(len == 0) m = NULL;
    else{
        m = new int(len);
        for(int i=0; i<len; i++) m[i] = v.m[i];
    }
    cout<<this<<" : Kvector(Kvector&)"<<endl;
}
Kvector::~Kvector(){
    cout<<this<<" : ~Kvector()"<<endl;
}

Kvector& Kvector::operator=(const Kvector& v){
    len = v.size();
    if(len == 0) m = NULL;
    else{
        m = new int(len);
        for(int i=0; i<len; i++)
            m[i] = v.m[i];
    }
    return *this;
}
bool Kvector::operator==(const Kvector& v){
    bool issame = true;
    if(len != v.size()) issame = false;
    else
        for(int i=0; i<len; i++)
            if(m[i]!=v.m[i]){
                issame = false;
                break;
            }
    return issame;
}
bool Kvector::operator!=(const Kvector& v){
    return !(*this == v);
}
ostream& operator<<(ostream&os, const Kvector& v){
    for(int i=0; i<v.size(); i++) os<<v.m[i]<<" ";
    return os;
}
int& Kvector::operator[](int idx){
    return m[idx];
}

int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();
    cout<<(v1==v2)<<endl;
    cout<<(v3==v2)<<endl;
    v3=v2=v1;
    cout<<v1<<endl;
    cout<<v2<<endl;
    cout<<v3<<endl;
    cout<<(v3!=v2)<<endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout<<"v1: "<<v1<<"v2: "<<v2<<"v3: "<<v3<<endl;
    return 0;
}
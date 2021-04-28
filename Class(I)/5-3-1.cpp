#include<iostream>

using namespace std;

class Kvector{
  int *m;
  int len;

  public:
  static int total_len;
  Kvector(int sz = 0, int value = 0);
  Kvector(const Kvector& v);
  ~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] this->m;
    total_len -= this->len;
  }

  void print() const{
    for(int i = 0; i < this->len; i++)
      cout << m[i] << " ";
    cout << endl;
  }

  void clear(){
    total_len -= this->len;
    delete[] m;
    m = NULL;
    this->len = 0;
  }

  int size(){
    return this->len;
  }
};

int Kvector::total_len = 0;

Kvector::Kvector(int sz, int value){
  len = sz;
  Kvector::total_len += len;
  if(len == 0){
    Kvector::m = NULL;
  }
  else{
    Kvector::m = new int[len];
  }

  for(int i = 0; i < len; i++){
    Kvector::m[i] = value;
  }
  cout << this << " : Kvector( " << sz << ", " << value <<  ") " << endl;
}

Kvector::Kvector(const Kvector& v){
  len = v.len;
  total_len += len;
  m = new int[len];
  for(int i = 0; i < len; i++){
    m[i] = v.m[i];
  }
  cout << this << " : Kvector(*" << &v <<  ") " << endl;
}

int main(){
  Kvector v1(3);
  v1.print();
  const Kvector v2(2, 9);
  v2.print();
  Kvector v3(v2);
  v3.print();

  cout << "total length = " << Kvector::total_len << endl;
  v2.print();
  v3.print();
  cout << "total length = " << Kvector::total_len << endl;

  return 0;
}

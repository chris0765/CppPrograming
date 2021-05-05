#include "Avector.h"

kvector::kvector(int sz, int value): len(sz){
  cout << this << " : Kvector(" << sz << "," << value << ")" << endl;
  if(sz == 0 ) m = NULL;
  else{
    m = new int[sz];
    for(int i=0; i<sz; i++) m[i] = value;
  }
  len = sz;
}

kvector::kvector(kvector &v){
  cout << this << " : Kvector(* "<< &v << ")" << endl;
  len = v.len;
  m = new int[len];
  for(int i =0; i<len ; i++) m[i] = v.m[i];
}

kvector& kvector::operator=(const kvector& k){
  m = new int[k.len];
  for(int i = 0; i<k.len; i++) m[i] = k.m[i];
  len = k.len;
  return *this;
}

bool operator==(const kvector& k, const kvector& l) {
  bool boolean = true;
  for(int i=0; i<k.len;i++){
    if(k.m[i] != l.m[i]) boolean = false;
  }
  return boolean;
}

bool operator!=(const kvector& k, const kvector& l){
  return !(k==l);
}

int& kvector::operator[](int idx){
  return m[idx];
}

ostream& operator<<(ostream& os, const kvector& v){
  for(int i = 0; i<v.len; i++) os<<v.m[i] << " ";
  return os;
}


Avector::Avector(int sz , int v, const char *t ): kvector(sz,v){
 for(int i=0;i<N;i++) table[i] = t[i];
 cout << this << " :Avector(" << sz << "," << v <<"," <<t << ")" << endl;
}

void Avector::setTable(const char *t){
  for(int i=0;i<N;i++) table[i] = t[i];
}

ostream& operator<<(ostream& os, const Avector& v){
  for(int i = 0; i<v.len; i++) os<<v.table[v.m[i]%3] << " ";
  return os;
}

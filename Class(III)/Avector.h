#include <iostream>
using namespace std;

class kvector{
protected:
  int *m;
  int len;
public:
  kvector(int sz = 0, int value = 0);
  kvector(kvector &v);
  ~kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m;
  }
  void print(){
    for(int i=0;i<len;i++) cout << m[i] <<" ";
    cout << endl;
  }
  void clear(){
    delete[] m;
    m = NULL;
    len = 0;
  }
  int size(){return len;}

  kvector& operator=(const kvector& k);
  friend bool operator==(const kvector& k, const kvector& l);
  friend bool operator!=(const kvector& k, const kvector& l);
  int& operator[](int idx);
  friend ostream& operator<<(ostream& os, const kvector& v);
};


#define N 3
class Avector : public kvector{
  char table[N];
public:
  Avector(int sz = 0, int v =0, const char *t = "abc");

  void setTable(const char *t);

  friend ostream& operator<<(ostream& os, const Avector& v);

};

#include <iostream>
#include <cassert>
#include "BitSet.h"
using namespace std;



BitSet::BitSet(int sz): Bvector(sz){};

void BitSet::insert(int v){
  set(v);
}
BitSet operator+(const BitSet& v1, const BitSet& v2){
  try{
    if(v1.NBITS != v2.NBITS) throw IncompatibleException(v1.NBITS, v2.NBITS);
  }
  catch (IncompatibleException& e){
    cout<<endl;
    cout<<"In + operation, the operands are not compatible.\nThe size of the first BitSet is "<<v1.len<<"\nThe size of the second BitSet is "<<v2.len<<endl;
  }
  BitSet rst(v1.NBITS);
  for(int i = 0; i < rst.NBITS; i++) {
    if(v1[i] || v2[i])
      rst.insert(i);
  }
  return rst;
}

ostream& operator<<(std::ostream& os, const BitSet& s){
  os <<"{ ";
  for(int i = 0; i < s.NBITS; i++){
    if(s[i])
      os << i << " ";
  }
  os << " }";
  return os;
}

int main(int argc, char *argv[]){
  BitSet b1(132), b2(131);
  b1.insert(3); b1.insert(5); b1.insert(8);
  b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
  b1.print();
  b2.print();
  cout << "b1 : " << b1 << endl;
  cout << "b2 : " << b2 << endl;
  cout << "b1+b2 : " << b1+b2 << endl;

  return 0;
}

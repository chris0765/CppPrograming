#include <iostream>
#include <exception>
#include "Bvector.h"
class IncompatibleException : public std::exception{
  int v1;
  int v2;
public:
  IncompatibleException(int pv1, int pv2) : v1(pv1), v2(pv2){};
};

class BitSet : public Bvector{
public:
  BitSet(int sz = 32);
void insert(int v);
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};

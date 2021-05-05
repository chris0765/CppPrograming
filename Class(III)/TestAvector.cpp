#include <iostream>
#include "Avector.h"

int main(int argc, char* argv[]){
  if(argc !=2 ){
    cout << "usage : ./avecter pqr\n";
    return 1;
  }

  Avector v1(3); v1.print();
  Avector v2(2,1,"xyz"); v2.print();
  Avector v3(v2); v3.print();
  cout <<"v1 == v2 "<< (v1 == v2) << endl;
  cout << "v3 == v2 "<< (v3 == v2) << endl;
  v3 = v2 = v1 ;
  cout <<"v1 : " <<v1 << endl;
  v1.print();
  cout << "v2 : "<<v2 << endl;
  v2.print();
  cout <<"v3 : " <<v3 << endl;
  v3.print();
  cout << "v3 != v2 "<<(v3 != v2) << endl;
  v1[2] = 2;
  v2[0] = v1[2];
  v1.setTable(argv[1]);
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  v1.print();
  v2.print();
  v3.print();
  return 0;
}

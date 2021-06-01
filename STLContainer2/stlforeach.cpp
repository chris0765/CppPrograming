#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(int val){cout << val << ' ';}

#define N 12

template <class T>
void print_container(const T& container, string s = "")
{
  cout << s << "(" << container.size() << ")";
  auto it = container.begin();
  for (; it!= container.end(); it++){cout << *it << " ";}
  cout << endl;
}



int main()
{
  int a[] = {8,7,0,3,1,2,5,0,9,1,4,6};
  auto f = [](int val) {cout << val << ' ';};

  vector<int> v(&a[0],&a[N]);
  print_container(v, "v= ");

  cout << "\n1. ";
  for_each(v.begin(),v.end(),display);
  cout << "\n2. ";
  for_each(v.begin(), v.end(),f);
  cout << "\n3. ";
  for_each(v.begin(),v.end(),[](int val){
    cout << val << ' ';
  });
  cout << "\n";
}

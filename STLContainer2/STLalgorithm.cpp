#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "team.h"

using namespace std;

template <class T>
void print_container(const T& container,string s = ""){
  cout << s << "(" << container.size() << ") ";
  auto it = container.begin();
  for (; it != container.end(); it++) cout << *it << " ";
  cout << endl;
}

bool teamCmp_byName (const Team& a, const Team& b) {return a.name < b.name;}
struct TeamCmp_byVictory {
  bool operator()(const Team& a, const Team& b) {return a.wins < b.wins;}
};


int main()
{
  Team t[] = {Team("Bulls",7), Team("Warriors",5), Team("Spurs",2)};
  vector<Team> tVec;
  tVec.push_back(t[0]);
  tVec.push_back(t[1]);
  tVec.push_back(t[2]);
  print_container(tVec, "1. tVec= ");
  sort(tVec.begin(), tVec.end(), teamCmp_byName);
  print_container(tVec, "2. tVec= ");
  sort(tVec.begin(), tVec.end(), TeamCmp_byVictory());
  print_container(tVec, "3. tVec= ");
  tVec.insert(tVec.begin(), Team("Lakers",3));
  print_container(tVec, "4. tVec= ");

  set<Team, TeamCmp_byVictory> tSet(&t[0], &t[3]);
  print_container(tSet, "1. tSet= ");
  tSet.insert(Team("Lakers",3));
  print_container(tSet, "2. tSet= ");

  priority_queue<Team, vector<Team>, TeamCmp_byVictory> tPQue(&t[0], &t[3]);
  tPQue.push(Team("Lakers",3));
  cout << "1. tPQue : ";
  while(!tPQue.empty())
  {
    cout << tPQue.top() << " ";
    tPQue.pop();
  }
  cout << endl;
}

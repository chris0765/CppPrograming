#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <string>
using namespace std;

class Team{
  string name;
  int wins;
public:
  Team(const string& n = "teamX", int w=0): name(n), wins(w){}
  Team(const Team& c)
  {
    this->name = c.getName();
    this->wins = c.getWins();
  }
  Team& operator+=(const Team& rhs){
    wins += rhs.wins;
    return *this;
  }

  friend Team operator+(const Team& a, const Team& b);
  friend bool operator==(const Team& a, const Team& b);
  friend bool operator!=(const Team& a, const Team& b);
  friend ostream& operator<<(ostream& os, const Team& a);
  friend bool teamCmp_byName (const Team& a, const Team& b);
  friend struct TeamCmp_byVictory;

  string getName() const {return name;};
  int getWins() const{return wins;};
};


#endif

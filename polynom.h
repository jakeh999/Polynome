#ifndef POLYNOM_H
#define POLYNOM_H

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

//Definition der Klasse Polynom

class Polynom {
private:
  vector<int> v;
public:
  Polynom(vector<int>);
  int grad() const;
  int wert(int) const;
  ostream& print(ostream&) const;
  ostream& print_fmt(ostream&) const;

};
ostream& operator<<(ostream&, const Polynom&);
#endif

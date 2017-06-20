#include "polynom.h"
#include <math.h>

Polynom::Polynom(vector<int> v) {
  if (v.empty())
    throw runtime_error("Leere Initialisierungsliste nicht erlaubt!");
  if (v.at(v.size()-1)==0)
    throw runtime_error("Leitindex 0 nicht erlaubt!");
  this->v = v;
}

int Polynom::wert(int n) const {
  int a; int w = 0;
  for (int e = (static_cast<int>(this->v.size())-1); e > -1; e--) {
    a = this->v.at(static_cast<size_t>(e));
    int z = pow(n, e);
    z = z * a;
    w += z;
  }
  return w;
}

int Polynom::grad() const {
  return int(this->v.size())-1;
}

ostream& Polynom::print(ostream& o) const {
  for (int i = (int(this->v.size())-1); i > -1; i--) {
    o << this->v.at(static_cast<size_t>(i)) << "x^" << i;
    if (i!=0)
      o << "+";
  }
  return o;
}

ostream& Polynom::print_fmt(ostream& o) const {
  bool first = true;
  for (int e = (static_cast<int>(this->v.size())-1); e > -1; e--) {
    int a = this->v.at(static_cast<size_t>(e));
    if (a != 0) {
      if (first) {
        if ((a < -1) || (a > 1)) {
          o << a;
        } else if (a == -1) {
          o << '-';
        }
      }

      if ((!first)) {
        if (a > 1) {
          o << '+' << a;
        } else if (a < -1) {
          o << a;
        } else if (a == 1) {
          if (e == 0) {
            o << "+1";
          } else {
            o << '+';
          }
        } else if (a == -1) {
          if (e == 0) {
            o << "-1";
          } else {
            o << '-';
          }
        }
      }

      if (e > 1) {
        o << "x^" << e;
      } else if (e == 1) {
        o << 'x';
      }

      first = false;
    }
  }
  return o;
}

ostream& operator<<(ostream& o, const Polynom& p) {
  return p.print(o);
}

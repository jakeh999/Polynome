
#include"polynom.h"
using namespace std;

int main() {
 Polynom p {{7,-2,3,0,0,8}};
 cout << p << '\n';
 cout << Polynom{{1,1,1}} << " " << Polynom{{-5}} << '\n';
 cout << Polynom{{-1,0,-1,0,-1}}<<'\n';
 cout << Polynom{{0,0,0,0,0,0,1}}<<'\n';
 try {
   cout << Polynom{{4,-1,0,0}};
   cout << Polynom{{2}};
 }
 catch (runtime_error& e) {
   cout << "Leitindex 0 nicht erlaubt!\n";
 }
 try {
   cout << Polynom{{}};
 }
 catch (runtime_error& e) {
   cout << "Leere Initialisierungsliste nicht erlaubt!\n";
 }
 cerr << p << '\n';
 cerr << p.grad() << ' ' << Polynom{{1,2,3}}.grad() << '\n';

 //Dekommentieren fuer Zusatz wert
 cout << Polynom{{4,-1,1}}.wert(2)<<'\n';
 cout << p.wert(-1) << ' ' << p.wert(7) << ' ' << p << '\n';

 //Dekommentieren fuer Zusatz print_fmt
 p.print_fmt(cout)<<'\n';
 Polynom{{1,1,1}}.print_fmt(cout)<<'\n';
 Polynom{{-5}}.print_fmt(cout)<<'\n';
 Polynom{{-1,0,-1,0,-1}}.print_fmt(cout)<<'\n';
 Polynom{{0,0,0,0,0,0,1}}.print_fmt(cerr)<<'\n';

 return 0;
}

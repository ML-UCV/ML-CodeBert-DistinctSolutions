#include <iostream>
#include <fstream>
std::fstream in ("strmatch.in", std::ios::in) ;
std::fstream out ("strmatch.out", std::ios::out) ;

const int MV = 2e6 ;
int sol[MV + 1] ;
int pi[2 * MV + 1] ;

int main(int argc, const char * argv[]) {
 std::string A, B ;
 in >> A >> B ;
 std::string tot = '+' + A + '!' + B ;
 int len(tot.size()) ;
 int nr(0), i ;
 for (i = 2 ; i < len ; ++ i) {
  int prev = pi[i - 1] ;
  while (prev && tot[prev + 1] != tot[i]) {
   prev = pi[prev] ;
  }
  prev += tot[prev + 1] == tot[i] ;
  pi[i] = prev ;
  if (pi[i] == A.size()) {
   sol[++ nr] = i - 2 * A.size() - 1 ;
   }
 }
 out << nr << '\n' ;
 for (i = 1 ; i <= nr && i <= 1000 ; ++ i) {
  out << sol[i] << ' ' ;
 }
}

#include <fstream>

using namespace std;
const int N = 100001;
int p;
char s[N];
int expresie();
int termen();
int factor();
int expresie() {
    int sum = termen();
    while ( s[p] == '+' || s[p] == '-' ) {
        if ( s[p] == '+' ) {
            p++;
            sum += termen();
        } else {
            p++;
            sum -= termen();
        }
    }
    return sum;
}
int termen () {
  int prod = factor();
  while ( s[p] == '*' || s[p] == '/' ) {
     if ( s[p] == '*' ) {
       p++;
       prod *= factor();
     }
     if ( s[p] == '/' ) {
       p++;
       prod /= factor();
     }
  }
  return prod;
}
int factor () {
   int val = 0, semn = 1;
   while ( s[p] == '-' ) {
     semn = -semn;
     p++;
   }
   if ( s[p] == '(' ) {
     p++;
     val = expresie();
     p++;
     return semn * val;
   }
   while ( s[p] >= '0' && s[p] <= '9' )
     val = val * 10 + ( s[p++] - '0' );
   return semn * val;
}
ifstream cin ( "evaluare.in" );
ofstream cout ( "evaluare.out" );
int main() {
    cin.getline( s, N );
    cout << expresie();
    return 0;
}

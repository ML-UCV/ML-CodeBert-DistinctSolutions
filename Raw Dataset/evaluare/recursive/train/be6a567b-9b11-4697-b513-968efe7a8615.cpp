#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

ifstream fin( "evaluare.in" );
ofstream fout( "evaluare.out" );

const int MaxL = 100001;

char exp[MaxL + 1];
int i;

int eval();
int term();
int fact();

int eval() {
  int res;

  res = term();
  while ( exp[i] == '+' || exp[i] == '-' ) {
 ++i;
 if ( exp[i - 1] == '+' ) {
   res += term();
 } else {
   res -= term();
 }
  }
  return res;
}
int term() {
  int res;

  res = fact();
  while ( exp[i] == '*' || exp[i] == '/' ) {
 ++i;
 if ( exp[i - 1] == '*' ) {
      res *= fact();
 } else {
   res /= fact();
 }
  }
  return res;
}
int fact() {
  int res = 0;

  if ( exp[i] == '(' ) {
 ++i;
 res = eval();
 ++i;
  } else {
    while ( isdigit( exp[i] ) ) {
      res = res * 10 + exp[i] - '0';
      ++i;
 }
  }
  return res;
}

int main() {
  fin >> exp;
  fout << eval();
  fin.close();
  fout.close();
  return 0;
}

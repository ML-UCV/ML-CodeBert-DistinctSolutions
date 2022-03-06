#include <fstream>

using namespace std;

ifstream fin ("evaluare.in");
ofstream fout ("evaluare.out");

const int Dim = 1e6 +5;
char s[Dim];
int p = 1;
int factor();
int exp();
int termen();

int exp() {

 int sum = termen();
 while ( s[p] == '+' or s[p] == '-') {

  if ( s[p] == '+') {

   ++p;
   sum += termen();
  }
  else
   if ( s[p] == '-') {

    ++p;
    sum -= termen();
   }
 }
 return sum;
}

int termen() {

 int prod = factor();
 while ( s[p] == '*' or s[p] == '/' ) {

  if ( s[p] == '*') {

   ++p;
   prod *= factor();
  }
  else if ( s[p] == '/' ) {
   ++p;
   prod /= factor();
  }
 }
 return prod;
}

int factor() {

 int val = 0, semn = 1;
 while ( s[p] == '-') {

  ++p;
  semn *= -1;
 }
 if ( s[p] == '(') {

  p++;
  val = exp();
  p++;
  return semn * val;
 }
 while ( isdigit(s[p]) ) {
   val = val * 10 + s[p] - '0';
  ++p;
  }
 return semn * val;
}

int main() {

 fin >> (s + 1);
 fout << exp();

}

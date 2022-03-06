#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



inline int gcd (int A, int B, long long &X, long long &Y ) {

 if (B == 0) {

  X = 1;

  Y = 0;

  return A;

 }

 int D;

 long long X0, Y0;

 D = gcd (B, A % B, X0, Y0);

 X = Y0;

 Y = X0 - (A / B) * Y0;

 return D;

}



int main() {

 long long inv = 0, ins;

 int A, N;

 fin >> A >> N;

 gcd (A, N, inv, ins);

 if (inv <= 0) inv = N + inv % N;

 fout << inv;

 fin.close ();

 fout.close ();

 return 0;

}

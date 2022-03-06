#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <stdio.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");







void gcd(int a, int b, long long& x, long long& y) {

 if (a == 0) {

  x = 0;

  y = 1;

  return;

 }



 long long x1, y1;



 gcd(b % a, a, x1, y1);



 x = y1 - (b / a) * x1;

 y = x1;

}



int main() {

 int A, N;



 fin >> A >> N;



 long long inv, ins;



 gcd(A, N, inv, ins);



 if (inv < 0)

  inv = N + inv % N;



 fout << inv;



 return 0;

}

#include <iostream>
#include <fstream>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int N = 2500001;

const int L = 18;

int n, m, p, q, rez, t[L][N];



int main() {

 in >> n >> m;

 for (int i = 1; i <= n; i++)

  in >> t[0][i];

 for (int i = 1; i < L; i++)

  for (int j = 1; j <= n; j++)

   t[i][j] = t[i - 1][t[i - 1][j]];

 while (m) {

  int i = 0;

  m--;

  in >> q >> p;

  rez = q;

  while (p) {

   if (p % 2 != 0) rez = t[i][rez];

   p /= 2;

   i++;

  }

  out << rez << '\n';

 }

 return 0;

}

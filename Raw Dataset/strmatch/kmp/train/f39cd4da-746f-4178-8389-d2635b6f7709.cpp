#include<bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int m, n, k, c, urm[2000005];

char P[2000005], T[2000005];

int a[2000005];

void Prefix()

{

 int j = 0;

 for (int i = 1; i < n; ++i)

 {

  while (j > 0 && P[i] != P[j])

   j = urm[j - 1];

  if (P[i] == P[j])

   j++;

  urm[i] = j;

 }

}



void KMP()

{

 int q = 0;

 for (int i = 0; i < m; ++i)

 {

  while (q > 0 && P[q] != T[i])

   q = urm[q - 1];

  if (P[q] == T[i]) ++q;

  if (q == n)

  {

   a[c++] = i - n + 1;

  }

 }

}



void Citire()

{

 fin.getline(P, 2000005);

 fin.getline(T, 2000005);

 n = strlen(P);

 m = strlen(T);

}



int main()

{

 Citire();

 Prefix();

 KMP();

 fout << c << '\n';

 if (c > 1000)

  c = 1000;

 for (int i = 0; i < c; ++i)

 {

  fout << a[i] << ' ';

 }

}

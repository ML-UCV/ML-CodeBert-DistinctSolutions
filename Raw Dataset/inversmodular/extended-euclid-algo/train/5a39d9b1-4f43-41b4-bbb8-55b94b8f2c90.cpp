#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int main()

{

long long int a, n, aux, r, c, y, y0, y1;

y0 = 0;

y1 = 1;

fin >> a >> n;

aux = n;

while(a!=0)

{

  r = n%a;

  c = n/a;

  n = a;

  a = r;

  y = y0 - c * y1;

  y0 = y1;

  y1 = y;

}

if(y0 < 0)

  y0 = aux + y0%aux;

fout << y0;

return 0;

}

#include <bits/stdc++.h>
using namespace std;



ifstream fin ( "inversmodular.in" );

ofstream fout ( "inversmodular.out" );



void gcda ( int a, int b, pair<int,int> &xy )

{

  if ( b == 0 ) { xy = {1, 0}; return; }

  gcda (b, a%b, xy);

  xy = {xy.second, xy.first - (a/b)*xy.second};

}



int main ()

{

  int a, n; fin >> a >> n;

  pair<int,int> xy;

  gcda (a, n, xy);

  if (xy.first < 0) xy.first += ((-xy.first)/n+1)*n;

  fout << xy.first % n;

  fin.close (); fout.close ();

  return 0;

}

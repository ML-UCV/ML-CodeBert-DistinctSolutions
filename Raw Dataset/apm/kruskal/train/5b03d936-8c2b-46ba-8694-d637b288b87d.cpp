#include <bits/stdc++.h>




using namespace std;



ifstream fin( "apm.in" );

ofstream fout( "apm.out" );



const int NMAX = 2e5;

const int MMAX = 4e5;

struct lol {

  int a, b, c;

  bool operator < ( const lol &shit ) const {

    return c < shit.c;

  }

};

lol v[MMAX + 1];

int sef[NMAX + 1];

vector <pair<int, int>> sol;



int myfind( int x ){

  if( sef[x] == x )

    return x;

  return sef[x] = myfind(sef[x]);

}



void myunite( int x, int y ){

  int sefx = myfind(x), sefy = myfind(y);

  if( sefx != sefy )

    sef[sefy] = sefx;

}



int main() {

  int n, m, i, sum;

  fin >> n >> m;

  for( i = 0; i < m; ++i )

    fin >> v[i].a >> v[i].b >> v[i].c;

  for( i = 1; i <= n; ++i )

    sef[i] = i;

  sort( v, v + m );

  sum = 0;

  for( i = 0; i < m; ++i )

    if( myfind(v[i].a) != myfind(v[i].b) ){

      sum += v[i].c;

      sol.push_back({v[i].a, v[i].b});

      myunite(v[i].a, v[i].b);

    }

  fout << sum << "\n" << sol.size() << "\n";

  for( auto it : sol )

    fout << it.first << " " << it.second << "\n";

  return 0;

}

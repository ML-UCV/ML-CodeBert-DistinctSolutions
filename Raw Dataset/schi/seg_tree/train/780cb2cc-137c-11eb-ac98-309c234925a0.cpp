#include <fstream>


using namespace std;



ifstream fin( "schi.in" );

ofstream fout( "schi.out" );



const int NMAX = 30000;

int v[NMAX + 1];

int sol[NMAX + 1];

int aint[NMAX * 4 + 1];



void build( int nod, int st, int dr ){

  int med;

  if( st == dr ){

    aint[nod] = v[st];

    return;

  }

  med = (st + dr) >> 1;

  build( nod << 1, st, med );

  build( (nod << 1) | 1, med + 1, dr );

  aint[nod] = aint[nod << 1] + aint[(nod << 1) | 1];

}



int query_bun(int nod, int x, int val)

{

  int st, pas, s=0;

  st = 0;

  for(pas=x;pas>0;pas>>=1)

    if(aint[nod<<1]+s<val)

    {

      s += aint[nod<<1];

      nod=((nod<<1)|1);

      st += pas;

    }

    else

      nod<<=1;

  return st + 1;

}



void update( int nod, int st, int dr, int a, int val ){

  int med;

  if( st == dr ){

    aint[nod] = val;

    return;

  }

  med = (st + dr) >> 1;

  if( a <= med )

    update( (nod << 1), st, med, a, val );

  else

    update( (nod << 1) | 1, med + 1, dr, a, val );

  aint[nod] = aint[nod << 1] + aint[(nod << 1) | 1];

}



int main() {

    int n, i, nnou,s;

    fin >> n;

    nnou = 1;

    while(nnou<n)

      nnou<<=1;

    for( i = 1; i <= n; ++i )

      v[i] = 1;

    build( 1, 1, nnou );

    for( i = 1; i <= n; ++i )

      fin >> v[i];

    for( i = n; i >= 1; --i ){

        s=query_bun(1, nnou>>1, v[i]);

      sol[s] = i;

      update( 1, 1, nnou, s, 0 );

    }

    for( i = 1; i <= n; ++i )

      fout << sol[i] << "\n";

    return 0;

}

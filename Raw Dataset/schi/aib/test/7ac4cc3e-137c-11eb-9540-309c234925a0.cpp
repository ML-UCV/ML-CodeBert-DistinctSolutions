#include <fstream>


using namespace std;



ifstream fin( "schi.in" );

ofstream fout( "schi.out" );



const int NMAX = 30005;

const int INF = 2000000000;



int N;

int tree[NMAX];



int a[NMAX];



void Read()

{

  fin >> N;



  for( int i = 1; i <= N; ++i )

    fin >> a[i];



  fin.close();

}



void Update( int pos, int val )

{

  while( pos <= N )

  {

    tree[pos] += val;

    pos += pos & -pos;

  }

}



int Query( int pos )

{

   int sum = 0;



   while( pos > 0 )

   {

     sum += tree[pos];

     pos -= pos & -pos;

   }



   return sum;

}



int BinSearch( int lf, int rg, int val )

{

  if( lf > rg ) return INF;



  int mid = ( lf + rg ) / 2;

  int q = Query( mid );



  if( q == val ) return min( mid, BinSearch( lf, mid - 1, val ) );



  if( q < val ) return BinSearch( mid + 1, rg, val );

  else return BinSearch( lf, mid - 1, val );

}



void Do()

{

  for( int i = 1; i <= N; ++i )

    Update( i, 1 );



  int sol[NMAX];



  for( int i = N; i >= 1; --i )

  {

    int p = BinSearch( 1, N, a[i] );



    sol[p] = i;



    Update( p, -1 );

  }



  for( int i = 1; i <= N; ++i )

    fout << sol[i] << '\n';



  fout.close();

}



int main()

{

    Read();

    Do();



    return 0;

}

#include <string.h>
#include <fstream>
using namespace std;

ifstream fin( "strmatch.in" );

ofstream fout( "strmatch.out" );

char caut[ 2000005 ], b[ 2000005 ];



void lps( int v[], char b[] ){

 v[ 0 ] = 0;

 int i = 1, n = strlen( b ), len = 0;

 while( i < n )

  if( b[ i ] == b[ len ] ){

   len++;

   v[ i++ ] = len;

  } else if( len != 0 )

    len = v[ len - 1 ];

   else

    v[ i++ ] = 0;



}



void KMP( char a[], char b[] ){

 int i = 0, j = 0, n = strlen( a ), m = strlen( b );

 int v[ m ], cnt = 0, val[ 1000 ];

    lps( v, b );

 while( i < n ){

  if( a[ i ] == b[ j ] ){

   i++;

   j++;

   if( j == m ){

    if( cnt < 1000 )

        val[ cnt ] = i - j;

                cnt++;

                j = v[ j - 1 ];

   }

  } else if( ( i < n ) && ( b[ j ] != a[ i ] ) )

   if( j > 0 )

    j = v[ j - 1 ];

   else i++;

 }

 fout << cnt << "\n";

 if( cnt > 1000 )

        cnt = 1000;

 for( int i = 0; i < cnt; ++i )

     fout << val[ i ] << ' ';

}



int main()

{

    fin >> b;

    fin >> caut;

    KMP( caut, b );

    return 0;

}

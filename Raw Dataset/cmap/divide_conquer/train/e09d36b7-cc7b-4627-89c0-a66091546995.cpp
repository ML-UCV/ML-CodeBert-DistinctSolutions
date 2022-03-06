#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
const int NLIM = 1e5 + 10;

const long double INF = INT_MAX;



using namespace std;



struct pointS

{

 long double x, y;

};



int comparX( const void* a, const void* b )

{

 pointS p1 = *(pointS*)a;

 pointS p2 = *(pointS*)b;



 if( p1.x < p2.x ) return -1;

 if( p1.x > p2.x ) return 1;



 if( p1.y < p2.y ) return -1;

 if( p1.y > p2.y ) return 1;

 return 0;

}

int comparY( const void* a, const void* b )

{

 pointS p1 = *(pointS*)a;

 pointS p2 = *(pointS*)b;



 if( p1.y < p2.y ) return -1;

 if( p1.y > p2.y ) return 1;



 if( p1.x < p2.x ) return -1;

 if( p1.x > p2.x ) return 1;

 return 0;

}





long double dist( pointS p1, pointS p2 )

{

 return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );

}



int n;

pointS points[NLIM];

pointS strip[NLIM];





long double solve( int l, int r )

{



 if( l + 3 >= r )

 {



  long double res = INF;

  for( int i = l; i < r; ++i )

   for( int j = i + 1; j < r; ++j )

   {

    long double d = dist(points[i], points[j]);

    if( d < res )

     res = d;

   }

  return res;

 }



 int m = ( l + r ) / 2;



 long double res = min( solve( l, m ), solve( m + 1, r ) );







 int stripSize = 0;

 for( int i = l; i < r; ++i )

  if( abs( points[i].x - points[m].x ) < res )

   strip[stripSize] = points[i], stripSize++;





 qsort( strip, stripSize, sizeof( pointS ), comparY );

 for( int i = 0; i < stripSize; ++i )

  for( int j = i + 1; j < stripSize && ( strip[j].y - strip[i].y ) < res; ++j )

  {

   long double d = dist( strip[i], strip[j] );

   if( d < res )

    res = d;

  }



 return res;

}



ifstream fcin("cmap.in");

ofstream fcout("cmap.out");

int main()

{

 fcin >> n;



 for( int i = 0; i < n; ++i )

  fcin >> points[i].x >> points[i].y;



 qsort( points, n, sizeof( pointS ), comparX );
 fcout << fixed << setprecision(6) << solve( 0, n ) << "\n";







}

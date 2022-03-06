#include <bits/stdc++.h>


using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int Nmax = 100002;



struct Point

{

    int x,y;

} A[Nmax] , B[Nmax] , C[Nmax ];



bool CompX( Point a , Point b )

    { return a.x<b.x; }



bool CompY ( Point a , Point b)

      { return a.y<b.y; }



long long Distance ( Point a , Point b)

   {

       return ( (long long) a.x- (long long )b.x)*((long long )a.x-(long long )b.x) + ((long long )a.y- (long long )b.y)*((long long )a.y-(long long )b.y);

   }



long long Solve ( int left , int right )

{

    if ( right - left + 1 <= 3 )

    {

        sort ( A + left , A + right + 1 , CompY );



       long long LeastDist = Distance( A[left], A[left+1 ] );



        for ( int i=left ; i < right ; ++i)

            for( int j=i+1 ; j<=right ;++j)

        { long long Dist = Distance ( A[i],A[j] );

          if ( LeastDist > Dist )

                LeastDist = Dist ;

        }



      return LeastDist;



    }



    else

    {



        int Middle = (left + right ) / 2;

        Point Mid;

        Mid.x = A[Middle].x;

        Mid .y = 0 ;



        long long LeastDist1 = Solve ( left , Middle ) ;

        long long LeastDist2 = Solve ( Middle + 1 , right ) ;

        long long LeastDist = min(LeastDist1 , LeastDist2 );



        int i ,j ,k = 0 , h = 0;

        for ( i = left , j =Middle +1 ; i<= Middle || j<=right ; )

            if ( i<=Middle && ( ( A[i].y < A[j].y ) || j > right ) )

                 B[ ++k ] = A[ i++] ;

            else if ( j<=right )

                 B[++k] = A[j++];





        for (i=1 , j = left ;i<=k && j<= right ;++i ,++j)

        {if ( ( (long long )B[i].x - (long long ) Mid.x ) * ( (long long )B[i].x - (long long ) Mid.x ) <= LeastDist )

              C[++h] = B[i];

         A[j]=B[i];

        }



        for (i=1; i< h;++i)

            for (j=i+1; j<=h && j<=i+7;++j)

        { long long Dist = Distance(C[i],C[j]);

            if ( Dist < LeastDist )

                LeastDist = Dist ;

        }



        return LeastDist;

    }





}





int main()

{



    int N ;

    long long result ;

    fin>>N;



    for ( int i = 1; i <= N ; ++i )

         fin>>A[i].x>>A[i].y;



    sort(A+1,A+N+1,CompX);



    result = Solve( 1 , N );







    fout<<setprecision(6)<<fixed << sqrt ((double) result) ;



    return 0;

}

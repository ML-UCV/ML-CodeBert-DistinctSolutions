#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inv.in") ;

ofstream g("inv.out") ;

long long x[100001] , n , i , nrinv ;



void interclaseaza(int st, int mij, int dr)

{

    long long i, j, k = 0, y[100001] ;

    i = st;

    j = mij + 1;





    while (i <= mij && j <= dr)

    {

        if (x[i] <= x[j])

        {

            k++;

            y[k] = x[i];

            i++;

        }

        else

        {

            k++;

            y[k] = x[j];

            j++;

            nrinv = ( nrinv + mij - i + 1) % 9917;

        }

    }

    while (i <= mij)

    {

        k++;

        y[k] = x[i];

        ++i;

    }

    while (j <= dr)

    {

        k++;

        y[k] = x[j];

        ++j;

    }



    k=1;

    for (i = st; i <= dr; ++i)

        {

            x[i] = y[k];

            k++;

        }

}



 void mergesort( int st , int dr)

 {

     if( st < dr )

        {

     mergesort( st , ( st + dr ) / 2 ) ;

     mergesort( ( st + dr ) / 2 + 1 , dr ) ;

     interclaseaza( st , ( st + dr ) / 2 , dr ) ; }

 }

int main()

{

    f >> n ;

    for( i = 1 ; i <= n ; i ++ )

        f >> x[i] ;

    mergesort( 1 , n ) ;

    g << nrinv ;

    return 0 ;

}

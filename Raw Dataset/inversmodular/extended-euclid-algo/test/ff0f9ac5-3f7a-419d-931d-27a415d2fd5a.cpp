#include <stdio.h>


void calculez( long long a, long long b, long long *x, long long *y )

{

    if( b == 0 ){

        *x = 1;

        *y = 0;

    } else {

        long long x0, y0;

        calculez( b, a % b, &x0, &y0 );

        *x = y0;

        *y = x0 - ( a / b ) * y0;

    }

}



int main()

{

    long long a, n, x, y;

    FILE *fin = fopen( "inversmodular.in", "r" );

    fscanf( fin, "%lld %lld", &a, &n );

    fclose( fin );

    calculez( a, n, &x, &y );

    if( x < 1 )

        x = (x + n) % n;

    FILE *fout = fopen( "inversmodular.out", "w" );

    fprintf( fout, "%lld", x );

    fclose( fout );

    return 0;

}

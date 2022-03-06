#include <bits/stdc++.h>
using namespace std;

ifstream fin( "inversmodular.in" );

ofstream fout( "inversmodular.out" );

void fast()

{

    cin.tie( 0 );

    ios_base::sync_with_stdio( 0 );

}

int a,b;

void invers( int a, int b, int &x, int &y )

{

    if( !b )

        {

            x = 1;

            y = 0;

            return;

        }



    int x0, y0;

    invers( b, a % b, x0, y0 );

    x = y0;

    y = x0 - y0 * ( a / b );

}

int main()

{

    fast();

    fin >> a >> b;

    int x, y;

    invers( a, b, x, y );



    while( x < 0 )

        x = ( x + b ) % b;



    fout << x;

    return 0;

}

#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



int cont[27], cont2[27];

int P[50005];

int M[27][50005];

int N;



int BIT[50005];



string a, b;



inline int lsb( int x )

{

    return ( x & ( -x ) );

}



void update( int x, int val )

{

    for ( int i = x; i <= N; i += lsb( i ) )

            BIT[i] += val;

}



int query( int x )

{

    int s = 0;



    for ( int i = x; i >= 1; i -= lsb( i ) )

            s += BIT[i];



    return s;

}



int main()

{

    ifstream f("swap.in");

    ofstream g("swap.out");



    getline( f, a );

    getline( f, b );



    N = a.size();



    for ( int i = 0; i < N; ++i )

    {

        M[ b[i] - 97 ][ ++cont2[ b[i] - 97 ] ] = i + 1;

    }



    for ( int i = 0; i < N; ++i )

    {

        ++cont[ a[i] - 97 ];



        P[i + 1] = M[ a[i] - 97 ][ cont[ a[i] - 97 ] ];

    }



    int sol = 0;



    for ( int i = 1; i <= N; ++i )

    {

        if ( P[i] == 0 )

        {

            g << "-1\n";

            return 0;

        }

    }



    for ( int i = 1; i <= N; ++i )

    {

        sol += i - 1 - query( P[i] - 1 );

        update( P[i], 1 );

    }



    g << sol << "\n";



    f.close();

    g.close();



    return 0;

}

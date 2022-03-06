#include <bits/stdc++.h>


using namespace std;



const int NMAX = 30002;



ifstream fin("schi.in");

ofstream fout("schi.out");



int N, v[NMAX], aib[NMAX];

int S[NMAX];



void Update( int pos, int val )

{

    while( pos <= N )

    {

        aib[pos] += val;

        pos += ( pos & -pos );

    }

}

int Query( int pos )

{

    int sum = 0;

    while( pos )

    {

        sum += aib[pos];

        pos -= ( pos & -pos );

    }

    return sum;

}

int BS( int lf, int rg, int val )

{

    if( lf > rg ) return ( 1 << 30 );



    int mid = lf + ( rg - lf )/2;



    int qmid = Query( mid );



    if( qmid >= val ) return min( mid, BS( lf, mid-1, val ) );

    else return BS( mid+1, rg, val );

}

void Solve()

{

    fin >> N;



    for( int i = 1; i <= N; ++i )

    {

        fin >> v[i];

        Update( i, 1 );

    }



    for( int i = N; i > 0; --i )

    {

        int p = BS( 1, N, v[i] );



        S[p] = i;

        Update( p, -1 );

    }



    for( int i = 1; i <= N; ++i )

        fout << S[i] << '\n';

}

int main()

{

    Solve();

    return 0;

}

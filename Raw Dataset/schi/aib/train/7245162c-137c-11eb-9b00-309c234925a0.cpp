#include <bits/stdc++.h>


using namespace std;



ifstream fin( "schi.in" );

ofstream fout( "schi.out" );



const int NMAX = 30005;



int N;

int t[NMAX];

int a[NMAX];

int place[NMAX];



void Update( int idx, int v ) {

    while( idx <= N ) {

       t[idx] += v;

       idx += idx & (-idx );

    }

}



int Query( int idx ) {

    int ans = 0;

    while( idx ) {

       ans += t[idx];

       idx -= idx & ( -idx );

    }

    return ans;

}



void Read()

{

    fin >> N;

    for( int i = 1; i <= N; ++i )

       fin >> a[i];

}



int BinSearch( int lf, int rg, int val ) {

    if( lf > rg ) return N + 1;



    int mid = lf + ( rg - lf ) / 2;

    int ans = Query( mid );



    if( ans == val ) return min( mid, BinSearch( lf, mid - 1, val ) );



    if( ans < val ) return BinSearch( mid + 1, rg, val );

    else return BinSearch( lf, mid - 1, val );

}



void Do()

{

    for( int i = 1; i <= N; ++i )

      Update( i, 1 );



    for( int i = N; i > 0; --i ) {

       int loc = BinSearch( 1, N, a[i] );



       place[loc] = i;

       Update( loc, -1 );

    }

    for( int i = 1; i <= N; ++i )

      fout << place[i] << '\n';

}



int main()

{

    Read();

    Do();



    return 0;

}

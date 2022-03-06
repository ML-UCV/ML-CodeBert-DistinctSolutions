#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;



ifstream fin ( "cmap.in" );

ofstream fout ( "cmap.out" );



pair<int, int> v[1 + 100000], p[1 + 100000];



double minim ( double a, double b ) {

    return ( a < b ) ? a : b;

}



double dist ( pair<int, int> a, pair<int, int> b ) {

    return sqrt ( ( double ) ( a.first - b.first ) * ( a.first - b.first ) + ( double ) ( a.second - b.second ) * ( a.second - b.second ) );

}



double cmp ( pair<int, int> a, pair<int, int> b ) {

    return a.second < b.second;

}



double sol ( int st, int dr ) {



    if ( dr - st + 1 <= 3 ) {

        sort ( v + st, v + dr + 1, cmp );



        double ans = INFINITY;



        for ( int i = st; i <= dr; ++ i )

            for ( int j = i + 1; j <= dr; ++ j )

                ans = minim ( ans, dist ( v[i], v[j] ) );



        return ans;

    }



    int mid = ( st + dr ) / 2;

    int xmid = v[mid].first;



    double ans = minim ( sol ( st, mid ), sol ( mid + 1, dr ) );



    int ind = st;

    int i = st, j = mid + 1;



    while ( i <= mid && j <= dr ) {

        if ( v[i].second < v[j].second )

            p[ind ++] = v[i ++];

        else

            p[ind ++] = v[j ++];

    }



    for ( ; i <= mid; ++ i ) p[ind ++] = v[i];



    for ( ; j <= dr; ++ j ) p[ind ++] = v[j];



    for ( int i = st; i <= dr; ++ i )

        v[i] = p[i];



    ind = 0;



    for ( int i = st; i <= dr; ++ i )

        if ( fabs ( v[i].first - xmid ) < ans )

            p[ind++] = v[i];



    for ( int i = 0; i < ind; ++ i )

        for ( int j = i + 1; j <= i + 7 && j < ind; ++ j )

            ans = min ( ans, dist ( p[i], p[j] ) );



    return ans;



}



int main() {



    int N;



    fin >> N;



    for ( int i = 1; i <= N; ++i )

        fin >> v[i].first >> v[i].second;



    fout << setprecision(8) << fixed;



    sort( v + 1, v + N + 1 );

    fout << sol (1, N);



    return 0;

}

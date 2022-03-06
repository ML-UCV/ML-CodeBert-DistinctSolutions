#include <bits/stdc++.h>
using namespace std;



ifstream f ( "cmap.in" );

ofstream g ( "cmap.out" );

const int MAX_N = 100005;

const long long INF = 4e18;



vector < pair<long long,long long> > V ( MAX_N ), X, Y;



long long dist ( const pair<long long,long long>& a, const pair<long long,long long>& b )

{

    return ( a.first - b.first ) * ( a.first - b.first ) + ( a.second - b.second ) * ( a.second - b.second );

}

long long go ( int st, int dr, vector <pair<long long,long long> >& X, vector < pair<long long,long long> >& Y )

{

    if ( st >= dr - 1 )

        return INF;

    else

        if ( dr - st == 2 )

        {

            if ( Y[st] > Y[st + 1] )

                swap ( Y[st], Y[st + 1] );



            return dist ( X[st], X[st + 1] );

        }



    int mid = ( st + dr ) / 2;

    long long best = min ( go ( st, mid, X, Y ), go ( mid, dr, X, Y ) );

    merge ( Y.begin() + st, Y.begin() + mid, Y.begin() + mid, Y.begin() + dr, V.begin() );

    copy ( V.begin(), V.begin() + ( dr - st ), Y.begin() + st );

    int v_size = 0;



    for ( int i = st; i < dr; ++ i )

        if ( abs ( Y[i].second - X[mid].first ) <= best )

            V[v_size ++] = Y[i];



    for ( int i = 0; i < v_size - 1; ++ i )

    {

        for ( int j = i + 1; j < v_size && j - i < 8; ++ j )

            best = min ( best, dist ( V[i], V[j] ) );

    }



    return best;

}



int main ()

{

    int n;

    f >> n;

    X.resize ( n ), Y.resize ( n );



    for ( int i = 0; i < n; ++ i )

        f >> X[i].first >> X[i].second;



    sort ( X.begin(), X.end() );



    for ( int i = 0; i < n; ++ i )

        Y[i] = make_pair ( X[i].second, X[i].first );



    g << fixed << setprecision ( 6 ) << sqrt ( go ( 0, X.size(), X, Y ) ) << "\n";

    return 0;

}

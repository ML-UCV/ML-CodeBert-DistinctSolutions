#include <bits/stdc++.h>






using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



struct Muchie

{

    int x, y, cost;

};



struct A

{

    int x, y;

};



vector < A > R;

Muchie v[400005];

int t[200005], lg[200005];



int radacina ( int x );

void uneste ( int x, int y );

bool crt ( Muchie a, Muchie b );



int main()

{

    int n, m, i, x, y, r = 0;



    fin >> n >> m;

    for ( i = 1 ; i <= m ; i++ ) fin >> v[i].x >> v[i].y >> v[i].cost;



    sort ( v + 1, v + m + 1, crt );

    for ( i = 1 ; i <= n ; i++ ) t[i] = i, lg[i] = 1;



    for ( i = 1 ; i <= m ; i++ )

    {

        x = radacina ( v[i].x );

        y = radacina ( v[i].y );



        if ( x != y )

        {

            uneste ( x, y );

            r += v[i].cost;

            R.push_back ( { v[i].x, v[i].y } );

        }

    }



    fout << r << '\n' << n - 1 << '\n';

    for ( i = 0 ; i < R.size() ; i++ ) fout << R[i].x << ' ' << R[i].y << '\n';



    return 0;

}



bool crt ( Muchie a, Muchie b )

{

    if ( a.cost < b.cost ) return 1;



    return 0;

}



int radacina ( int x )

{

    if ( x != t[x] ) t[x] = radacina ( t[x] );



    return t[x];

}



void uneste ( int x, int y )

{

    if ( lg[x] < lg[y] ) lg[y] += lg[x], t[x] = y;

    else lg[x] += lg[y], t[y] = x;

}

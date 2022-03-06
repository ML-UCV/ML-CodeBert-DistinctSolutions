#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



const int NMAX = 2e5;

const int MMAX = 4e5;



struct edge {

    int a;

    int b;

    int cost;

};

vector <edge> edges;

vector <edge> ans;

int father[NMAX + 1];



void init() {

    for ( int i = 1; i <= NMAX; i ++ )

        father[i] = i;

}

int root( int i ) {

    if ( father[i] == i )

        return i;

    return ( father[i] = root( father[i]) );

}

bool cmp( edge a, edge b ) {

    return a.cost < b.cost;

}

int main() {

    ifstream fin( "apm.in" );

    ofstream fout( "apm.out" );

    int n, m, i, a, b, cost, total = 0, k;

    fin >> n >> m;

    for ( i = 0; i < m; i ++ ) {

        fin >> a >> b >> cost;

        edges.push_back( { a, b, cost } );

    }

    init();

    sort( edges.begin(), edges.end(), cmp );

    k = i = 0;

    while ( k < n - 1 ) {

        a = edges[i].a;

        b = edges[i].b;

        if ( root( a ) != root( b ) ) {

            total += edges[i].cost;

            father[root( a )] = root( b );

            ans.push_back( { a, b, cost } );

            k ++;

        }

        i ++;

    }

    fout << total << '\n' << n - 1 << '\n';

    for ( auto& x : ans )

        fout << x.a << ' ' << x.b << '\n';

    return 0;

}

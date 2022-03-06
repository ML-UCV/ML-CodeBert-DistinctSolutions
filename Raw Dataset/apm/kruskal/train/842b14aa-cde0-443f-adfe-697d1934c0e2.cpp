#include <bits/stdc++.h>


using namespace std;



ifstream fin( "apm.in" );

ofstream fout( "apm.out" );



const int NMAX = 200005;



int N, M;

struct edg

{

    int a, b;

    int d;



    bool operator < ( const edg & E ) {

        return d < E.d;

    }

} A[2 * NMAX];



int m[NMAX];

int sz[NMAX];



vector <pair<int,int> > sol;



int Find( int a ) {

    int ra = a;



    while( m[ra] != ra )

        ra = m[ra];



    while( a != m[a] ) {

        int aux = m[a];

        m[a] = ra;

        a = aux;

    }

    return ra;

}



void Union( int a, int b ) {

    int ra = Find( a );

    int rb = Find( b );



    if( sz[ra] < sz[rb] ) swap( ra, rb );



    sz[ra] += sz[rb];

    m[rb] = ra;

}



void Read() {

    fin >> N >> M;



    int a, b, d;

    for( int i = 1; i <= M; ++i ) {

        fin >> a >> b >> d;



        A[i].a = a;

        A[i].b = b;

        A[i].d = d;

    }

}



void Do()

{

    sort( &A[1], &A[M + 1] );



    for( int i = 1; i <= N; ++i )

        sz[i] = 1, m[i] = i;



    int added = 0;

    int cost = 0;



    for( int i = 1; i <= M && added < N - 1; ++i ) {

        int fa = Find( A[i].a ), fb = Find( A[i].b );



        if( fa != fb ) {

            ++added;

            Union( fa, fb );

            cost += A[i].d;

            sol.push_back( { A[i].a, A[i].b } );

        }

    }



    fout << cost << '\n' << added << '\n';

    for( int i = 0; i < sol.size(); ++i )

        fout << sol[i].first << ' ' << sol[i].second << '\n';



}



int main()

{

    Read();

    Do();



    return 0;

}

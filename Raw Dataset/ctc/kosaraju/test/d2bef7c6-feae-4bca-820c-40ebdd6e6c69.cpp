#include <bits/stdc++.h>
using namespace std;

ifstream fin( "ctc.in" );

ofstream fout( "ctc.out" );

void fast()

{

    cin.tie( 0 );

    ios_base::sync_with_stdio( 0 );

}

vector<int>g[100005], sol[100005];

vector<int>gt[100005];

vector<int>ord;

int use[100005];

int m, n, nrctc;

void dfs( int x )

{

    use[x] = 1;



    for( auto it : g[x] )

        if( !use[it] )

            dfs( it );



    ord.push_back( x );

}

void ctc( int x )

{

    sol[nrctc].push_back( x );

    use[x] = 1;



    for( auto it : gt[x] )

        if( !use[it] )

            ctc( it );

}

int main()

{

    fast();

    fin >> n >> m;



    for( int i = 1; i <= m; i++ )

        {

            int x, y;

            fin >> x >> y;

            g[x].push_back( y );

            gt[y].push_back( x );

        }



    for( int i = 1; i <= n; i++ )

        if( !use[i] )

            dfs( i );
    reverse( ord.begin(), ord.end() );



    for( int i = 1; i <= n; i++ )

        use[i] = 0;



    for( auto it : ord )

        if( !use[it] )

            {

                nrctc++;

                ctc( it );

            }



    fout << nrctc << '\n';



    for( int i = 1; i <= nrctc; i++ )

        {

            for( auto it : sol[i] )

                fout << it << ' ';



            fout << '\n';

        }



    return 0;

}

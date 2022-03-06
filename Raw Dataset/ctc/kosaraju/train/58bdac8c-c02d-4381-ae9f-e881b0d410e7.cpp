#include <bits/stdc++.h>


using namespace std;



const int NMAX = 100005;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int N, M, x, y;

vector < int > Ad[NMAX];

vector < int > Ad_r[NMAX];

vector < int > T;



bool viz[NMAX];



int ctc;

vector < int > C[NMAX];



void DFS( int nod )

{

    viz[nod] = 1;



    for( int i = 0; i < Ad[nod].size(); ++i )

    {

        int w = Ad[nod][i];



        if( !viz[w] )

            DFS( w );

    }

    T.push_back( nod );

}

void Read()

{

    fin >> N >> M;



    for( int i = 1; i <= M; ++i )

    {

        fin >> x >> y;

        Ad[x].push_back( y );

        Ad_r[y].push_back( x );

    }



    for( int i = 1; i <= N; ++i )

        if( !viz[i] )DFS( i );

    for( int i = 1; i <= N; ++i )

        viz[i] = 0;

}



void DFSr( int nod )

{

    viz[nod] = 1;

    C[ctc].push_back( nod );

    for( int i = 0; i < Ad_r[nod].size(); ++i )

    {

        int w = Ad_r[nod][i];



        if( !viz[w] )

            DFSr( w );

    }



}

void Solve()

{

    for( int i = T.size()-1; i >= 0; --i )

        if( !viz[T[i]] )

        {

            ctc++;

            DFSr( T[i] );

        }

    fout << ctc << '\n';



    for( int i = 1; i <= ctc; ++i ){

        for( int j = 0; j < C[i].size(); ++j )

            fout << C[i][j] << ' '; fout << '\n';}

}

int main()

{

    Read();

    Solve();

    return 0;

}

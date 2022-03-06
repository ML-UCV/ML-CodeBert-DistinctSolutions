#include <bits/stdc++.h>


using namespace std;



ifstream fin( "ctc.in" );

ofstream fout( "ctc.out" );



const int NMAX = 100005;



int N, M;

vector <int> Ad[NMAX];

vector <int> Adrev[NMAX];



vector <int> t_sort;

bool v[NMAX];



vector < vector<int> > sol;

vector <int> stk;



void Read() {

    fin >> N >> M;



    int a, b;

    for( int i = 1; i <= M; ++i ) {

        fin >> a >> b;



        Ad[a].push_back( b );

        Adrev[b].push_back( a );

    }

}



void T_dfs( int nod ) {

    v[nod] = true;



    int w;

    for( int i = 0; i < Ad[nod].size(); ++i ) {

        w = Ad[nod][i];



        if( !v[w] ) T_dfs( w );

    }



    t_sort.push_back( nod );

}



void TopoSort() {

    for( int i = 1; i <= N; ++i )

        if( !v[i] ) T_dfs( i );

}



void Dfs2( int nod ) {

    stk.push_back( nod );

    v[nod] = true;



    int w;

    for( int i = 0; i < Adrev[nod].size(); ++i ) {

        w = Adrev[nod][i];



        if( !v[w] ) Dfs2( w );

    }

}



void Do() {

    TopoSort();



    for( int i = 1; i <= N; ++i )

        v[i] = false;



    for( int i = t_sort.size() - 1; i >= 0; --i ) {

        int u = t_sort[i];



        if( v[u] ) continue;



        stk.clear();



        Dfs2( u );



        sol.push_back( stk );

    }
    fout << sol.size() << '\n';



    for( int i = 0; i < sol.size(); ++i ) {

        for( int j = 0; j < sol[i].size(); ++j )

            fout << sol[i][j] << ' ';

        fout << '\n';

    }

}



int main()

{

    Read();

    Do();



    return 0;

}

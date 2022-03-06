#include <fstream>
#include <vector>


enum { normal, transpus };



using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



int n, m, ctc, vis[100001], stack[100001], sp;



vector <int> G [100001];

vector <int> Gt[100001];



vector <int> sol[100001];



void DFS ( int nod, int Graf ) {

    vis[ nod ] = 1;



    int size = Graf == normal ? G[nod].size() : Gt[nod].size();

    for ( int l = 0; l < size; l++ ) {



        int to = Graf == normal ? G[nod][l] : Gt[nod][l];

        if ( !vis[to] )

            DFS ( to, Graf );

    }



    if ( Graf == normal )

        stack[ ++sp ] = nod;

    else

        sol[ctc].push_back ( nod );

}



void solve () {



    for ( int i = 1; i <= n; i++ )

        if ( ! vis[ i ] )

            DFS ( i, normal );



    for ( int i = 1; i <= n; i++ )

        vis[i] = 0;



    while ( sp > 0 ) {

        if ( ! vis[ stack[sp] ] ) {

            ctc++;

            DFS ( stack[sp], transpus );

        }

        sp--;

    }

}



void write () {



    fout << ctc << "\n";

    for (int i = 1; i <= ctc; i++) {

        for ( unsigned int l = 0; l < sol[i].size(); l++ ) {

            fout << sol[i][l] << " ";

        }

        fout << "\n";

    }

}



void read () {

    fin >> n >> m;



    int from, to;

    for (int i = 1; i <= m; i++) {

        fin >> from >> to;

        G[ from ].push_back (to);

        Gt[ to ].push_back (from);

    }

}



int main()

{

    read ();

    solve ();

    write ();

    return 0;

}

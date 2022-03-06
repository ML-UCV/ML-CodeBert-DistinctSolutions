#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;



ifstream in("party.in");

ofstream out("party.out");



const int NMAX = 200;



bool viz[NMAX+2];

vector <int> G[NMAX+2], GP[NMAX+2], ord;

int ind_ctc = 0;

int N, M;

int ctc[NMAX+2];



int normal( int x ) {

    if( x < 0 ) return -x;

    return x + N;

}



int negat( int x ) {

    if( x <= N ) return x + N;

    return x - N;

}



void Dfs_Plus( int nod ) {

    viz[nod] = 1;



    for( int i = 0; i < (int)G[nod].size(); ++i ) {

        int x = G[nod][i];

        if( !viz[x] ) {

            Dfs_Plus( x );

        }

    }



    ord.push_back( nod );

}



void Dfs_Minus( int nod ) {

    viz[nod] = 1;

    ctc[nod] = ind_ctc;



    for( int i = 0; i < (int)GP[nod].size(); ++i ) {

        int x = GP[nod][i];

        if( !viz[x] ) {

            Dfs_Minus( x );

        }

    }

}



void HueHue( int x, int y ) {

    G[ negat(x) ].push_back( y );

    G[ negat(y) ].push_back( x );



    GP[ y ].push_back( negat(x) );

    GP[ x ].push_back( negat(y) );

}



int main() {

    in >> N >> M;

    for( int i = 1; i <= M; ++i ) {

        int x,y, op;

        in >> x >> y >> op;

        if( op == 0 ) HueHue( x,y );

        else if( op == 1 ) HueHue( x, negat(y) );

        else if( op == 2 ) HueHue( y, negat(x) );

        else HueHue( negat(x), negat(y) );

    }



    for( int i = 1; i <= 2*N; ++i ) {

        if( !viz[i] ) Dfs_Plus(i);

    }

    memset( viz, 0, sizeof(viz) );

    for( int i = (int)ord.size() - 1; i >= 0; --i ) {

        if( !viz[ ord[i] ] ) {

            ++ind_ctc;



            Dfs_Minus( ord[i] );

        }

    }



    bool ok = 1;

    for( int i = 1; i <= N; ++i ) {

        if( ctc[i] == ctc[i + N] ) ok = 0;

    }

    if( !ok ) {

        out << "-1\n";

        return 0;

    }



    vector <int> sol;

    for( int i = 1; i <= N; ++i ) {

        if( ctc[i] > ctc[i + N] ) sol.push_back( i );

    }

    out << sol.size() << '\n';

    sort( sol.begin(), sol.end() );

    for( int i = 0; i < (int)sol.size(); ++i ) out << sol[i] << '\n';



    return 0;

}

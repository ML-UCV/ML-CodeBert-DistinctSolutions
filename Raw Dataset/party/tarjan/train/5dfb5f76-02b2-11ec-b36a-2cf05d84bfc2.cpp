#include <bits/stdc++.h>
using namespace std;

ifstream in ( "party.in" );
ofstream out( "party.out" );

const int DIM = 2e2 + 5;
const int INF = 0x3f3f3f3f;

int N, M, X, Y, Z, cnt, ans, Low[DIM], Lev[DIM], Sol[DIM];
vector<int> G[DIM]; vector<int> St;

inline int f( int X ) {
    return (X <= N) ? (X + N) : (X - N);
}

void dfs( int node ) {
    Low[node] = Lev[node] = ++ cnt;
    St.push_back( node );

    for( auto next : G[node] ) {
        if( Lev[next] == 0 )
            dfs( next );

        if( Lev[next] > 0 )
            Low[node] = min( Low[node], Low[next] );
    }

    if( Low[node] == Lev[node] ) {
        int aux;

        do {
            aux = St.back(); St.pop_back();
            Lev[aux] *= -1;

            if( Sol[aux] == 0 ) {
                Sol[aux] = 1;
                Sol[f(aux)] = -1;
            }
        } while( aux != node );
    }

    return;
}

int main( int argc, const char *argv[] ) {

    in >> N >> M;
    for( int i = 1; i <= M; i ++ ) {
        in >> X >> Y >> Z;

        switch( Z ) {
            case 0: {
                G[f(X)].push_back(Y);
                G[f(Y)].push_back(X);
                break;
            }
            case 1: {
                G[f(X)].push_back(f(Y));
                G[Y].push_back(X);
                break;
            }
            case 2: {
                G[f(Y)].push_back(f(X));
                G[X].push_back(Y);
                break;
            }
            case 3: {
                G[X].push_back(f(Y));
                G[Y].push_back(f(X));
                break;
            }
        }
    }

    for( int i = 1; i <= N * 2; i ++ ) {
        if( Lev[i] == 0 )
            dfs( i );
    }

    for( int i = 1; i <= N; i ++ ) {
        if( Sol[i] == 1 )
            ans ++;
    } out << ans << '\n';

    for( int i = 1; i <= N; i ++ ) {
        if( Sol[i] == 1 )
            out << i << "\n";
    }

    return 0;
}

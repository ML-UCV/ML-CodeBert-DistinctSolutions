#include<bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int DIM = 1e5 + 5;



int low[DIM], niv[DIM], cod, N, M, K;

bool f[DIM];

stack<int> st;

vector<int> edge[DIM], ctc[DIM];



void dfs( int nod ){

    niv[nod] = low[nod] = ++cod;

    st.push( nod );

    f[nod] = true;

    for( int i = 0; i < edge[nod].size(); i++ ){

        int vec = edge[nod][i];

        if( niv[vec] == 0 ){

            dfs( vec );

            low[nod] = min( low[nod], low[vec] );

        }else{

            if( f[vec] == true )

                low[nod] = min( low[nod], low[vec] );

        }

    }

    if( low[nod] == niv[nod] ){

        K++;

        while( !st.empty() && st.top() != nod ){

            ctc[K].push_back( st.top() );

            f[st.top()] = false;

            st.pop();

        }

        ctc[K].push_back( st.top() );

        f[st.top()] = false;

        st.pop();

    }

}



int main(){

    fin >> N >> M;

    for( int i = 1; i <= M; i++ ){

        int x, y; fin >> x >> y;

        edge[x].push_back( y );

    }



    for( int i = 1; i <= N; i++ ){

        if( niv[i] == 0 ){

            dfs( i );

        }

    }



    fout << K << "\n";

    for( int i = 1; i <= K; i++, fout << "\n" )

        for( int j = 0; j < ctc[i].size(); j++, fout << " " )

            fout << ctc[i][j];



    return 0;

}

#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 100000;

vector<int> G[NMAX + 1];

vector<int> G_transpose[NMAX + 1];

stack<int> st;

vector<vector<int>> sol;

vector<int> v;



int viz[NMAX + 1];



void dfs( int node ) {

  viz[node] = 1;



  for( const auto &it : G[node] ) {

    if( !viz[it] )

      dfs(it);

  }



  st.push(node);

}



void tareconexe( int node ) {

  viz[node] = 1;

  v.push_back(node);

  for( const auto &it : G_transpose[node] )

    if( !viz[it] )

      tareconexe(it);

}



int main() {

    int n, m;

    fin>>n>>m;

    for( int i = 1; i <= m; i ++ ) {

      int x, y;

      fin>>x>>y;

      G[x].push_back(y);

      G_transpose[y].push_back(x);

    }

    for( int i = 1; i <= n; i ++ ) {

      if( !viz[i] ) {

        dfs(i);

      }

    }

    memset(viz, 0 ,sizeof(viz));

    while( !st.empty() ) {

      int node = st.top();

      st.pop();

      if( !viz[node] ) {

        tareconexe(node);

        sol.push_back(v);

        v.clear();

      }

    }

    fout<<sol.size()<<"\n";

    for( int i = 0; i < sol.size(); i ++ ) {

      for( const auto &it : sol[i] )

        fout<<it<<" ";

      fout<<"\n";

    }

    return 0;

}

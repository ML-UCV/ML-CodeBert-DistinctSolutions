#include <fstream>
#include <vector>
#include <stack>




using namespace std;
ifstream in ( "ctc.in" );
ofstream out( "ctc.out" );
int n, m, i, x, y, nivel, ctc;
int niv[100100], low[100100], fr[100100];
vector<int> L[100100], sol[100100];
stack<int> s;

void dfs( int nod ){

nivel++;
niv[nod] = nivel;
low[nod] = nivel;
s.push(nod);
fr[nod] = 1;

for ( auto vecin: L[nod] )
    if ( !niv[vecin] ){
        dfs(vecin);
        low[nod] = min ( low[nod], low[vecin] );
    } else if ( fr[vecin] )
        low[nod] = min ( low[nod], low[vecin] );

if ( niv[nod] == low[nod] ){
    ctc++;
    x = nod;
    do {
        x = s.top();
        sol[ctc].push_back(x);
        fr[x] = 0;
        s.pop();
    } while ( x != nod );
}

}

int main() {

in>>n>>m;
for ( i=1; i <= m; i++ ){
    in>>x>>y;
    L[x].push_back(y);
}

for ( i=1; i <= n; i++ )
    if ( !niv[i] )
        dfs(i);

out<<ctc<<"\n";
for ( i=1; i <= ctc; i++, out<<"\n" )
    for ( auto nod: sol[i] )
        out<<nod<<" ";
return 0;
}

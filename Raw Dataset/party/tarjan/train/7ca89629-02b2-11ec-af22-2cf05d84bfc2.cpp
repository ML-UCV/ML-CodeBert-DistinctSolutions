#include<fstream>#include <cstring>
#include<vector>
#include<queue>
using namespace std;



const int MAX_N = 200007;

vector<int> G[MAX_N], Gt[MAX_N], L[MAX_N];

int C[MAX_N], P, N, M, viz[MAX_N], d[MAX_N], sol[MAX_N];

vector<int> A[MAX_N], pl;

queue<int>Q;

inline int non(int x) { return (x > N)?x-N:x+N; }

void DFP(int x)

{

 if(viz[x]) return;

 viz[x] = 1;

 int i;

 for(i = 0; i < (int)G[x].size(); ++i)

  DFP(G[x][i]);

 pl.push_back(x);

}

void DFM(int x)

{

 if(viz[x]) return;

 int i;

 C[x] = P; L[P].push_back(x); viz[x] = 1;

 for(i = 0; i < Gt[x].size(); ++i)

  DFM(Gt[x][i]);

}

int main()

{

 ifstream in("party.in"); ofstream out("party.out");

 in>>N>>M;

 int x, y, i, j, op, aux;

 for(i = 1; i <= M; ++i)

 {

  in>>x>>y>>op;

  if(op == 1) y = -y;

  else if (op == 2) { x = -x; }

  else if(op == 3) {x = -x, y = -y; }

  if(x < 0 ) x = -x + N;

  if(y < 0 ) y = -y + N;

  G[non(x)].push_back(y); Gt[y].push_back(non(x));

  G[non(y)].push_back(x); Gt[x].push_back(non(y));

 }

 for(i=1; i <= 2*N; ++i)

  if(!viz[i])

   DFP(i);

 memset(viz, 0, sizeof(viz));

 for(i = pl.size() - 1; i >= 0; --i)

  if( !viz[ pl[i] ] )

  {

   P++;

   DFM(pl[i]);

  }

 int ok = 1;

 for(i = 1; i <= N; ++i)

  if( C[i] == C[ non(i) ] ) ok = 0;

 if(ok == 0) { out<<"-1\n"; return 0; }



 for(x = 1; x <= 2*N; ++x)

  for(j = 0; j < (int)G[x].size(); ++j)

  {

   y = G[x][j];

   if( C[x] != C[y] )

   {

    A[ C[x]].push_back(C[y]);

    d[C[y]]++;

   }

  }

 for(i = 1; i <= P; ++i)

  if(d[i] == 0) Q.push(i);

 for(;!Q.empty();Q.pop())

 {

  x = Q.front();

  for(i = 0; i < L[x].size(); ++i)

  {

   y = L[x][i];

   if(sol[y]) continue;

   sol[y] = 1;

   sol[non(y)] = 2;

  }

  for(i = 0; i < A[x].size(); ++i)

  {

   y = A[x][i];

   d[y]--;

   if(d[y] == 0) Q.push(y);

  }

 }

 int cnt = 0;

 for(i = 1; i <= N; ++i)

  if(sol[i] == 2) ++cnt;

 out<<cnt<<"\n";

 for(i = 1; i <= N; ++i)

  if( sol[i] == 2) out<<i<<"\n";

 return 0;

}

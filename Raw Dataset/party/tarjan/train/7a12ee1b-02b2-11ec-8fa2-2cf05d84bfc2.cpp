#include <stdio.h>#include <cstring>
#include <vector>
using namespace std;





vector <int> G[210], Gt[210], V[210];

int C[210], R[210], out[210];

int viz[210], st[210];

int n, m, k;

int pun = 1, comp, pas;

inline int real(int x){

 if(x > 0) return x;

 return n-x;

}

inline void go_muchii(int x, int y){

 G[real(-x)].push_back(real(y));

 G[real(-y)].push_back(real(x));



 Gt[real(y)].push_back(real(-x));

 Gt[real(x)].push_back(real(-y));

}

void df(int x, vector<int> G[]){

 viz[x] = 1;

 if(!pas) C[x] = comp;

 for(vector<int>::iterator i = G[x].begin(); i != G[x].end(); ++i)

  if(!viz[*i])

   df(*i, G);

 out[x] = ++k;

 if(pun) st[++st[0]] = x;

}

void CTC(){

 for(int i = 1; i <= 2*n; ++i)

  if(!viz[i])

   df(i, G);

 pun = 0;

 memset(viz, 0, (2*n+3)*sizeof(viz[0]));

 for(int i = st[0]; i; --i)

  if(!viz[st[i]]){

   comp++;

   df(st[i], Gt);

  }



 for(int x = 1; x <= 2*n; ++x)

  for(vector<int>::iterator i = G[x].begin(); i != G[x].end(); ++i)

   if(C[x] != C[*i]) V[C[x]].push_back(C[*i]);



 memset(viz, 0, (2*n+3)*sizeof(viz[0]));

 k = 0;

 pas = 1;

 for(int x = 1; x <= comp; ++x)

  if(!viz[x])

   df(x, V);

}

void sat() {

 for(int x = 1; x <= n; ++x)

  if( out[C[x]] < out[C[real(-x)]]) R[C[x]] = 1;

  else R[C[real(-x)]] = 1;

 int c = 0;

 for(int i = 1; i <= n; ++i)

  if(R[C[i]]) c++;

 printf("%d\n", c);

 for(int i = 1; i <= n; ++i)

  if(R[C[i]]) printf("%d\n", i);

}

int main(){

 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);

 scanf("%d%d", &n, &m);

 for(int i = 1; i <= m; ++i){

  int x, y, c;

  scanf("%d%d%d", &x, &y, &c);

  if(c==0) ;

  else if(c == 1) y = -y;

  else if(c==2) x = -x;

  else {x = -x; y = -y;}

  go_muchii(x, y);

 }

 CTC();

 sat();

 return 0;

}

#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

typedef pair<int, double> graf;
vector <graf> G[1510];

int NR[1510], H[1510];

bool in[1510];

double D[1510];

int n, m, nr;

double make_abs(double a){

 if(a > 0) return a;

 return -a;

}

int egal(double a, double b){

 if(make_abs(a-b) <= 1e-8)

  return 1;

 return 0;

}

void down_heap(int k){

 int son = 1;

 while(son){

  son = 0;

  if(2*k <= nr) son = 2*k;

  if(2*k+1 <= nr && D[H[2*k+1]] < D[H[2*k]]) son ++;

  if(son && D[H[son]] < D[H[k]]){

   swap(H[son], H[k]);

   k = son;

  }

  else son = 0;

 }

}

void up_heap(int k){

 while(k > 1 && D[H[k]] < D[H[k/2]]){

  swap(H[k], H[k/2]);

  k /= 2;

 }

}

void push_heap(int x){

 H[++nr] = x;

 in[x] = true;

 up_heap(nr);

}

int pop_heap(){

 int x = H[1];

 swap(H[1], H[nr]);

 nr--;

 down_heap(1);

 in[x] = false;

 return x;

}

int mic(double a, double b){

 if(b-a > 1e-8)

  return 1;

 return 0;

}

void dij(){

 push_heap(1);

 NR[1] = 1;

 int x, nod;

 double dist;

 while(nr){

  x = pop_heap();

  for(vector<graf>::iterator i = G[x].begin(); i != G[x].end(); ++i){

   nod = i -> first;

   dist = i -> second;

   if(mic(D[x] + dist , D[nod])){

    D[nod] = D[x] + dist;

    NR[nod] = NR[x];

    if(!in[nod]) push_heap(nod);

   }

   else if(egal(D[x] + dist , D[nod])){

    NR[nod] = (NR[nod] + NR[x])%104659;

    if(!in[nod]) push_heap(nod);

   }

  }





 }

 for(int i = 2; i < n; ++i)

  printf("%d ", NR[i]);

 printf("%d\n", NR[n]);

}

int main(){

 freopen("dmin.in", "r", stdin);

 freopen("dmin.out", "w", stdout);

 scanf("%d%d", &n, &m);

 for(int i = 1; i <= m; ++i){

  int x, y, z;

  double r;

  scanf("%d%d%d", &x, &y, &z);

  r = log10(z);

  G[x].push_back(graf(y,r));

  G[y].push_back(graf(x,r));

 }

 for(int i = 2; i <= n; ++i)

  D[i] = 2000000000;

 dij();

 return 0;

}

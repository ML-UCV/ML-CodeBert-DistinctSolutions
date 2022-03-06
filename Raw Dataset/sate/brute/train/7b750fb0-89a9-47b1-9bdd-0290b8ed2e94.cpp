#include<stdio.h>
#include<vector>
#include<utility>
#define NMAX 30001
using namespace std;
vector < pair<int, int> > v[NMAX];
long long viz[NMAX];
int stiv [NMAX];
int main (){
  FILE *in,*out;
  in = fopen ("sate.in","r");
  out = fopen ("sate.out","w");
  int n,m,i,nods,nodf,inc,sf,pp,a,b,l,nod,DIM;
  fscanf(in,"%d%d%d%d",&n,&m,&nods,&nodf);
  for (i=1;i<=m;i++){
    fscanf(in,"%d%d%d",&a,&b,&l);
    v[a].push_back(make_pair(b,l));
    v[b].push_back(make_pair(a,l));/// reciproca
  }

  for (i=1;i<=n;i++)
    viz[i] = -1LL;
  inc = sf = 1;
  stiv[inc] = nods;
  viz[nods] = 0LL;
  pp = 0;
  while (inc <= sf && pp == 0){
    nod = stiv[inc];
    DIM = v[nod].size();
    for (i = 0; i < DIM;i ++){
      if (viz[v[nod][i].first] == -1){
        if (v[nod][i].first > nod)
          viz[v[nod][i].first] = viz[nod] + v[nod][i].second;
        else
          viz[v[nod][i].first] = viz[nod] - v[nod][i].second;
        stiv[++sf] = v[nod][i].first;
      ///if (v[nod][i].first == nodf)
      ///  pp = 1;
      }
    }
    inc ++;
  }

  fprintf(out,"%d",viz[nodf]);



  fclose (in);
  fclose (out);
  return 0;
}



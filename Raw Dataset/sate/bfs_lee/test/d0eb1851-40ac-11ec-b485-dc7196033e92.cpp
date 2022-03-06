#include <stdio.h>

using namespace std;

#include <vector>
#include <queue>
#define NMAX 30000
#define MMAX 100024

struct edge{
  int to;
  int cost;
};
vector <edge> g[NMAX+1];
queue <int> q;

int dist[NMAX+1],viz[NMAX+1];

void bfs(int nod){
  int i,first;
  viz[nod]=1;
  q.push(nod);
  while(!q.empty()){
    first=q.front();
    for(auto next : g[first]){
      if(viz[next.to]==0){
        viz[next.to]=1;
        dist[next.to]=dist[first]+next.cost;
        q.push(next.to);
      }
    }
    q.pop();
  }
}

int main()
{
  FILE *fin,*fout;
  fin=fopen("sate.in","r");
  fout=fopen("sate.out","w");

  int n,m,x,y,i,j,d,k;
  fscanf(fin,"%d%d%d%d",&n,&m,&x,&y); ///dist de la nodul x la nodul y
  for(k=1;k<=m;k++){
    fscanf(fin,"%d%d%d",&i,&j,&d); ///i-j muchie, d = dist intre muchii
    g[i].push_back({j,d});///se pun in ordinea campurilor din struct
    g[j].push_back({i,-d});
  }
  bfs(x);
  fprintf(fout,"%d",dist[y]); ///distanta de la x la y

  fclose(fin);
  fclose(fout);
  return 0;
}

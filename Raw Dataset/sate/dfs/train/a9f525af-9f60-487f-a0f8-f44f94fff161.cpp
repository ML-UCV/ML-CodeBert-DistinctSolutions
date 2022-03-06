#include <bits/stdc++.h>
using namespace std;


#define MAXN 30001
vector < pair <int, int> > v[MAXN];
bool viz[MAXN];
int drum[MAXN];
int b, a, ans;
int dfs(int nod) {
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++) {
      pair <int, int> it = v[nod][i];
      if(viz[it.first] == 0){
        drum[it.first]=drum[nod]+it.second;
        //printf("%d %d\n", it.first, drum[it.first]);
        if(it.first==b){
          return 0;
        }
        dfs(it.first);
      }

    }
}

int main(){
  FILE*fin=fopen("sate.in", "r");
  FILE*fout=fopen("sate.out", "w");
  int n, m, a, b, i, x, y, c;
  fscanf(fin, "%d%d%d%d", &n, &m, &a, &b);
  for(i=1; i<=m; i++){
    fscanf(fin, "%d%d%d", &x, &y, &c);
    v[x].push_back({y, c});
    v[y].push_back({x, -c});
  }
  ans=0;
  dfs(a);
  if(b>a)
    fprintf(fout, "%d", drum[b]);
  else
    fprintf(fout, "%d", -drum[b]);
  return 0;
}

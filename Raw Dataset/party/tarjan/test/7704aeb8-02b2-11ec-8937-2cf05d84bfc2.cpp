#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;



int I[205], minI[205], index, S[205], inS[205], t;
int scc_cnt, node_to_scc[205], scc_in_deg[205];
vector<int> G[205], scc_G[205], scc_list[205];

inline int non(int x, int N){
  return (x > N)? x-N: x+N;
}

void scc(int n){

  I[n]=minI[n]=++index;
  S[++t]=n; inS[n]=1;

  vector<int>::iterator ii;
  for(ii=G[n].begin(); ii!=G[n].end(); ii++){
    if(I[*ii] == -1){
      scc(*ii);
      minI[n]=min(minI[n], minI[*ii]);
    }
    else if(inS[*ii])
      minI[n]=min(minI[n], minI[*ii]);
  }

  if(I[n] == minI[n]){
    scc_cnt++;
    do {
      node_to_scc[S[t]]=scc_cnt;
      scc_list[scc_cnt].push_back(S[t]);
      inS[S[t]]=0;
    } while(S[t--] != n);
  }

}

int main(){

  freopen("party.in", "r", stdin);
  freopen("party.out", "w", stdout);

  int N, M, i, a, b, c, l, r, n, aux, guest;
  static int Q[205], value[205];
  vector<int>::iterator ii;

  scanf("%d%d", &N, &M);
  for(i=0; i<M; i++){
    scanf("%d%d%d", &a, &b, &c);

    if(c==1)
      b=non(b, N);
    else if(c==2)
      a=non(a, N);
    else if(c==3){
      a=non(a, N);
      b=non(b, N);
    }

    G[non(a, N)].push_back(b);
    G[non(b, N)].push_back(a);
  }

  for(i=1; i<=(N<<1); i++){
    I[i]=-1;
    value[i]=-1;
  }

  index=-1; t=-1; guest=0;

  for(i=1; i<=(N<<1); i++)
    if(I[i] == -1)
      scc(i);

  for(i=1; i<=(N<<1); i++)
    for(ii=G[i].begin(); ii!=G[i].end(); ii++)
      if(node_to_scc[i] != node_to_scc[*ii]){
 scc_G[node_to_scc[i]].push_back(node_to_scc[*ii]);
 scc_in_deg[node_to_scc[*ii]]++;
      }

  r=-1;
  for(i=1; i<=scc_cnt; i++)
    if(scc_in_deg[i] == 0)
      Q[++r]=i;

  for(l=0; l<=r; l++){
    n=Q[l];
    for(ii=scc_list[n].begin(); ii!=scc_list[n].end(); ii++){
      aux=(*ii > N)? *ii-N: *ii;
      if(value[aux] == -1){
 value[aux]=(*ii > N)? 1: 0;
 guest+=value[aux];
      }
    }
    for(ii=scc_G[n].begin(); ii!=scc_G[n].end(); ii++){
      scc_in_deg[*ii]--;
      if(scc_in_deg[*ii] == 0)
 Q[++r]=*ii;
    }
  }

  printf("%d\n", guest);
  for(i=1; i<=N; i++)
    if(value[i])
      printf("%d\n", i);

  return 0;

}

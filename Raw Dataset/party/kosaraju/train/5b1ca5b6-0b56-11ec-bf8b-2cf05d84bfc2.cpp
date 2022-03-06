#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;



const int N=200000+7;

int n,m,top,o[N],tip[N],cur;

bool one[N];

bool vis[N];

vector<int> g[N],ginv[N];



void dfs1(int a) {

  vis[a]=1;

  for (auto &b:g[a]) {

    if (vis[b]==0) {

      dfs1(b);

    }

  }

  o[++top]=a;

}



void dfs2(int a) {

  vis[a]=1;

  tip[a]=cur;

  for (auto &b:ginv[a]) {

    if (vis[b]==0) {

      dfs2(b);

    }

  }

}



signed main() {

  freopen ("party.in","r",stdin);

  freopen ("party.out","w",stdout);



  scanf("%d%d",&n,&m);



  for (int i=1;i<=m;i++) {

    int x,y,t;

    scanf("%d%d%d",&x,&y,&t);

    if (t==0) {

      g[x+n].push_back(y);

      g[y+n].push_back(x);

    }

    if (t==1) {

      g[x+n].push_back(y+n);

      g[y].push_back(x);

    }

    if (t==2) {

      g[x].push_back(y);

      g[y+n].push_back(x+n);

    }

    if (t==3) {

      g[x].push_back(y+n);

      g[y].push_back(x+n);

    }



  }



  for (int i=1;i<=2*n;i++) {

    for (auto &j : g[i]) {

      ginv[j].push_back(i);

    }

  }



  for (int i=1;i<=2*n;i++) {

    if (vis[i]==0) {

      dfs1(i);

    }

  }

  for (int i=1;i<=2*n;i++) {

    vis[i]=0;

  }

  for (int i=2*n;i>=1;i--) {

    int node=o[i];

    if (vis[node]==0) {

      cur++;

      dfs2(node);

    }

  }

  int cnt=0;

  for (int i=1;i<=n;i++) {

    cnt+=(tip[i]>tip[i+n]);

  }

  printf("%d\n",cnt);

  for (int i=1;i<=n;i++) {

    if (tip[i]>tip[i+n]) {

      printf("%d\n",i);

    }

  }

  return 0;

}

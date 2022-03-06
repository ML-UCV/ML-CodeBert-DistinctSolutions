#include <cstdio>
#include <vector>


using namespace std;



const int N=100000+7;

int n,m,top,o[N],sol[N],tip[N],cur;

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

  sol[++top]=a;

  tip[top]=cur;

  for (auto &b:ginv[a]) {

    if (vis[b]==0) {

      dfs2(b);

    }

  }

}



signed main() {

  freopen ("ctc.in","r",stdin);

  freopen ("ctc.out","w",stdout);



  scanf("%d%d",&n,&m);

  for (int i=1;i<=m;i++) {

    int x,y;

    scanf("%d%d",&x,&y);

    g[x].push_back(y);

    ginv[y].push_back(x);

  }

  for (int i=1;i<=n;i++) {

    if (vis[i]==0) {

      dfs1(i);

    }

  }

  for (int i=1;i<=n;i++) {

    vis[i]=0;

  }

  top=0;

  for (int i=n;i>=1;i--) {

    int node=o[i];

    if (vis[node]==0) {

      cur++;

      dfs2(node);

    }

  }

  printf("%d",cur);

  for (int i=1;i<=n;i++) {

    if (tip[i]!=tip[i-1]) {

      printf("\n");

    }

    printf("%d ",sol[i]);

  }

  return 0;

}

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>






using namespace std;



int n,m,x,y,ans;

bool acc[100010];

vector<int> nn[100010],nt[100010],cc[100010],vn;



void dfs(int nod,vector<int> nd[100010],vector<int> &ca){

  acc[nod]=1;

  for(auto i:nd[nod])

    if(!acc[i]){

      dfs(i,nd,ca);

    }

  ca.push_back(nod);

}



int main()

{

    ifstream f ("ctc.in");

    ofstream g ("ctc.out");

    f>>n>>m;

    for(int i=1;i<=m;i++)

      f>>x>>y,

      nn[x].push_back(y),

      nt[y].push_back(x);

    for(int i=1;i<=n;i++)

      if(!acc[i])dfs(i,nn,vn);

    for(int i=1;i<=n;i++)acc[i]=0;

    for(auto i:vn) cout<<i<<" ";

    for(int i=n;i>=1;i--)

      if(!acc[vn[i-1]])dfs(vn[i-1],nt,cc[++ans]);

    g<<ans<<'\n';

    for(int i=1;i<=ans;i++){

      for(auto j:cc[i])g<<j<<" ";

      g<<'\n';

    }

    f.close ();

    g.close ();

    return 0;

}

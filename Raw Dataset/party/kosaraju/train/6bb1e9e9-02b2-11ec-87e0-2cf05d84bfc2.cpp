#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;







vector <int> v[201],vt[201],SCC[201];

int viz[201],p[201],sol[201],poz[201],n,nr;



inline int NEG(int x)

{

 int aux = x + n;

 if(aux>2*n)

  aux=aux-2*n;

 return aux;

}



void dfs(int nod)

{

 viz[nod]=1;

 for(vector <int> :: iterator it=v[nod].begin();it!=v[nod].end();it++)

  if(viz[*it]==0)

   dfs(*it);

 p[++p[0]]=nod;

}



void dfst(int nod)

{

 viz[nod]=1;

 SCC[nr].push_back(nod);

 poz[nod]=nr;

 for(vector <int> :: iterator it=vt[nod].begin();it!=vt[nod].end();it++)

  if(viz[*it]==0)

   dfst(*it);

}



int main ()

{

 int m,i,x,y,opt;

 ifstream f("party.in");

 ofstream g("party.out");

 f>>n>>m;

 for(i=1;i<=m;i++) {

  f>>x>>y>>opt;

  if(opt==1)

   y=y+n;

  if(opt==2)

   x=x+n;

  if(opt==3) {

   x=x+n;

   y=y+n;

  }

  v[NEG(x)].push_back(y);

  v[NEG(y)].push_back(x);

  vt[y].push_back(NEG(x));

  vt[x].push_back(NEG(y));

 }

 f.close();

 for(i=1;i<=2*n;i++)

  if(viz[i]==0)

   dfs(i);

 memset(viz,0,sizeof(viz));

 for(i=p[0];i>=1;i--)

  if(viz[p[i]]==0) {

   nr++;

   dfst(p[i]);

  }

 for(i=1;i<=2*n;i++)

  sol[i]=-1;

 for(i=nr;i>=1;i--) {

  if(sol[SCC[i][0]]!=-1)

   continue;

  for(vector <int> :: iterator it=SCC[i].begin();it!=SCC[i].end();it++) {

   sol[*it]=1;

   sol[NEG(*it)]=0;

  }

 }

 nr=0;

 for(i=1;i<=n;i++)

  nr=nr+sol[i];

 g<<nr<<'\n';

 for(i=1;i<=n;i++)

  if(sol[i])

   g<<i<<'\n';

 g.close();

 return 0;

}

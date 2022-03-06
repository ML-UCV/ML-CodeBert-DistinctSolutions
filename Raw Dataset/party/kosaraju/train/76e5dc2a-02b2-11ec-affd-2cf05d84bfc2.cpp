#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;





vector<int> v[10004],vt[10004];
int t[10004],nrt,n,m,sol[10004];
int a=0,b=0,tip=-1;
char viz[10004];

void dfs(int nod)
{
 viz[nod]=1;
 int i,vec,lim=v[nod].size();

 for(i=0;i<lim;i++)
  if(!viz[vec=v[nod][i]])
   dfs(vec);
 t[++nrt]=nod;
}

void dfs2(int nod)
{
 viz[nod]=1;
 sol[(nod<=n ? nod+n : nod-n)]=1;

 int i,vec,lim=vt[nod].size();

 for(i=0;i<lim;i++)
  if(!viz[vec=vt[nod][i]])
   dfs2(vec);

}

int main ()
{
 int i;

 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);

 scanf("%d%d",&n,&m);

 for(i=1;i<=m;i++)
 {
  scanf("%d%d%d",&a,&b,&tip);


  if(!tip)
  {
   v[(a<=n ? a+n : a-n)].push_back(b);
   v[(b<=n ? b+n : b-n)].push_back(a);
   vt[b].push_back((a<=n ? a+n : a-n));
   vt[a].push_back((b<=n ? b+n : b-n));
  }
  else if(tip==1)
  {
   v[(a<=n ? a+n : a-n)].push_back((b<=n ? b+n : b-n));
   vt[(b<=n ? b+n : b-n)].push_back((a<=n ? a+n : a-n));
   v[b].push_back(a);
   vt[a].push_back(b);

  }
  else if(tip==2)
  {
   v[(b<=n ? b+n : b-n)].push_back((a<=n ? a+n : a-n));
   vt[(a<=n ? a+n : a-n)].push_back((b<=n ? b+n : b-n));
   v[a].push_back(b);
   vt[b].push_back(a);
  }
  else
  {
   vt[(a<=n ? a+n : a-n)].push_back(b);
   vt[(b<=n ? b+n : b-n)].push_back(a);
   v[b].push_back((a<=n ? a+n : a-n));
   v[a].push_back((b<=n ? b+n : b-n));

  }

 }

 for(i=1;i<=2*n;i++)
  if(!viz[i])
   dfs(i);
 memset(viz,0,sizeof(viz));


 for(i=2*n;i>=1;i--)
  if(!viz[t[i]] && !viz[(t[i]<=n ? t[i]+n : t[i]-n)])
   dfs2(t[i]);

 for(i=1;i<=n;i++)
  if(sol[i])
   sol[0]++;

 printf("%d\n",sol[0]);

 for(i=1;i<=n;i++)
  if(sol[i])
   printf("%d\n",i);
 return 0;
}

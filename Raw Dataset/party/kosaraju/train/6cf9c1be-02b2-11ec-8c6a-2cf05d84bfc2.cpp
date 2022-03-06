#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>

using namespace std;

const int nmax = 105;

int n,m,i,x,y,z,tsort[2*nmax],cnt,comp[2*nmax],sol;

vector<int> v[2*nmax];

vector<int> vt[2*nmax];

bool viz[2*nmax];
void dfs(int x)

{

    (viz+nmax)[x]=1;

    for(vector<int>::iterator it=(v+nmax)[x].begin();it!=(v+nmax)[x].end();it++)

        if(!(viz+nmax)[*it]) dfs(*it);

    tsort[++cnt]=x;

}



void dfst(int x)

{

    (viz+nmax)[x]=1; (comp+nmax)[x]=cnt;

    for(vector<int>::iterator it=(vt+nmax)[x].begin();it!=(vt+nmax)[x].end();it++)

        if(!(viz+nmax)[*it]) dfst(*it);

}


int main()
{
 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);
 scanf("%d%d",&n,&m);

 for(;m;m--)

 {

     scanf("%d%d%d",&x,&y,&z);

     if(z==1) y=-y;

     else if(z==2) x=-x;

     else if(z==3) x=-x,y=-y;

     (v+nmax)[-x].push_back(y);

        (v+nmax)[-y].push_back(x);

        (vt+nmax)[y].push_back(-x);

        (vt+nmax)[x].push_back(-y);

 }



 for(i=-n;i<=n;i++) if(!(viz+nmax)[i] && i) dfs(i);

    for(i=-n;i<=n;i++) (viz+nmax)[i]=0; cnt=0;

    for(i=2*n;i;i--) if(!(viz+nmax)[tsort[i]]) {cnt++; dfst(tsort[i]);}



    for(i=1;i<=n;i++) if((comp+nmax)[i]>(comp+nmax)[-i]) sol++; printf("%d\n",sol);

    for(i=1;i<=n;i++) if((comp+nmax)[i]>(comp+nmax)[-i]) printf("%d\n",i);


 return 0;
}

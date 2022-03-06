#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>


using namespace std;
int n,m;

vector<int> G[232133];

vector<int> Gt[232133];

int ok,nr;

int viz[232133];

int sol[232133];

int ord[232133];





inline int neg(int a)

{

    if (a>n)

        return a-n;

    else

        return a+n;

}



void baga(int x, int y)

{

 G[2*n-x+1].push_back(y);

    G[2*n-y+1].push_back(x);

 Gt[y].push_back(2*n-x+1);

 Gt[x].push_back(2*n-y+1);

}





void citire()

{

    int i,a,b,c;

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    scanf("%d %d", &n, &m);

    while(m--)

    {

        scanf("%d %d %d", &a, &b,&c);

        a+=n*((c&2)!=0);

        b+=n*(c&1);

        G[neg(a)].push_back(b);

        Gt[b].push_back(neg(a));

        G[neg(b)].push_back(a);

        Gt[a].push_back(neg(b));



    }



}



void dfs(int nod)

{

 int i;

 if (viz[nod])

  return ;

 viz[nod]=1;

 for (i=0;i<G[nod].size();++i)

   if (!viz[G[nod][i]])

    dfs(G[nod][i]);

 ord[++nr]=nod;

}



void dfst(int nod)

{

 int i;

 if (viz[nod])

  return ;

 viz[nod]=1;

 if (sol[nod]) ok=0;

 sol[neg(nod)]=1;

 for (i=0;i<Gt[nod].size();++i)

   if (!viz[Gt[nod][i]])

    dfst(Gt[nod][i]);

}





void solve()

{

    int i;

    ok=1;

    nr=0;

    for (i=1;i<=2*n;++i)

          if (!viz[i])

             dfs(i);

    memset(viz,0,sizeof(viz));

    for (i=2*n;i>=1;--i)

         if (!viz[ord[i]] && !viz[neg(ord[i])])

             dfst(ord[i]);

    nr=0;

    for (i=1;i<=n;++i)

         if (sol[i]) {



             nr++;

         }

         printf("%d\n", nr);

   for (i=1;i<=n;++i)

         if (sol[i]) {

             printf("%d\n", i);



         }

}



int main()

{

    citire();

    solve();



    fclose(stdin);

    fclose(stdout);



    return 0;

}

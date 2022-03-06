#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int nmax=205;

vector<int> v[nmax],vt[nmax];

bool viz[nmax],val[nmax],ap[nmax];

int r[nmax];

int i,j,n,x,m,tip,y,k,nr;

inline int no(int x)

{

    if(x<=n) return n+x;

    return x-n;

}

void dfs(int x)

{

    viz[x]=1;

   for(int i=0;i<v[x].size();i++)

     if(!viz[v[x][i]])

        dfs(v[x][i]);

    k++;r[k]=x;

}

void dfst(int x)

{

    viz[x]=0;val[x]=0;val[no(x)]=1;

    for(int i=0;i<vt[x].size();i++)

        if(viz[vt[x][i]])

         dfst(vt[x][i]);

}

int main()

{

    ifstream f("party.in");

    ofstream g("party.out");

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y>>tip;

        if(tip==0)

        {



            v[no(x)].push_back(y);

            vt[y].push_back(no(x));

            v[no(y)].push_back(x);

            vt[x].push_back(no(y));

        }

        if(tip==1)

        {



            v[no(x)].push_back(no(y));

            vt[no(y)].push_back(no(x));

            v[y].push_back(x);

            vt[x].push_back(y);

        }

        if(tip==2)

        {



            v[x].push_back(y);

            vt[y].push_back(x);

            v[no(y)].push_back(no(x));

            vt[no(x)].push_back(no(y));

        }

        if(tip==3)

        {



            v[x].push_back(no(y));

            vt[no(y)].push_back(x);

            v[y].push_back(no(x));

            vt[no(x)].push_back(y);

        }

    }

    for(i=1;i<=2*n;i++)

        if(!viz[i])

        dfs(i);

    for(i=2*n;i>=1;i--)

    {

        x=r[i];

        if(viz[x]&&viz[no(x)])dfst(x);

        if(val[x]&&x<=n)

            nr++;

    }

    g<<nr<<'\n';

    for(i=1;i<=n;i++)

        if(val[i])

            g<<i<<'\n';

    return 0;

}

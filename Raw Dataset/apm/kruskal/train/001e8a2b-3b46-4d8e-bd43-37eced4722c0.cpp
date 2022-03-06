#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n,m,sol=0,tata[200005];

vector< pair<int,int> >vecini[200005];

bool fost[200005];



set< pair<int,pair<int,int> > >perechi;



void adauga(int nod)

{

    for(int i=0; i<vecini[nod].size(); i++)

    {

        int x=vecini[nod][i].first;

        int y=vecini[nod][i].second;

        if(!fost[x])

        {

            perechi.insert( make_pair( y,make_pair(x,nod) ) );

        }

    }

}



void dfs(int nod)

{

    fost[nod]=1;

    adauga(nod);

    while( !perechi.empty() )

    {

        int cost=perechi.begin()->first;

        int x=perechi.begin()->second.first;

        int plecare=perechi.begin()->second.second;

        perechi.erase(perechi.begin());



        if(!fost[x])

        {

            tata[x]=plecare;

            sol+=cost;

            dfs(x);

        }

    }

}



int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x,y,z;

        f>>x>>y>>z;

        vecini[x].push_back(make_pair(y,z));

        vecini[y].push_back(make_pair(x,z));

    }

    dfs(1);

    g<<sol;

    g<<'\n';

    g<<n-1;

    g<<'\n';

    for(int i=2; i<=n; i++) g<<i<<' '<<tata[i]<<'\n';

}

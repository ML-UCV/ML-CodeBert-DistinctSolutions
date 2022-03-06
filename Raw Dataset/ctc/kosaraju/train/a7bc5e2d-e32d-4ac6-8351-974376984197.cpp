#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



stack <int> S;

vector <int> V[100005],Copie,V1[100005];

int n,m;

bitset <100005> viz;

vector <vector <int> > Sol;

void dfs(int x)

{

    viz[x]=true;

    for(int i=0; i<V[x].size(); i++)

        if(!viz[V[x][i]])

            dfs(V[x][i]);

    S.push(x);

}

void dfs2(int x)

{

    Copie.push_back(x);

    viz[x]=0;

    for(int i=0; i<V1[x].size(); i++)

        if(viz[V1[x][i]])

            dfs2(V1[x][i]);

}

int main()

{

    f>>n>>m;

    while(m--)

    {

        int x,y;

        f>>x>>y;

        V[x].push_back(y);

        V1[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfs(i);

    for(; !S.empty(); S.pop())

        if(viz[S.top()])

        {

            dfs2(S.top());

            Sol.push_back(Copie);

            Copie.clear();

        }

    g<<Sol.size()<<'\n';

    for(int i=0;i<Sol.size();i++,g<<'\n')

        for(int j=0;j<Sol[i].size();j++)

        g<<Sol[i][j]<<' ';

    return 0;

}

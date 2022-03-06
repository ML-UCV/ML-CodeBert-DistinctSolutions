#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in ("ctc.in");

ofstream out("ctc.out");

vector <vector <int> > muchii[2];

vector <bool> marcat;

vector <int> sortat;

vector <vector <int> > componente;

vector <int> componentaTata;

int n, m, x, y;

void dfs(int nod)

{

    marcat[nod]=true;

    for(auto & x:muchii[0][nod])

        if(!marcat[x])

            dfs(x);

    sortat.push_back(nod);

}

void topologica()

{

    for(int i=1; i<=n; i++)

        if(!marcat[i])

            dfs(i);

    reverse(sortat.begin(), sortat.end());

}

void dfs2(int nod)

{

    if(!componentaTata[nod])

    {

        componentaTata[nod]=componente.size();

        componente.back().push_back(nod);

        for(auto & x : muchii[1][nod])

            dfs2(x);

    }

}

void Kosaraju()

{

    for(auto & nod : sortat)

        if(!componentaTata[nod])

        {

            componente.push_back(vector <int>());

            dfs2(nod);

        }

}

int main()

{

    in>>n>>m;

    marcat.resize(n+1, false);

    componentaTata.resize(n+1, 0);

    muchii[0].resize(n+1); muchii[1].resize(n+1);

    for(int i=1; i<=m; i++)

    {

        in>>x>>y;

        muchii[0][x].push_back(y);

        muchii[1][y].push_back(x);

    }

    topologica();

    Kosaraju();

    out<<componente.size()<<"\n";

    for(auto & vec:componente)

    {

        for(auto & x:vec)

            out<<x<<" ";

        out<<"\n";

    }

    return 0;

}

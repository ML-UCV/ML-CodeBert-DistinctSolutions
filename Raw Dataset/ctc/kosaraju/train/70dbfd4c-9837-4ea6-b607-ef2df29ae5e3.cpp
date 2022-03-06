#include <bits/stdc++.h>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



list <int> topoSort;

vector < vector <int> > la;

vector < vector <int> > li;

vector < vector <int> > componenta;

int n,m,nrComponente;

bool used[100002];



void citire()

{

    f >> n >> m;

    la.resize(n+1);

    li.resize(n+1);

    for(int i=1;i<=m;++i)

    {

        int x,y;

        f >> x >> y;

        la[x].push_back(y);

        li[y].push_back(x);

    }

}



void dfs(int x)

{

    used[x] = 1;

    for(int i : la[x])

        if(!used[i])dfs(i);

    topoSort.push_front(x);

}



void puneInComponenta(int x,int nrComp)

{

    componenta[nrComp].push_back(x);

    used[x] = 1;

    for(int i : li[x])

        if(!used[i])

            puneInComponenta(i,nrComp);

}



void Kosaraju()

{

    for(int i=1;i<=n;++i)

        if(!used[i])dfs(i);



    memset(used,0,sizeof(used));

    componenta.resize(n+1);



    for(int i : topoSort)

        if(!used[i])puneInComponenta(i,nrComponente++);



    componenta.resize(nrComponente+1);

    g << nrComponente << '\n';

    for(vector <int> i : componenta)

    {

        for(int j : i)g << j << ' ';

        g << '\n';

    }

}



int main()

{

    citire();

    Kosaraju();

}

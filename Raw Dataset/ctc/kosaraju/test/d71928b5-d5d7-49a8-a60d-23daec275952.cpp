#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, nr_ctc;

int vizitat[100005];

vector <int> G[100005], GT[100005], CTC[100005];

stack <int> Stiva;



void read()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x, y;

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void dfs_graf(int nod)

{

    vizitat[nod]=1;

    for(int i=0;i<G[nod].size();i++)

    {

        int vecin=G[nod][i];

        if(vizitat[vecin]==0)

            dfs_graf(vecin);

    }

     Stiva.push(nod);

}



void dfs_graf_transpus(int nod)

{

    vizitat[nod]=2;

    CTC[nr_ctc].push_back(nod);

    for(int i=0;i<GT[nod].size();i++)

    {

        int vecin=GT[nod][i];

        if(vizitat[vecin]==1)

            dfs_graf_transpus(vecin);

    }

}



void solutie()

{

    int i, j;

    for(i=1;i<=n;i++)

        if(vizitat[i]==0)

            dfs_graf(i);

    while(!Stiva.empty())

    {

        int nod=Stiva.top();

        if(vizitat[nod]==1)

        {

            nr_ctc++;

            dfs_graf_transpus(nod);

        }

        Stiva.pop();

    }

    fout<<nr_ctc<<'\n';

    for(i=1;i<=nr_ctc;i++)

    {

        for(j=0;j<CTC[i].size();j++)

            fout<<CTC[i][j]<<" ";

        fout<<'\n';

    }



}



int main()

{

    read();

    solutie();

    return 0;

}

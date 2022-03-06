#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector<int>G[100005];

vector<int>GT[100005];

vector<int>CTC[100005];

int sortt[100005];

int N, M;

int cicluri;

short int frec[100005];

int dfs(int nod)

{

    frec[nod] = 1;

    for(int i=0; i<G[nod].size(); i++)

    {

        int vecin = G[nod][i];

        if(frec[vecin] == 0)

        {

            dfs(vecin);

        }

    }

    sortt[++sortt[0]] = nod;

}

int dfs_t(int nod)

{

    frec[nod] = 2;

    CTC[cicluri].push_back(nod);

    for(int i=0; i<GT[nod].size(); i++)

    {

        int vecin = GT[nod][i];

        if(frec[vecin] == 1)

        {

            dfs_t(vecin);

        }

    }

}

void afisare()

{

    fout<<cicluri<<"\n";

    for(int i=1; i<=cicluri; i++)

    {

        for(int j=0; j<CTC[i].size(); j++)

            fout<<CTC[i][j]<<" ";

        fout<<"\n";

    }

}

void rezolvare()

{

    for(int i=1; i<=N; i++)

    {

        if(frec[i] == 0)

        {

            dfs(i);

        }

    }

    for(int i=sortt[0]; i>=1; i--)

    {

        int nod = sortt[i];

        if(frec[ nod ] == 1)

        {

            cicluri++;

            dfs_t(nod);

        }

    }

    afisare();

}

void citire()

{

    fin>>N>>M;

    int x, y;

    for(int i=1; i<=M; i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    rezolvare();

}

int main()

{

    citire();

    return 0;

}

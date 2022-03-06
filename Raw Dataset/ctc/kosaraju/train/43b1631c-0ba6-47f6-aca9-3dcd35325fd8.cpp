#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int nmax = 100005;



int n, m, nrctc;

stack < int > S;

int viz[nmax];

vector < int > G[nmax], GT[nmax], CTC[nmax];



void read()

{

    fin >> n >> m;

    for(int i = 1; i <= m; ++i)

    {

        int x, y;

        fin >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);



    }

}



void DFS1(int nod)

{

    viz[nod] = 1;

    for(unsigned int i = 0; i < G[nod].size(); ++i)

    {

        int vecin = G[nod][i];

        if(!viz[vecin])

            DFS1(vecin);

    }

    S.push(nod);

}



void DFS2(int nod)

{

    viz[nod] = 2;

    CTC[nrctc].push_back(nod);

    for(unsigned int i = 0; i < GT[nod].size(); ++i)

    {

        int vecin = GT[nod][i];

        if(viz[vecin] == 1)

            DFS2(vecin);

    }

}



void solve()

{

    for(int i = 1; i <= n; ++i)

        if(!viz[i])

            DFS1(i);

    while(!S.empty())

    {

        int nod = S.top();

        if(viz[nod] == 1)

        {

            nrctc++;

            DFS2(nod);

        }

        S.pop();

    }

}



void afisare()

{

    fout << nrctc << "\n";

    for(int i = 1; i <= nrctc; ++i)

    {

        for(unsigned int j = 0; j < CTC[i].size(); ++j)

            fout << CTC[i][j] << " ";

        fout << "\n";

    }

}

int main()

{

    read();

    solve();

    afisare();

    return 0;

}

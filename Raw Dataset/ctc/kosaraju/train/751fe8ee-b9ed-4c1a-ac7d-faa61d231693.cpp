#include <bits/stdc++.h>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int vizitat[100001], nrCompTareConexe;

vector<int> listaMuchii[100001], listaMuchiiTranspusa[100001];

vector<int> componenteTareConexe[100005];

stack<int> stiva;

void dfs(int nod)

{

    int vecin;

    vizitat[nod] = 1;



    for (int i = 0; i < listaMuchii[nod].size(); i++)

    {

        vecin = listaMuchii[nod][i];

        if (!vizitat[vecin])

            dfs(vecin);

    }

    stiva.push(nod);

}

void dfs_transpus(int nod)

{

    int vecin;

    vizitat[nod] = 2;

    componenteTareConexe[nrCompTareConexe].push_back(nod);

    for (int i = 0; i < listaMuchiiTranspusa[nod].size(); i++)

    {

        vecin = listaMuchiiTranspusa[nod][i];



        if (vizitat[vecin] == 1)

            dfs_transpus(vecin);

    }

}

int main()

{

    int x, y, i, noduri, muchii, nodCurent;

    fin >> noduri >> muchii;



    for (i = 1; i <= muchii; i++)

    {

        fin >> x >> y;

        listaMuchii[x].push_back(y);

        listaMuchiiTranspusa[y].push_back(x);

    }



    for (i = 1; i <= noduri; i++)

    {

        if (vizitat[i] == 0)

            dfs(i);

    }



    while (!stiva.empty())

    {



        nodCurent = stiva.top();





        if (vizitat[nodCurent] == 1)

        {

            nrCompTareConexe++;

            dfs_transpus(nodCurent);

        }

        stiva.pop();

    }

    fout << nrCompTareConexe << '\n';

    for (i = 1; i <= nrCompTareConexe; i++)

    {

        for (int j = 0; j < componenteTareConexe[i].size(); j++)

        {

            fout << componenteTareConexe[i][j] << " ";

        }

        fout << '\n';

    }

    return 0;

}

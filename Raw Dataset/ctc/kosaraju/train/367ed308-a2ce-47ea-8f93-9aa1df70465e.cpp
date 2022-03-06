#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector <int> Graf[100005], Graf_tr[100005], listaOrd, c_conex[100005];

int viz[100005], v_conex[100005];

int nr_conex = 0;



void dfs(int node)

{

    if (viz[node] == 1)

        return;

    viz[node] = 1;

    for (auto i : Graf[node])

        dfs(i);

    listaOrd.push_back(node);

}



void dfs1(int node, int index_conex)

{

    if (v_conex[node])

        return;

    v_conex[node] = index_conex;

    c_conex[index_conex].push_back(node);

    for (auto i : Graf_tr[node])

    {

        dfs1(i, index_conex);

    }



}



int main() {

    int n, m, a, b;

    fin >> n >> m;

    for (int i = 0; i < m; i++)

    {

        fin >> a >> b;

        Graf[a].push_back(b);

        Graf_tr[b].push_back(a);

    }

    for (int i = 1; i <= n; i++)

    {

        if (viz[i] != 1)

        {

            dfs(i);

        }

    }

    for (int i = n - 1; i >= 0; i--)

    {

        if (!v_conex[listaOrd[i]])

        {

            nr_conex++;

            dfs1(listaOrd[i], nr_conex);

        }

    }

    fout << nr_conex << "\n";

    for (int i = 1; i <= nr_conex; i++)

    {

        for (auto j : c_conex[i])

        {

            fout << j << " ";

        }

        fout << "\n";

    }



    return 0;

}

#include <fstream>
#include <vector>


using namespace std;



const int NMAX = 100000;



vector<int> graf[1 + NMAX];

vector<int> grafInv[1 + NMAX];



bool vizitat[1 + NMAX];



vector<int> lista;



int nrComponente = 0;

vector<int> componente[1 + NMAX];



void dfs(int nod)

{

    vizitat[nod] = true;



    for (int i = 0; i < graf[nod].size(); i++)

    {

        if (!vizitat[graf[nod][i]])

        {

            dfs(graf[nod][i]);

        }

    }



    lista.push_back(nod);

}



void dfsInv(int nod)

{

    vizitat[nod] = true;



    for (int i = 0; i < grafInv[nod].size(); i++)

    {

        if (!vizitat[grafInv[nod][i]])

        {

            dfsInv(grafInv[nod][i]);

        }

    }



    componente[nrComponente].push_back(nod);

}



int main()

{

    ifstream in("ctc.in");

    ofstream out("ctc.out");

    int n, m;



    in >> n >> m;

    for (int i = 1; i <= m; i++)

    {

        int x, y;



        in >> x >> y;

        graf[x].push_back(y);

        grafInv[y].push_back(x);

    }



    for (int i = 1; i <= n; i++)

    {

        if (!vizitat[i])

        {

            dfs(i);

        }

    }



    for (int i = 1; i <= n; i++)

    {

        vizitat[i] = false;

    }



    for (int i = lista.size() - 1; i >= 0; i--)

    {

        if(!vizitat[lista[i]])

        {

            nrComponente++;

            dfsInv(lista[i]);

        }

    }



    out << nrComponente << '\n';

    for (int i = 1; i <= nrComponente; i++)

    {

        for (int j = 0; j < componente[i].size(); j++)

        {

            out << componente[i][j] << ' ';

        }

        out << '\n';

    }



    return 0;

}

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");



int const NMAX = 100001;



int n, m, nr_comp_tare_conexe, viz[NMAX];

vector<int> arce[100001], arceTranspusa[NMAX];

stack<int> stiva;

vector<int> componenteTareConexe[NMAX];



void citire()

{

    f >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        int x, y;

        f >> x >> y;

        arce[x].push_back(y);

        arceTranspusa[y].push_back(x);

    }

}



void DFS(int nod)

{

    viz[nod] = 1;

    for(int i = 0; i < arce[nod].size(); i++)

    {

        int vecin = arce[nod][i];

        if(viz[vecin] == 0)

            DFS(vecin);

    }

    stiva.push(nod);

}



void DFS_transpus(int nod)

{

    viz[nod] = 2;

    componenteTareConexe[nr_comp_tare_conexe].push_back(nod);

    for(int i = 0; i < arceTranspusa[nod].size(); i++)

    {

        int vecin = arceTranspusa[nod][i];

        if(viz[vecin] == 1)

            DFS_transpus(vecin);

    }

}



void afis()

{

    g << nr_comp_tare_conexe << '\n';

    for(int i = 1; i <= nr_comp_tare_conexe; i++)

    {

        for(int j = 0; j < componenteTareConexe[i].size(); j++)

            g << componenteTareConexe[i][j] << ' ';

        g << '\n';

    }

}



int main()

{

    citire();



    for(int i = 1; i <= n; i++)

        if(viz[i] == 0)

            DFS(i);



    while(!stiva.empty())

    {

        int nod_curent = stiva.top();

        if(viz[nod_curent] == 1)

        {

            nr_comp_tare_conexe++;

            DFS_transpus(nod_curent);

        }

        stiva.pop();

    }



    afis();

    return 0;

}

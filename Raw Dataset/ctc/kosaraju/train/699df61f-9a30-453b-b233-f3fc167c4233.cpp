#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



const int DMAX = 100005;



unsigned int n, m, nrCTC;

vector <unsigned int> G[DMAX], GT[DMAX], CTC[DMAX];



stack <unsigned int> stiva;



unsigned int viz[DMAX];



void read()

{

    f >> n >> m;



    for (unsigned int i = 1; i <= m; i++)

    {

        unsigned int x, y;



        f >> x >> y;



        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void dfs(unsigned int nod)

{

    viz[nod] = 1;



    for (auto vecin : G[nod])

    {

        if (viz[vecin] == 0)

            dfs(vecin);

    }



    stiva.push(nod);

}



void dfs_T(unsigned int nod)

{

    viz[nod] = 2;

    CTC[nrCTC].push_back(nod);



    for (auto vecin : GT[nod])

    {

        if (viz[vecin] == 1)

            dfs_T(vecin);

    }

}



void kosaraju()

{

    for (unsigned int i = 1; i <= n; i++)

        if (viz[i] == 0)

            dfs(i);



    while (!stiva.empty())

    {

        unsigned int nod = stiva.top();



        if (viz[nod] == 1)

        {

            nrCTC++;

            dfs_T(nod);

        }

        stiva.pop();

    }

}



void show()

{

    g << nrCTC << '\n';



    for (unsigned int i = 1; i <= nrCTC; i++)

    {

        for (auto nod : CTC[i])

            g << nod << ' ';



        g << '\n';

    }

}



int main()

{

    read();

    kosaraju();

    show();



    return 0;

}

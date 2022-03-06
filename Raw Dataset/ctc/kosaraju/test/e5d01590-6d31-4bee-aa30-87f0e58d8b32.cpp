#include <iostream>
#include <fstream>
#include<vector>
#include<stack>


using namespace std;







bool viz1[100005], viz2[100005];

vector <int> graph1[100005];

vector <int> graph2[100005];

vector <int> comp[100005];

stack <int> ord;

int n, m, ncomp;



ifstream f("ctc.in");

ofstream g("ctc.out");





void dfs1(int nod)

{

    viz1[nod] = 1;

    int len, i, var;

    len = graph1[nod].size();



    for(i = 0; i < len; i++)

    {

        var = graph1[nod][i];

        if(!viz1[var])

            dfs1(var);

    }

    ord.push(nod);

}



void dfs2(int nod)

{

    viz2[nod] = 1;

    int len, i, var;

    len = graph2[nod].size();



    for(i = 0; i < len; i++)

    {

        var = graph2[nod][i];

            if(!viz2[var])

                dfs2(var);

    }

    comp[ncomp].push_back(nod);

}



int main()

{

    int i, j, x, y, len;

    f >> n >> m;



    for(i = 0; i < m; i++)

    {

        f >> x >> y;

        graph1[x].push_back(y);

        graph2[y].push_back(x);

    }



    for(i = 1; i <= n; i++)

        if(viz1[i] == 0)

            dfs1(i);



    while(!ord.empty())

    {

        x = ord.top();

        ord.pop();

        if(!viz2[x])

        {

            dfs2(x);

            ncomp++;

        }

    }



    g << ncomp << endl;



    for(i = 0; i < ncomp; i++)

    {

        len = comp[i].size();



        for(j = 0; j < len; j++)

            g << comp[i][j] << ' ';



        g << '\n';

    }

    return 0;

}

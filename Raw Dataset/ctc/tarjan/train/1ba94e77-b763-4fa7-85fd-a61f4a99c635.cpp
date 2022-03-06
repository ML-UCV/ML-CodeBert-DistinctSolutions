#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int> v[100001], tc[100001];

stack<int> stiva;

bool inStiva[100001];

int n, ctc, id, viz[100001], leg[100001];



void citire()

{

    int m;

    f>>n>>m;

    for(int i = 1; i <= m; i++)

    {

        int x, y;

        f>>x>>y;

        v[x].push_back(y);

    }

}



void dfs(int nod)

{

    stiva.push(nod);

    inStiva[nod] = 1;

    viz[nod] = leg[nod] = ++id;

    for(int i = 0; i < v[nod].size(); i++)

    {

        if(!viz[v[nod][i]])

        {

            dfs(v[nod][i]);

            leg[nod] = min(leg[nod], leg[v [nod][i]]);

        }

        else if(inStiva[v[nod][i]])

            leg[nod] = min(leg[nod], leg[v[nod][i]]);

    }

    if(leg[nod] == viz[nod])

    {

        ctc++;

        while(true)

        {

            tc[ctc].push_back(stiva.top());

            inStiva[stiva.top()] = 0;

            if(stiva.top() == nod)

            {

                stiva.pop();

                break;

            }

            stiva.pop();

        }

    }

}



int main()

{

    citire();

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            dfs(i);

    g<<ctc<<'\n';

    for(int i = 1; i <= ctc; i++){

        for(int j = 0; j < tc[i].size(); j++)

            g<<tc[i][j]<<' ';

        g<<'\n';

    }

    return 0;

}

#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int>graph[100005];

vector<int>rezultate[100005];

stack<int>s;



int n, m, a, b, llk[100005],ind_rez, ix[100005];

int indice;

bool viz[100005];



void adaugare(int ind)

{

    viz[ind]=1;

    ix[ind]=llk[ind]=++indice;

    s.push(ind);

    for (auto &v:graph[ind])

    {

        if (!ix[v])

        {

            adaugare(v);

            llk[ind]=min(llk[v],llk[ind]);

        }

        else if (viz[v])

        {

            llk[ind]=min(llk[ind],llk[v]);

        }

    }

    if (ix[ind]==llk[ind])

    {

        while(!s.empty())

        {

            int nod=s.top();

            viz[nod]=0;

            s.pop();

            if (llk[nod]==ix[nod])

            {

                rezultate[ind_rez++].push_back(nod);

                break;

            }

            rezultate[ind_rez].push_back(nod);

        }

    }

}



int main()

{

    f >> n >> m;

    for (int i=1; i<=m; ++i)

    {

        f >> a >> b;

        graph[a].push_back(b);

    }

    for (int i=1; i<=n; ++i)

    {

        if (!ix[i])

        {

            adaugare(i);

        }

    }

    g << ind_rez << '\n';

    for (int i=0; i<ind_rez; ++i)

    {

        for (auto &v:rezultate[i])

        {

            g << v <<' ';

        }

        g << '\n';

    }

    return 0;

}

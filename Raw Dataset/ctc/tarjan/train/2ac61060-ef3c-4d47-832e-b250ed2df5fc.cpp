#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



stack<int>s;

vector<int>graph[100005];

vector<int>rezultate[100005];

int n, m, a, viz[100005], b, llk[100005], ix[100005], ind=1, ind_rez;



void solve(int val)

{

    int sus;

    llk[val]=ix[val]=ind++;

    s.push(val);

    viz[val]=1;

    for (auto &v:graph[val])

    {

        if (!ix[v])

        {

            solve(v);

            llk[val]=min(llk[val],llk[v]);

        }

        if (viz[v])

            llk[val]=min(llk[val],llk[v]);

    }

    if (llk[val]==ix[val])

    {

        while (!s.empty())

        {

            sus=s.top();

            s.pop();

            viz[sus]=false;

            if (llk[sus]==ix[sus])

            {

                rezultate[ind_rez].push_back(sus);

                ind_rez++;

                break;

            }

            else

            {

                rezultate[ind_rez].push_back(sus);

            }

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

            solve(i);

    }

    g << ind_rez << '\n';

    for (int i=0; i<ind_rez; ++i)

    {

        for (auto &v:rezultate[i])

            g << v <<' ';

        g <<'\n';

    }

    return 0;

}

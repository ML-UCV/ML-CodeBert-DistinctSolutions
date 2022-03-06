#include <bits/stdc++.h>






using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int nmax = 1505;

int n, m, viz[nmax];

vector <pair <int, double> > g[nmax];

double d[nmax];

int dp[nmax];



inline void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++)

    {

        int a, b, c;

        fin >> a >> b >> c;

        g[a].push_back({b, log10(1.0*c)});

        g[b].push_back({a, log10(1.0*c)});

    }

}



struct cmp

{

    bool operator()(int x,int y)

    {

        return d[x] - d[y] > 1e-8;

    }

};



priority_queue <int, vector <int>, cmp> q;



inline void dij()

{

    q.push(1);

    for (int i = 2; i <= n; i++)

        d[i] = 1e9;

    dp[1] = 1;

    d[1] = 0;

    viz[1] = 1;

    while (!q.empty())

    {

        int nod = q.top();

        q.pop();

        viz[nod] = 0;

        for (int i = 0; i < g[nod].size(); i++)

        {

            int vecin = g[nod][i].first;

            double cost = g[nod][i].second;

            if (d[vecin] - (d[nod] + cost) > 1e-8)

            {

                d[vecin] = d[nod] + cost;

                dp[vecin] = dp[nod];

                dp[vecin] %= 104659;

                if (!viz[vecin])

                {

                    viz[vecin] = 1;

                    q.push(vecin);

                }

            }

            else if (abs(d[vecin] - (d[nod] + cost)) < 1e-8)

                dp[vecin] += dp[nod], dp[vecin] %= 104659;

        }

    }

}



inline void solve()

{

    dij();

    for (int i = 2; i <= n; i++)

        fout << dp[i] << " ";

}



int main()

{

    read();

    solve();

    return 0;

}

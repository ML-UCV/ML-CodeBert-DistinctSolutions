#include <bits/stdc++.h>
FILE *fin = freopen("dmin.in", "r", stdin);

FILE *fout = freopen("dmin.out", "w", stdout);



using namespace std;

int V, E, sol[1502];

double D[1502];

struct comp

{

    bool operator() (const pair <int, double> &a, const pair <int, double> &b)

    {

        if(fabs(a.second - b.second) < 0.0000000001)

            return 0;

        else return a.second > b.second + 0.0000000001;

    }

};

priority_queue <pair <int, double>, vector<pair <int, double> >, comp> Q;

vector <pair <int, double> > G[1502];

bool F[1502];

void read()

{

    int x, y;

    double z;

    scanf("%d %d", &V, &E);

    while(E --)

    {

        scanf("%d %d %lf", &x, &y, &z);

        z = log(z);

        G[x].push_back(pair <int, double>(y, z));

        G[y].push_back(pair <int, double>(x, z));

    }

    for(int i = 2; i <= V; ++ i)

        D[i] = 2000000000.0;

    Q.push(pair <int, double>(1, 0.0));

    sol[1] = 1;

}

void solve()

{

    int x, y;

    double z;

    while(!Q.empty())

    {

        x = Q.top().first;



        Q.pop();

        int sz = G[x].size();

        if (F[x])

            continue;



        for(int i = 0; i < sz; ++ i)

        {

            y = G[x][i].first;

            z = G[x][i].second;

            if (!F[y])

            {

                if(D[y] > D[x] + z + 0.0000000001)

                {

                    D[y] = D[x] + z;

                    sol[y] = sol[x];

                    Q.push(pair <int, double>(y, D[y]));

                }

                else if(fabs(D[y] - D[x] - z) < 0.0000000001)

                    sol[y] = (sol[y] + sol[x]) % 104659;

            }

        }

        F[x] = 1;

    }

}

void write()

{

    for(int i = 2; i <= V; ++ i)

        printf("%d ", sol[i]);

}

int main()

{

    read();

    solve();

    write();

    return 0;

}

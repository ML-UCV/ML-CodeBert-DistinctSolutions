#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



const int NMAX = 2e5 + 3;

int n, m, ans;

class Link

{

public:

    int x, y, cost;

    bool operator < (const Link &other) const

    {

        return this->cost < other.cost;

    }

};

Link e[NMAX * 2];

int dad[NMAX];

bool vis[NMAX * 2];



void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++)

        fin >> e[i].x >> e[i].y >> e[i].cost;

}



int findDad(int node)

{

    int ndad = node;

    while (ndad != dad[ndad])

        ndad = dad[ndad];



    while (node != ndad)

    {

        int aux = dad[node];

        dad[node] = ndad;

        node = aux;

    }

    return ndad;

}



void kruskal()

{

    sort(e + 1, e + m + 1);

    iota(dad + 1, dad + n + 1, 1);

    for (int i = 1; i <= m; i++)

    {

        int x = findDad(e[i].x);

        int y = findDad(e[i].y);

        if (x != y)

        {

            ans += e[i].cost;

            dad[x] = y;

            vis[i] = true;

        }

    }



    fout << ans << '\n' << n - 1 << '\n';

    for (int i = 1; i <= m; i++)

        if (vis[i])

            fout << e[i].x << ' ' << e[i].y << '\n';

}



int main()

{

    read();

    kruskal();

    fout.close();

    return 0;

}

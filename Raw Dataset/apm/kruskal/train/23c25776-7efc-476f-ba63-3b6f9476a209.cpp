#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

vector <pair < int, int > > v;

int n, m;

struct nod

{

    int p;

    int d;

} graf[200005];

struct muchie

{

    int x,y;

    int cost;

} nodes[400005];

bool cmp(muchie a, muchie b)

{

    if(a.cost < b.cost)

        return true;

        else if( a. cost == b. cost)

            if(a.x < b.x)

            return true;

          if(a.x == b.x)

             if(a.y < b.y)

                return true;

    return false;

}

int getRoot(int node)

{

    if(graf[node].p == 0)

        return node;

    int p = getRoot(graf[node].p);

    graf[node].d = graf[p].d;

    graf[node].p = p;

    return p;

}

void citire()

{

    fin >> n >> m;

    for(int i = 0; i < m; i++)

        fin >> nodes[i].x >> nodes[i].y >> nodes[i].cost;

            sort(nodes, nodes + m, cmp);

}

void solve()

{

    int c = 0;

    int k = 0;

    for(int i = 0; i < m; i++)

    {

        int r1 = getRoot(nodes[i].x);

        int r2 = getRoot(nodes[i].y);

        if(r1 != r2)

        {

            if(graf[r1].d == graf[r2].d)

            {

                graf[r2].p = r1;

                graf[r1].d++;

            }

            else if(graf[r1].d > graf[r2].d)

            {

                graf[r2].p = r1;

            }

            else if(graf[r1].d < graf[r2].d)

            {

                graf[r1].p = r2;

            }

            c =c + nodes[i].cost;

            v.push_back({nodes[i].x, nodes[i].y});

        }

    }

    fout << c << "\n";

    fout << n - 1 << "\n";

    for(auto &n : v)

        fout << n.first <<" "<< n.second <<"\n";

}

int main()

{

    citire();

    solve();

    return 0;

}

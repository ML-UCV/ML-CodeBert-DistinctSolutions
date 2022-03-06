#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct nod

{

    int parent;

    int depth;

    int cost;

} graf[200005];

int n, m;



struct muchie

{

    int x, y, c;

    bool operator<(muchie other)

    {

        if(other.c == c)

            return x < other.x;

        return c < other.c;

    }

} muchii[400005];



vector<pair<int, int> > sol;



int getRoot(int node)

{

    if(graf[node].parent == 0)

        return node;

    int parent = getRoot(graf[node].parent);

    graf[node].parent = parent;

    return parent;

}



void read()

{

    f>>n>>m;

    int c, x, y;

    for(int i = 0; i<m; i++)

    {

        f>>muchii[i].x>>muchii[i].y>>muchii[i].c;

    }

    sort(muchii, muchii+m);

}



void solve()

{

    for(int i = 0; i<m; i++)

    {

        int r1 = getRoot(muchii[i].x);

        int r2 = getRoot(muchii[i].y);

        if(r1 == r2)

            continue;

        if(graf[r1].depth == graf[r2].depth)

        {

            graf[r1].cost += graf[r2].cost + muchii[i].c;

            graf[r2].parent = r1;

            graf[r1].depth++;

        }

        else if(graf[r1].depth > graf[r2].depth)

        {

            graf[r1].cost += graf[r2].cost + muchii[i].c;

            graf[r2].parent = r1;

        }

        else if(graf[r1].depth < graf[r2].depth)

        {

            graf[r2].cost += graf[r1].cost + muchii[i].c;

            graf[r1].parent = r2;

        }

        sol.push_back({muchii[i].x, muchii[i].y});

    }

}



void afisare()

{

    g<<graf[getRoot(1)].cost<<"\n";

    g<<sol.size()<<"\n";

    for(auto p : sol)

        g<<p.first<<" "<<p.second<<"\n";

}



int main()

{

    read();

    solve();

    afisare();

    return 0;

}

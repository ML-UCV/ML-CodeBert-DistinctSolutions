#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >V;

vector<pair<int, int> >v[200005];

int n, m, x, y, c, viz[200005];

struct Banana

{

    int x, y;

}sol[200005];

int prim(int nod)

{

    int i, cost = 0, b = 0, j, nodaux;

    viz[nod] = 1;

    for (i = 1; i <= n - 1; i++)

    {

        for (j = 0; j < v[nod].size(); j++)

        {

            nodaux = v[nod][j].second;

            b = v[nod][j].first;

            if (!viz[nodaux]) V.push({ b,{nod,nodaux} });

        }

        while (viz[V.top().second.second])

            V.pop();

        cost += V.top().first;

        viz[V.top().second.second] = 1;

        sol[i].x = V.top().second.first;

        sol[i].y = V.top().second.second;

        nod = V.top().second.second;

        V.pop();

    }

    return cost;

}

int main()

{

    int i;

    f >> n >> m;

    for (i = 1; i <= m; i++)

    {

        f >> x >> y >> c;

        v[x].push_back({ c,y });

        v[y].push_back({ c,x });

    }

    g << prim(1) << '\n' << n - 1 << '\n';

    for (i = 1; i < n; i++)

        g << sol[i].x << " " << sol[i].y << '\n';

    return 0;

}

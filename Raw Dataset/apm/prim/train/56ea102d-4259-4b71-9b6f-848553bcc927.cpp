#include <bits/stdc++.h>
using namespace std;

ifstream f("apm.in");

ofstream o("apm.out");

typedef pair<int, int> pii;

vector<pii> adj[200001];

bitset<200001> APM;

int n, m;

void Prim()

{

    int x;

    priority_queue<pii, vector<pii>, greater<pii> > q;

    vector<int> cost(n + 1, 1000001);

    vector<int> t(n + 1, 0);

    q.push({ 0,1 });

    cost[1] = 0;

    t[1] = 0;

    while (!q.empty())

    {

        x = q.top().second;

        q.pop();

        APM[x] = true;

        for (auto i : adj[x])

        {

            if (!APM[i.first] && cost[i.first] > i.second)

            {

                cost[i.first] = i.second;

                q.push({ cost[i.first], i.first });

                t[i.first] = x;

            }

        }

    }

    int val = 0;

    for (int i = 1; i <= n; i++)

       val += cost[i];

    o << val<<endl;

    o << n - 1 <<endl;

    for (unsigned int i = 2; i < t.size(); i++)

        o << t[i] << " " << i << "\n";

}

int main()

{

    int x, y, c;

    f >> n >> m;

    for(int i=1;i<=m;i++)

    {

        f >> x >> y >> c;

        adj[x].push_back({ y,c });

        adj[y].push_back({ x, c });

    }

    Prim();

    return 0;

}

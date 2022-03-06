#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");





typedef pair<int, int> pii;

vector<pii> adj[200001];

bitset<200001> inAPM;

int n, m;

void Prim()

{

    int x;

    priority_queue<pii, vector<pii>, greater<pii> > q;

    vector<int> cost(n + 1, 0x3f3f3f3f);

    vector<int> t(n + 1, 0);

    q.push({ 0,1 });

    cost[1] = 0;

    t[1] = 0;

    while (!q.empty())

    {

        x = q.top().second;

        q.pop();

        inAPM[x] = true;

        for (auto i : adj[x])

        {

            if (!inAPM[i.first] && cost[i.first] > i.second)

            {

                cost[i.first] = i.second;

                q.push({ cost[i.first], i.first });

                t[i.first] = x;

            }

        }

    }

    int ansval = 0;

    for (int i = 1; i <= n; i++)

       ansval += cost[i];

    fout << ansval<< "\n";

    fout << n - 1 << "\n";

    for (unsigned int i = 2; i < t.size(); i++)

        fout << t[i] << " " << i << "\n";

}

int main()

{

    int x, y, cost;

    fin >> n >> m;

    while (m--)

    {

        fin >> x >> y >> cost;

        adj[x].push_back({ y,cost });

        adj[y].push_back({ x, cost });

    }

    Prim();

    fin.close();

    fout.close();

    return 0;

}

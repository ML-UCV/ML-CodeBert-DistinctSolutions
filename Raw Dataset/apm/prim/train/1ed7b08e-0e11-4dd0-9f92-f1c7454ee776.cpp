#include <bits/stdc++.h>






using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



vector<pair<int, int> >adj[200000 + 5];

vector<int>key(200000 + 5, 1e9);

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int parent[200000 + 5];

bool inMST[200000 + 5];

int n, m;



int main()

{

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);



    fin>>n>>m;



    for(int i = 1; i <= m; i++)

    {

        int u, v, weight;

        fin>>u>>v>>weight;



        adj[u].push_back(make_pair(weight, v));

        adj[v].push_back(make_pair(weight, u));

    }



    pq.push(make_pair(0, 1));

    key[1] = 0;



    while(!pq.empty())

    {

        int u = pq.top().second;

        pq.pop();



        inMST[u] = true;



        for(int i = 0; i < adj[u].size(); i++)

        {

            int v = adj[u][i].second;

            int weight = adj[u][i].first;



            if(!inMST[v] && key[v] > weight)

            {

                key[v] = weight;

                pq.push(make_pair(key[v], v));

                parent[v] = u;

            }

        }

    }

    int s = 0;



    for(int i = 1; i <= n; i++)

        s += key[i];



    fout<<s<<'\n';



    fout<<n - 1<<'\n';





    for(int i = 2; i <= n; i++)

        fout<<parent[i]<<' '<<i<<'\n';

    return 0;

}

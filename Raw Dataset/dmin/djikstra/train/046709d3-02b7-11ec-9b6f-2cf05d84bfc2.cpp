#include <bits/stdc++.h>
using namespace std;



typedef long long ll;

typedef pair <int, int> pii;

typedef pair <ll, ll> pll;

typedef vector <int> vi;

typedef vector <pii> vii;

typedef vector <ll> vl;

typedef vector <pll> vll;

typedef queue <int> qi;

typedef queue <pii> qii;

typedef queue <ll> ql;

typedef queue <pll> qll;



const int INF = 1000000000;

const int MOD = 104659;

const double EPSILON = 1e-10;

const int NMAX = 1500 + 5;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



struct edge

{

    int node;

    double cost;



    edge()

    {

        node = cost = 0;

    }



    edge(int _node, double _cost)

    {

        node = _node;

        cost = _cost;

    }



    bool operator <(const edge &arg) const

    {

        return cost > arg.cost;

    }

};



vector <edge> graph[NMAX];

priority_queue <edge> pq;

int n, m;

int ans[NMAX];

double drum[NMAX];

bool vis[NMAX];



void dijkstra(int start)

{

    for (int i = 1; i < NMAX; ++i)

        drum[i] = INF;



    drum[start] = 0;

    ans[start] = 1;

    pq.push(edge(start, 0));



    while (!pq.empty())

    {

        edge nod = pq.top();

        pq.pop();

        if (nod.cost > drum[nod.node]) continue;

        for (edge next: graph[nod.node])

            if (drum[next.node] - EPSILON > nod.cost + next.cost)

            {

                drum[next.node] = nod.cost + next.cost;

                ans[next.node] = ans[nod.node];

                pq.push(edge(next.node, drum[next.node]));

            }

            else if (fabs(drum[next.node] - nod.cost - next.cost) <= EPSILON)

                ans[next.node] = (ans[next.node] + ans[nod.node]) % MOD;
    }

}



void write()

{

    for (int i = 2; i <= n; ++i)

        fout << ans[i] << " ";

}



void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; ++i)

    {

        int x, y;

        int cost;

        fin >> x >> y >> cost;

        graph[x].push_back(edge(y, log(1.0 * cost)));

        graph[y].push_back(edge(x, log(1.0 * cost)));

    }

}



int main()

{

    read();

    dijkstra(1);

    write();



    return 0;

}

#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie

{

    int curr;

    int dest;

    int cost;

    bool operator>(const muchie other) const

    {

        if(other.cost == cost)

            return dest > other.dest;

        return cost > other.cost;

    }

};

vector<muchie> graf[200005];

bool viz[200005];

int n, m;

vector<pair<int, int> > sol;

priority_queue<muchie, vector<muchie>, greater<muchie> > Q;

int cost;



void read()

{

    f>>n>>m;

    int c, x, y;

    for(int i = 0; i<m; i++)

    {

        f>>x>>y>>c;

        graf[x].push_back({x, y, c});

        graf[y].push_back({y, x, c});

    }

}



void addNode(int node)

{

    viz[node] = true;

    for(auto p : graf[node])

    {

        if(!viz[p.dest])

            Q.push(p);

    }

}



void solve()

{

    addNode(1);

    while(sol.size() < n-1)

    {

        muchie mu = Q.top();

        Q.pop();

        if(viz[mu.dest])

            continue;

        sol.push_back({mu.curr, mu.dest});

        addNode(mu.dest);

        cost += mu.cost;

    }

}



void afisare()

{

    g<<cost<<"\n";

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

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie {

    int x;

    int y;

    int val;

};



vector <pair<int,int>> solution;

int cycle[400005], cost_min;



struct less_than_key

{

    inline bool operator() (const muchie& struct1, const muchie& struct2)

    {

        return (struct1.val < struct2.val);

    }

};



void Union(int u, int v, int s[])

{

    if (s[u] < s[v])

    {

        s[u] += s[v];

        s[v] = u;

    }

    else

    {

        s[v] += s[u];

        s[u] = v;

    }

}



int Find(int u, int s[])

{

    int x = u;

    int v = 0;

    while (s[x] > 0)

    {

        x = s[x];

    }

    while (u != x)

    {

        v = s[u];

        s[u] = x;

        u = v;

    }

    return x;

}



void Kruskal(int n, int m, vector <muchie> g)

{

    for(int i = 0; i <= m; i++)

        cycle[i] = -1;

    int i = 0;

    while (i < m)

    {

        int u = g[i].x;

        int v = g[i].y;

        int cost = g[i].val;

        if (Find(u, cycle) != Find(v, cycle))

        {

            cost_min += cost;

            solution.push_back(make_pair(u,v));

            Union(Find(u, cycle), Find(v, cycle), cycle);

        }

        i++;

    }



}



int main()

{

    int n, m;

    f>>n>>m;

    vector <muchie> graph;

    for(int i = 0; i < m; i++)

    {

        muchie m;

        f>>m.x>>m.y>>m.val;

        graph.push_back(m);

    }

    sort(graph.begin(), graph.end(), less_than_key());

    Kruskal(n, m, graph);

    g<<cost_min<<endl;

    g<<solution.size()<<endl;

    for(int i = 0; i < solution.size(); i++)

    {

        g<<solution[i].first<<" "<<solution[i].second<<endl;

    }

    return 0;

}

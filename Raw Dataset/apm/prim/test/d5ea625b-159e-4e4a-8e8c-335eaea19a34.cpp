#include <bits/stdc++.h>
#include <fstream>






using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



int n , m;







bitset<200005>f;

int cost[200005];

int previous[200005];

struct edge

{

    int x , d;

};

vector<edge> edges[200005];



priority_queue<pair<int , int > >pq;



void refresh()

{

    for(int i = 1; i <= n; i++)

        cost[i] = 2e9;

}



int addtomst(int node)

{

    for(auto &i:edges[node])

    {

        if(f[i.x]==0)

        {

            if(i.d < cost[i.x])

            {

                pq.push({-i.d,i.x});

                cost[i.x] = i.d;

                previous[i.x] = node;

            }

        }

    }

}



int main()

{

    int a , b , d;

    in >> n >> m;

    for(int i = 1; i <= m; ++i)

    {

        in >> a >> b >> d;

        edges[a].push_back({b,d});

        edges[b].push_back({a,d});

    }

    refresh();

    f[1] = 1;

    addtomst(1);

    for(int i = 2; i <= n; i++)

    {

        int node = pq.top().second;

        while(f[node]==1)

        {

            pq.pop();

            node = pq.top().second;

        }

        f[node] = 1;

        addtomst(node);

    }

    int cazan = 0;

    for(int i = 2; i <= n; ++i)

        cazan += cost[i];

    out << cazan << '\n';

    out << n - 1 << '\n';

    for(int i = 2; i <= n; ++i)

        out << previous[i] << " " << i << "\n";

    return 0;

}

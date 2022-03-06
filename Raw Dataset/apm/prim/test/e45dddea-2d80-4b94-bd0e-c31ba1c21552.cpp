#include <bits/stdc++.h>


using namespace std;

ifstream r("apm.in");

ofstream w("apm.out");

int viz[200002];

vector<pair<int, int>>g[200002], rez;

struct qu

{

    int nod, cost, prev;

    qu(int nod, int cost, int prev)

    {

        this->nod=nod;

        this->cost=cost;

        this->prev=prev;

    }

    bool operator < (qu b)const

    {

        return cost>b.cost;

    }

};

priority_queue<qu>q;

int main()

{

    int n, m;

    r>>n>>m;

    viz[1]=1;

    for(int i=0; i<m; i++)

    {

        int x, y, c;

        r>>x>>y>>c;

        g[x].push_back(make_pair(y, c));

        g[y].push_back(make_pair(x, c));

    }

    long long sum=0;

    for(int i=0; i<g[1].size(); i++)

    {

        if(viz[g[1][i].first]==0)

        {

            q.push(qu(g[1][i].first, g[1][i].second, 1));

        }

    }

    while(rez.size()!=n-1)

    {

        while(viz[q.top().nod]==1){

            q.pop();

        }

        int a=q.top().nod;

        sum+=q.top().cost;

        rez.push_back(make_pair(q.top().prev, a));

        viz[a]=1;

        q.pop();

        for(int i=0; i<g[a].size(); i++)

        {

            if(viz[g[a][i].first]==0)

            {

                q.push(qu(g[a][i].first, g[a][i].second, a));

            }

        }

    }

    w<<sum<<"\n"<<n-1<<"\n";

    for(int i=0; i<n-1; i++)

    {

        w<<rez[i].first<<" "<<rez[i].second<<"\n";

    }

    return 0;

}

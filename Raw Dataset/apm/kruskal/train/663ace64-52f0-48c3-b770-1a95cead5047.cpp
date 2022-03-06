#include <bits/stdc++.h>


using namespace std;

ifstream r("apm.in");

ofstream w("apm.out");

vector<pair<int,int>>cost, g, rez;

int v[200002], len[200002];

int root(int a)

{

    if(v[a]==a)

    {

        return a;

    }

    return v[a]=root(v[a]);

}

int main()

{

    int n, m;

    r>>n>>m;

    for(int i=0; i<m; i++)

    {

        int x, y, c;

        r>>x>>y>>c;

        g.push_back(make_pair(x, y));

        cost.push_back(make_pair(c, i));

    }

    sort(cost.begin(), cost.end());

    for(int i=1; i<=n; i++)

    {

        v[i]=i;

        len[i]=1;

    }

    long long sum=0;

    for(int i=0;i<m;i++){

        int a=root(g[cost[i].second].first), b=root(g[cost[i].second].second);

        if(a==b){

            continue;

        }

        sum+=cost[i].first;

        rez.push_back(make_pair(g[cost[i].second].first, g[cost[i].second].second));

        if(a>b){

            swap(a, b);

        }

        if(len[a]==len[b]){

            len[a]++;

        }

        v[b]=a;

    }

    w<<sum<<"\n"<<rez.size()<<"\n";

    for(int i=0;i<rez.size();i++){

        w<<rez[i].first<<" "<<rez[i].second<<"\n";

    }

    return 0;

}

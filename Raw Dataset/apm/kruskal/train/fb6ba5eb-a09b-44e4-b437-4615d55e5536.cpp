#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

vector<pair<int,pair<int,int>>> edges;

vector<pair<int,int>> sol;

int parent[200005],n,m;

int Find(int i)

{

    if (parent[i] != i)

        parent[i] = Find(parent[i]);

    return parent[i];

}

void Union(int x,int y)

{

    int a = Find(x);

    int b = Find(y);

    parent[a] = b;

}

int main()

{

    in>>n>>m;

    for(int i=0;i<m;i++)

    {

        int a,b,c;

        in>>a>>b>>c;

        edges.push_back({c,{a,b}});

    }

    sort(edges.begin(), edges.end());

    for(int i=1;i<=n;i++)

        parent[i] = i;

    int sum = 0;

    for(auto it:edges)

    {

        int a = Find(it.second.first);

        int b = Find(it.second.second);

        if(a != b)

        {

            sum += it.first;

            sol.push_back({it.second.first,it.second.second});

            Union(a,b);

        }

    }

    out<<sum<<'\n'<<n-1<<'\n';

    for(int i=0;i<n-1;i++)

        out<<sol[i].first<<' '<<sol[i].second<<'\n';

    return 0;

}

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



int main()

{

    int n, m, x, y, c, s;

    fin >> n>> m;

    int d[n+1], t[n+1], viz[n+1];

    vector < pair<int, int>> g[n+1];

    for(int i=1; i<=m; ++i)

    {

        fin >> x >>y>> c;

        g[x].push_back({y,c});

        g[y].push_back({x,c});

    }

    for(int i=1; i<=n;++i)

    {

        d[i] = INT_MAX;

        t[i] = 0;

        viz[i] = 0;

    }

    s = 1;

    d[s] = 0;



    priority_queue < pair <int, int>> q;

    q.push({-d[s], s});

    while(!q.empty())

    {

        x=q.top().second;

        q.pop();

        viz[x]=1;

        for(auto i: g[x])

        {

            y=i.first;

            c=i.second;

            if(viz[y]==0 && d[y]>c)

            {

                t[y]=x;

                d[y]=c;

                q.push({-d[y], y});

            }

        }

    }

    s=0;

    for(int i=1; i<=n; i++) s+=d[i];

    fout<<s<<'\n'<<n-1<<'\n';

    for(int i=1; i<=n; i++)

    {

        if(t[i]!=0) fout<<t[i]<<" "<<i<<'\n';

    }

 return 0;

}

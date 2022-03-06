#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

vector<pair<int,int>> graf[200005];

int n,m,viz[200005],parent[200005],key[200005];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int main()

{

    in>>n>>m;

    for(int i=0;i<m;i++)

    {

        int a,b,c;

        in>>a>>b>>c;

        graf[a-1].push_back({b-1,c});

        graf[b-1].push_back({a-1,c});

    }

    q.push({0,0});

    for(int i=0;i<n;i++){

        key[i] = 5000;

    }

    while(!q.empty())

    {

        int nod = q.top().second;

        q.pop();

        viz[nod] = 1;

        for(auto it:graf[nod])

            if(!viz[it.first] && key[it.first] > it.second)

            {

                key[it.first] = it.second;

                parent[it.first+1] = nod+1;

                q.push({it.second,it.first});

            }

    }

    int sum=0;

    for(int i=1;i<n;i++)

        sum += key[i];

    out<<sum<<'\n'<<n-1<<'\n';

    for (int i = 2; i <= n; ++i)

        out<<parent[i]<<' '<<i<<'\n';

    return 0;

}

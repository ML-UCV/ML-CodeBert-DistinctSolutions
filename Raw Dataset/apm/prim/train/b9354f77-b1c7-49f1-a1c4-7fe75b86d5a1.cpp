#include <iostream>
#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

int N,M;

int tata[200005], d[200005];

bool viz[200005];

int cost_total = 0;

vector<pair<int,int>> Graph[200005];

auto Compare = [](pair<int,int> &a, pair<int,int> &b)

{

    return get<1>(a)>get<1>(b);

};

priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(Compare) > que(Compare);



void initializare(int nod)

{

    d[nod] = 2e9;

    tata[nod]=0;

}



int main()

{

    in>>N>>M;

    int x,y,z;

    for(int i=1; i<=M; i++)

    {

        in>>x>>y>>z;

        Graph[x].push_back({y,z});

        Graph[y].push_back({x,z});

    }

    for(int i=1; i<=N; i++)

        initializare(i);

    d[1] = 0;

    que.push({1,0});



    while(!que.empty())

    {

        int u = que.top().first;

        que.pop();

        viz[u] = true;

        for(auto &vecin:Graph[u])

        {

            int v = vecin.first;

            int w = vecin.second;

            if(!viz[v] && w<d[v])

            {

                d[v] = w;

                tata[v] = u;

                que.push({v,d[v]});

            }

        }

    }

    for(int i=1;i<=N;i++)

        cost_total+=d[i];

    out<<cost_total<<'\n'<<N-1<<'\n';

    for(int i=2; i<=N; i++)

        out<<i<<" "<<tata[i]<<'\n';

    return 0;

}

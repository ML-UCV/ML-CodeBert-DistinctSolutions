#include <bits/stdc++.h>
std::ifstream fin("stramosi.in");

std::ofstream fout("stramosi.out");

typedef long long ll;

ll n, m;

ll sol[300005];

std::vector<ll> graph[250005];

std::vector<std::pair<ll, ll> > query[250005];

std::vector<ll> list;

void solve(ll node);

int main()

{

    fin>>n>>m;

    for(int i=1; i<=n; ++i){

        ll x;

        fin>>x;

        graph[x].push_back(i);

    }

    for(int i=1; i<=m; ++i){

        ll x, y;

        fin>>x>>y;

        query[x].push_back({y+1, i});

    }

    solve(0);

    for(int i=1; i<=m; ++i) fout<<sol[i]<<"\n";

    return 0;

}

void solve(ll node){

    list.push_back(node);

    if(node){

        for(auto i:query[node]){

            if(i.first>list.size()-1) continue;

            else sol[i.second]=list[list.size()-i.first];

        }

    }

    for(auto next:graph[node]) solve(next);

    list.pop_back();

}

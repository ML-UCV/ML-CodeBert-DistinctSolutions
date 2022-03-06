#include <bits/stdc++.h>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n, m, cost;

int parent[200005], card[200005];

bool ap[200005];

vector < pair< int, int > > nod[200005], ans;

priority_queue < pair < int, pair< int, int > >, vector < pair < int, pair< int, int > > >, greater < pair < int, pair< int, int > > > > pq;



void add_edges(int x){

    ap[x] = true;

    int y, c;

    for(auto it: nod[x]){

        y = it.first;

        c = it.second;

        if(ap[y])

            continue;

        pq.push({c, {y, x}});

    }

}



void answer(){

    add_edges(1);

    int c, x, y;

    while(ans.size() != n-1){

        c = pq.top().first;

        y = pq.top().second.first;

        x = pq.top().second.second;

        pq.pop();

        if(ap[y])

            continue;

        cost += c;

        ans.push_back({x, y});

        add_edges(y);

    }

}



void read(){

    f>>n>>m;

    int c, x, y;

    for(int i = 1; i <= m; ++i){

        f>>x>>y>>c;

        nod[x].push_back({y, c});

        nod[y].push_back({x, c});

    }

    answer();

    g<<cost<<'\n';

    g<<n-1<<'\n';

    for(auto it: ans)

        g<<it.first<<' '<<it.second<<'\n';

}



int main(){

    read();

    return 0;

}

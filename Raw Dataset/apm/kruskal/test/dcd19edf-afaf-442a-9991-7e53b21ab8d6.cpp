#include <bits/stdc++.h>






using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n, m, cost;

int parent[200005], card[200005];

vector < pair< int, int > > ans;

priority_queue < pair < int, pair< int, int > >, vector < pair < int, pair< int, int > > >, greater < pair < int, pair< int, int > > > > q;



int find_parent(int nod){

    if(parent[nod] != nod){

        parent[nod] = find_parent(parent[nod]);

        return parent[nod];

    }

    return nod;

}



void reunion(int x, int y){

    x = find_parent(x);

    y = find_parent(y);

    if(card[x] < card[y])

        swap(x, y);

    card[x] += card[y];

    parent[y] = x;

}



void answer(){

    while(ans.size() != n-1){

        int c = q.top().first;

        int x = q.top().second.first;

        int y = q.top().second.second;

        q.pop();

        if(find_parent(x) == find_parent(y))

            continue;

        ans.push_back({x, y});

        cost += c;

        reunion(x, y);

    }

}



void read(){

    f>>n>>m;

    for(int i = 1; i <= n; ++i){

        parent[i] = i;

        card[i] = 1;

    }

    int c, x, y;

    for(int i = 1; i <= m; ++i){

        f>>x>>y>>c;

        q.push({c, {x, y}});

    }

    answer();

    g<<cost<<'\n';

    g<<n-1<<'\n';

    for(int i = 0; i < ans.size(); ++i)

        g<<ans[i].first<<' '<<ans[i].second<<'\n';

}



int main(){

    read();

    return 0;

}

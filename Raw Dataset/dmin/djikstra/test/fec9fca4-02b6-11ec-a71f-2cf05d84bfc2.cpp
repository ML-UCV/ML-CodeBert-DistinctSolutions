#include <bits/stdc++.h>






using namespace std;

using ld = long double;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int mod = 104659;

const int NMAX = 2048;

const ld EPS = 1e-6;

int N, M;

pair<ld,int> dp[NMAX];

vector<pair<int,ld>> G[NMAX];

priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> Q;



void add_self(int &a, int b) {

    a += b;

    if(a >= mod)

        a -= mod;

}



void Dijkstra() {

    for(int u = 1; u <= N; ++u)

        dp[u] = make_pair(1.0 * 0x3f3f3f3f, 0);

    dp[1] = make_pair(0.0, 1);

    Q.push(make_pair(0.0, 1));

    while(!Q.empty()) {

        int u = Q.top().second;

        ld d = Q.top().first;

        Q.pop();

        if(((d - dp[u].first) >= 0 ? (d - dp[u].first) : -(d - dp[u].first)) > EPS)

            continue;

        for(const auto &v : G[u]) {

            ld best = d + v.second;

            if((dp[v.first].first - best) > EPS) {

                dp[v.first].first = best;

                dp[v.first].second = dp[u].second;

                Q.push(make_pair(dp[v.first].first, v.first));

            }

            else

                if(((dp[v.first].first - best) >= 0 ? (dp[v.first].first - best) : -(dp[v.first].first - best)) <= EPS)

                    add_self(dp[v.first].second, dp[u].second);

        }

    }

}



int main() {

    fin >> N >> M;

    for(int i = 0; i < M; ++i) {

        int u, v, w;

        fin >> u >> v >> w;

        G[u].emplace_back(v, log2((ld)w));

        G[v].emplace_back(u, log2((ld)w));

    }

    Dijkstra();

    for(int u = 2; u <= N; ++u)

        fout << dp[u].second << ' ';

    fout << '\n';

}

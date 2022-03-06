#include <bits/stdc++.h>


using namespace std;

ifstream in("dmin.in");

ofstream out("dmin.out");



const int NMAX = 1505;

const double EPS = 0.0000000001;

const double INF = 1000000000;

const int MOD = 104659;

vector<pair<int, double> > v[NMAX];



struct Data {

    int node;

    double cost;

    bool operator< (Data other) const {

        return cost > other.cost;

    }

};



priority_queue<Data> hp;

double best[NMAX];

int dp[NMAX];



void dijkstra() {

    for (int i = 0; i < NMAX; i ++)

        best[i] = 1000000000;

    hp.push({1, 0});

    best[1] = 0;

    dp[1] = 1;

    while (hp.size()) {

        Data s = hp.top();

        hp.pop();

        for (auto i : v[s.node]) {

            if (best[i.first] - EPS > (s.cost + i.second)) {

                best[i.first] = s.cost + i.second;

                dp[i.first] = dp[s.node];

                hp.push({i.first, best[i.first]});

            } else if (fabs(best[i.first] - s.cost - i.second) <= EPS) {

                dp[i.first] += dp[s.node];

                if (dp[i.first] >= MOD)

                    dp[i.first] -= MOD;

            }

        }

    }

}





int main() {

    ios::sync_with_stdio(false);

    int n, m;

    in >> n >> m;

    for (int i = 1; i <= m; i ++) {

        int x, y;

        double c;

        in >> x >> y >> c;

        v[x].push_back({y, log10(c)});

        v[y].push_back({x, log10(c)});

    }

    dijkstra();

    for (int i = 2; i <= n; i ++)

        out << dp[i] << " ";

    return 0;

}

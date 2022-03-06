#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int NMAX = 2e5 + 5;

const int INF = 1e9;

int dist[NMAX], from[NMAX], ans;

bool vis[NMAX];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

vector<pair<int,int>> graf[NMAX];



int main()

{

    int n, m;

    f >> n >> m;

    for(int i = 1; i <= m; i++) {

        int x, y, c;

        f >> x >> y >> c;

        graf[x].push_back(make_pair(y, c));

        graf[y].push_back(make_pair(x, c));

    }

    for(int i = 1; i <= n; i++) {

        dist[i] = INF;

    }

    dist[1] = 0;

    pq.push(make_pair(dist[1], 1));

    while(!pq.empty()) {

        int nod = pq.top().second;

        pq.pop();

        if(vis[nod]) {

            continue;

        }

        vis[nod] = 1;

        ans += dist[nod];

        for(int i = 0; i < (int)graf[nod].size(); i++) {

            int next = graf[nod][i].first;

            int cost = graf[nod][i].second;

            if(!vis[next] && dist[next] > cost) {

                dist[next] = cost;

                from[next] = nod;

                pq.push(make_pair(dist[next], next));

            }

        }

    }

    g << ans << '\n';

    g << n - 1 << '\n';

    for(int i = 2; i <= n; i++) {

        g << i << ' ' << from[i] << '\n';

    }

    return 0;

}

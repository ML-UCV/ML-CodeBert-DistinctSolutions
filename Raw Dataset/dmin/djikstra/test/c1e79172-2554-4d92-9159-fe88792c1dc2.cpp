#include <fstream>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;



const int NMAX = 1500 + 5;

const int MMAX = 2500 + 5;

const int MOD = 104659;

const double EPS = 1e-8;

const double INF = 1e40;



int N, M;

vector <pair <int, double> > graph[NMAX];



double dist[NMAX];

int cnt[NMAX];

bool vis[NMAX];



priority_queue <pair <double, int> > q;



void dijkstra() {

    for (int i = 1; i <= N; ++ i)

        dist[i] = INF;



    dist[1] = 0;

    cnt[1] = 1;

    q.push(make_pair(0, 1));



    while (!q.empty()) {

        int node = q.top().second;

        q.pop();



        if (vis[node])

            continue;

        vis[node] = true;



        for (auto it: graph[node])

            if (dist[node] + it.second < dist[it.first] - EPS) {

                dist[it.first] = dist[node] + it.second;

                cnt[it.first] = cnt[node];

                q.push(make_pair(-dist[it.first], it.first));

            }

            else if (dist[node] + it.second < dist[it.first] + EPS) {

                cnt[it.first] += cnt[node];

                if (cnt[it.first] >= MOD)

                    cnt[it.first] -= MOD;

            }

   }

}



int main()

{

    ifstream cin("dmin.in");

    ofstream cout("dmin.out");



    cin >> N >> M;

    for (int i = 1; i <= M; ++ i) {

        int a, b, c;

        cin >> a >> b >> c;



        graph[a].push_back(make_pair(b, log(c)));

        graph[b].push_back(make_pair(a, log(c)));

    }



    dijkstra();

    for (int i = 2; i <= N; ++ i)

        cout << cnt[i] << " \n"[i == N];

    return 0;

}

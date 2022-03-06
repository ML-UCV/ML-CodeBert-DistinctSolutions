#include<stdio.h>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;


const int NMAX = 1505, mod = 104659, INF = 2e9;
const double eps = 1.e-10;
double dmin[NMAX];
int sol[NMAX];
bool vis[NMAX];

class cmp {
    public:
        bool operator () (int a, int b) const {
            return dmin[a] > dmin[b];
        }
};

priority_queue <int, vector <int>, cmp> q;

vector < pair <int, double> > graph[NMAX];

void dijkstra (int node) {
    sol[node] = 1;
    q.push(node);

    while(!q.empty()) {
        node = q.top();
        q.pop();

        if(vis[node]) continue;
        vis[node] = 1;

        for(int i = 0; i < graph[node].size(); ++ i)
            if(!vis[graph[node][i].first]) {
                int x = graph[node][i].first;
                double c = graph[node][i].second;

                if(fabs(dmin[node] + c - dmin[x]) < eps)
                    sol[x] = (sol[node] + sol[x]) % mod;
                else
                if(dmin[node] + c < dmin[x]) {
                    dmin[x] = dmin[node] + c;
                    sol[x] = sol[node];
                    q.push(x);
                }
            }
    }
}

int main() {
    freopen("dmin.in", "r", stdin);
    freopen("dmin.out", "w", stdout);
    int n, m, x, y, c, i;

    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; ++ i) {
        scanf("%d%d%d", &x, &y, &c);

        graph[x].push_back(make_pair(y, log(c)));
        graph[y].push_back(make_pair(x, log(c)));
    }

    for(i = 2; i <= n; ++ i)
        dmin[i] = 2e9;

    dijkstra(1);

    for(i = 2; i <= n; ++ i)
        printf("%d ", sol[i]);
    return 0;
}

#include <cstdio>
#include <vector>
#include <deque>
#define NMAX 30001
#define pb push_back
#define mp make_pair
using namespace std;

FILE *f = freopen("sate.in", "r", stdin);
FILE *g = freopen("sate.out", "w", stdout);

vector < pair <int, int> > G[NMAX];
deque <int> q;
int cost[NMAX], n, m, x, y;

void read() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = 1; i<=m; i++) {
        int xx, yy, zz;
        scanf("%d%d%d", &xx, &yy, &zz);
        G[xx].pb(mp(yy, zz));
        G[yy].pb(mp(xx, zz));
    }
}

void bfs(int start) {
    for(int i = 0; i<NMAX; i++)
        cost[i] = -1;
    q.pb(start);
    cost[start] = 0;
    while(!q.empty()) {
        int nod = q.front();
        q.pop_front();
        for (vector <pair <int, int> >::iterator it=G[nod].begin();it!=G[nod].end();it++) {
            if(cost[it->first] == -1) {
                q.pb(it->first);
                if(it -> first < nod )
                       cost[it -> first] = cost[nod] - it -> second;
                else
                cost[it -> first] = cost[nod] + it -> second;
            }
        }
    }
}
void write() {
    bfs(x);
    printf("%d", cost[y]);
}
int main() {
    read();
    write();
    return 0;
}

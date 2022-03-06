#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 30001;
vector< pair<short, int> > a[NMAX];
queue<short> q;
int d[NMAX],
    n, m, x, y;

void bfs() {
    q.push(x);
    d[x] = 1;
    int crt;
    while(!q.empty()) {
        crt = q.front();
        q.pop();
        for(auto i: a[crt]) {
            if(d[i.first] == 0) {
                d[i.first] = d[crt] + i.second;
                if(i.first == y) return;
                q.push(i.first);
            }
        }
    }
}
int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    scanf("%i %i %i %i", &n, &m, &x, &y);

    while(m--) {
        int i, j, D;
        scanf("%i %i %i", &i, &j, &D);
        a[i].push_back({j, D});
        a[j].push_back({i, -D});
    }

    bfs();

    printf("%i", d[y]-1);
    return 0;
}

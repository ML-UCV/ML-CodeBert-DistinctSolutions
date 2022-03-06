#include <cstdio>
#include <vector>
using namespace std;

const int NMAX = 100005;

vector <int> g[NMAX];

vector <int> gv[NMAX];

bool viz[NMAX];

vector <int> toposort;

void dfs(int u) {

    viz[u] = 1;

    for(int v : g[u]) {

        if(viz[v] == 0) {

            dfs(v);

        }

    }

    toposort.push_back(u);

}

vector <int> sol[NMAX];

int sz = 0;

void gdfs(int u) {

    viz[u] = 1;

    for(int v : gv[u]) {

        if(viz[v] == 0) {

            gdfs(v);

        }

    }

    sol[sz].push_back(u);

}



int main() {

    int n, m;

    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++) {

        int x, y;

        scanf("%d%d", &x, &y);

        g[x].push_back(y);

        gv[y].push_back(x);

    }

    for(int i = 1; i <= n; i++) {

        if(viz[i] == 0){

            dfs(i);

        }

    }

    for(int i = 0; i <= n; i++) {

        viz[i] = 0;

    }

    for(int i = toposort.size() - 1; i > -1; i--) {

        int val = toposort[i];

        if(viz[toposort[i]] == 0) {

            sz++;

            gdfs(toposort[i]);

        }

    }

    printf("%d\n", sz);

    for(int i = 1; i <= sz; i++) {

        for(int j = 0; j < sol[i].size(); j++) {

            printf("%d ", sol[i][j]);

        }

        printf("\n");

    }

    return 0;

}

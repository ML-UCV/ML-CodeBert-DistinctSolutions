#include <cstdio>
#include <vector>

FILE *fin = fopen("sate.in", "r");
FILE *fout = fopen("sate.out", "w");

#define maxn 120000
#define ll long long

std::vector<std::pair<int, int>> v[maxn + 1];
int viz[maxn + 1];
int a, b;
ll dp[maxn + 1];
void dfs(int t) {
    viz[t] = 1;
    int p, c;
    for (auto it : v[t]) {
        p = it.first;
        c = it.second;
        if (viz[p] != 1) {
            dp[p] = dp[t] + c;
            dfs(p);
        }

    }
}

int main()
{

    int n, m, x, y, c;

    fscanf(fin, "%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= m; i++) {
        fscanf(fin, "%d%d%d", &x, &y, &c);
        v[x].push_back (std::make_pair(y, c));
        v[y].push_back (std::make_pair(x, -c));
    }
    dfs(a);
    fprintf(fout, "%lld", dp[b]);
    return 0;
}

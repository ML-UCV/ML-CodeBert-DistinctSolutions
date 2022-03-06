#include <fstream>
#include <vector>
const int MAX_N = 30000;
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct Muchie {
    int v, c;
};
Muchie x, y;
long long n, m, s, ok;
bool vizitat[MAX_N + 1];
int dp[MAX_N + 1];

vector<Muchie> vecini[MAX_N + 1];

void dfs(Muchie u) {
    vizitat[u.v] = 1;
    if (ok == 1)
        return;
    if(u.v == y.v) {
        ok = 1;
        return;
    }
    for(auto v : vecini[u.v])
        if(!vizitat[v.v]) {
            dp[v.v]=dp[u.v]+v.c;
            dfs(v);
        }
}
int main()
{
    fin >> n >> m >> x.v >> y.v;
    for (int i = 1; i <= m; i++) {
        int u, w, c;
        fin >> u >> w >> c;
        vecini[u].push_back({w, c});
        vecini[w].push_back({u, -c});
    }
    dfs(x);
    fout << dp[y.v] << '\n';
    return 0;
}

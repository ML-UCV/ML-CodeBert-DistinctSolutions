#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 1e5 + 5;

ifstream cin ("ctc.in");
ofstream cout ("ctc.out");

vector <int> g1[NMAX];
vector <int> g2[NMAX];
int viz[NMAX];
vector <int> ans[NMAX];
vector <int> nodes;
void dfs1(int node)
{
    viz[node] = 1;
    for(auto x: g1[node]) {
        if(viz[x] == 0) {
            dfs1(x);
        }
    }
    nodes.push_back(node);
}

void dfs2(int node, int cm)
{
    viz[node] = 1;
    ans[cm].push_back(node);
    for(auto x: g2[node]) {
        if(viz[x] == 0) {
            dfs2(x, cm);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        if(viz[i] == 0) {
            dfs1(i);
        }
    }
    reverse(nodes.begin(), nodes.end());
    for(int i = 1; i <= n; ++i)
        viz[i] = 0;
    int cnt = 0;
    for(int i = 0; i < nodes.size(); ++i) {
        if(viz[nodes[i]] == 0) {
            ans[cnt++].clear();
            dfs2(nodes[i], cnt - 1);
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < cnt; ++i) {
        for(auto x: ans[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

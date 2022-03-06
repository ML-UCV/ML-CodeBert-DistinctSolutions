#include <iostream>
#include <fstream>
#include <vector>
const int N_MAX = 100005;

int no_conex, n, m;
std :: vector <int> conex[N_MAX];
int conex_nd[N_MAX];
bool vis[N_MAX];
std :: vector <int> graph[N_MAX], trans[N_MAX];
std :: vector <int> sorted;
int ind;

void dfs( int node) {
    if(vis[node]) return;

    vis[node] = true;
    for (int i : graph[node]) {

            dfs(i);
    }
    sorted.push_back(node);
}

void dfs_t(int node) {
    if (conex_nd[node]) return;

    conex_nd[node] = ind;
    conex[ind].push_back(node);

    for( int i : trans[node]) {
        dfs_t(i);
    }
}

int main() {

    std :: ifstream fin ("ctc.in");
    std :: ofstream fout ("ctc.out");

    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        trans[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }


    for (int i = n - 1; i >= 0; --i) {
        if (!conex_nd[sorted[i]]) {
            ind ++;
            dfs_t(sorted[i]);

        }
    }
    fout << ind << "\n";
    for (int i = 1; i <= ind; ++i) {
        for (int node: conex[i])
            fout << node << " ";
        fout << '\n';
    }
    return 0;
}

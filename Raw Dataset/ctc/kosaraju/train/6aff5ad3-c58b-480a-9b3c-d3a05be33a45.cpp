#include <fstream>
#include <vector>

using namespace std;

int n, m, i, j, k;
bool v1[100005], v2[100005];
vector<int> a, b, G[100005], GT[100005], comp[100005];

void dfs1(int nod) {
    int p;

    if(!v1[nod]) {
        v1[nod] = true;
        b.push_back(nod);
        for(p = 0; p < G[nod].size(); p++)
            if(!v1[G[nod][p]])
                dfs1(G[nod][p]);
    }
}

void dfs2(int nod) {
    int p;

    if(!v2[nod]) {
        v2[nod] = true;
        comp[k].push_back(nod);
        for(p = 0; p < GT[nod].size(); p++)
            if(!v2[GT[nod][p]])
                dfs2(GT[nod][p]);
    }
}

int main() {
    ifstream f("ctc.in");
    ofstream g("ctc.out");

    f >> n >> m;
    while(m) {
        f >> i >> j;

        G[i].push_back(j);
        GT[j].push_back(i);
        m--;
    }
    f.close();

    for(i = 1; i <= n; i++)
        if(!v1[i]) {
            dfs1(i);
            for(j = b.size() - 1; j >= 0; j--)
                a.push_back(b[j]);
            b.clear();
        }

    k = 0;
    for(i = a.size() - 1; i >= 0; i--)
        if(!v2[a[i]]) {
            k++;
            dfs2(a[i]);
        }

    g << k << '\n';
    for(i = 1; i <= k; i++, g << '\n')
        for(j = 0; j < comp[i].size(); j++)
            g << comp[i][j] << ' ';
    g.close();

    return 0;
}

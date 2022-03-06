#include <fstream>
#include <vector>

std::vector<int> arce[100001];
std::vector<int> transpus[100001];
std::vector<std::vector<int>> componente;
std::vector<int> sort;
bool vazut[100001];
bool vazut2[100001];

void sortare_topologica(int nod) {
    vazut[nod] = true;
    for (const int succ : arce[nod]) {
        if (!vazut[succ]) {
            sortare_topologica(succ);
        }
    }
    sort.push_back(nod);
}

void dfs2(int nod, std::vector<int>& r) {
    vazut2[nod] = true;
    r.push_back(nod);
    for (const int succ : transpus[nod]) {
        if (!vazut2[succ]) {
            dfs2(succ, r);
        }
    }
}

int main() {
    std::ifstream fin("ctc.in");
    std::ofstream fout("ctc.out");
    int n, m;

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        arce[a].push_back(b);
        transpus[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vazut[i]) {
            sortare_topologica(i);
        }
    }
    for (int i = sort.size() - 1; i >= 0; i--) {
        if (!vazut2[sort[i]]) {
            componente.push_back({});
            dfs2(sort[i], componente.back());
        }
    }
    fout << componente.size() << '\n';
    for (const auto& c : componente) {
        for (const int x : c) {
            fout << x << ' ';
        }
        fout << '\n';
    }
    return 0;
}

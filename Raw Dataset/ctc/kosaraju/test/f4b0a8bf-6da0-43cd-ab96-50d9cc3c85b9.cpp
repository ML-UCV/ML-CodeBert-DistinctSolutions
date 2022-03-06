#include <fstream>
#include <vector>

using namespace std;

const int NMAX = 200005;

vector<int> graf[NMAX];
vector<int> graf_t[NMAX];
vector<int> ordered_list;
vector<int> comp[NMAX];

int comp_nod[NMAX];
int viz[NMAX];

int nrcomp;

void dfs1(int nod) {
    if (viz[nod])
        return ;

    viz[nod] = 1;

    for (auto &vec : graf[nod]) {
        dfs1(vec);
    }
    ordered_list.push_back(nod);
}

void dfs2(int nod, int index) {
    if (comp_nod[nod])
        return ;

    comp_nod[nod] = index;
    comp[index].push_back(nod);

    for (auto &vec : graf_t[nod]) {
        dfs2(vec, index);
    }

}

int main() {
    ifstream fin("ctc.in");
    ofstream fout("ctc.out");

    int a,b,m,n;
    fin >> n >> m;
    for(int i = 0; i < m; i++) {
        fin >> a >> b;
        graf[a].push_back(b);
        graf_t[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if (!viz[i]) {
            dfs1(i);
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if (!comp_nod[ordered_list[i]]) {
            dfs2(ordered_list[i], ++nrcomp);
        }
    }

    fout << nrcomp << "\n";
    for (int i = 1; i <= nrcomp; i++) {
        for (auto &nod : comp[i]) {
            fout << nod << " ";
        }
        fout << "\n";
    }


    fin.close();
    fout.close();
    return 0;
}

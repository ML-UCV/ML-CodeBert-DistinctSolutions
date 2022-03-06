#include <fstream>
#include <vector>
#include <iostream>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, nr;

bool v[100005];

vector<int> g[100005], gt[100005], noduri, ctc[100005];



void citire() {

    fin >> n >> m;

    while(m--) {

        int x, y;

        fin >> x >> y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

}



void dfs1(int x) {

    v[x] = 1;

    for(auto next: g[x])

        if(!v[next])

            dfs1(next);

    noduri.push_back(x);

}



void dfs2(int x) {

    v[x] = 1;

    ctc[nr].push_back(x);

    for(auto next: gt[x])

        if(!v[next])

            dfs2(next);

}



void solve() {

    for(int i = 1; i <= n; i++)

        if(!v[i])

            dfs1(i);

    for(int i = 1; i <= n; i++)

        v[i] = 0;

    for(int i = noduri.size()-1; i >= 0; i--)

        if(!v[noduri[i]]) {

            nr++;

            dfs2(noduri[i]);

        }

}



void afis() {

    fout << nr << '\n';

    for(int i = 1; i <= nr; i++) {

        for(auto x: ctc[i])

            fout << x << ' ';

        fout << '\n';

    }

}



int main() {

    citire();

    solve();

    afis();

}

#include <fstream>
#include <vector>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int> noduri, g[100005], gt[100005], ctc[100005];

int n, m, currComp, v[100005];



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

    ctc[currComp].push_back(x);

    for(auto next: gt[x])

        if(!v[next])

            dfs2(next);

}



void solve() {

    for(int i = 1; i <= n; i++) v[i] = 0;

    for(int i = 1; i <= n; i++)

        if(!v[i]) dfs1(i);



    for(int i = 1; i <= n; i++) v[i] = 0;

    for(int i = noduri.size()-1; i >= 0; i--) {

        int x = noduri[i];

        if(!v[x]) {

            currComp++;

            dfs2(x);

        }

    }

}



void afis() {

    fout << currComp << '\n';

    for(int i = 1; i <= currComp; i++) {

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

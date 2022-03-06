#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int> g[100005], gt[100005], ctc[100005];

int n, m, nr;

vector<int> noduri;

bool v[100005];



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



int main() {

    citire();

    for(int i = 1; i <= n; i++)

        if(!v[i])

            dfs1(i);

    reverse(noduri.begin(), noduri.end());

    memset(v, 0, sizeof v);

    for(auto x: noduri)

        if(!v[x]) {

            nr++;

            dfs2(x);

        }

    fout << nr << '\n';

    for(int i = 1; i <= nr; i++) {

        for (auto x: ctc[i])

            fout << x << ' ';

        fout << '\n';

    }

}

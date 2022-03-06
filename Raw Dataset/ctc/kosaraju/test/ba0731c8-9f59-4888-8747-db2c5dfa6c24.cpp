#include <bits/stdc++.h>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



bitset <100000 +1> seen;

vector <int> G[100000 +1], GT[100000 +1], S;



void dfs (int x) {

    seen[x]=1;

    for (auto it: G[x])

        if (!seen[it])

            dfs(it);

    S.push_back(x);

}



void dfsT (int x) {

    seen[x]=1;

    for (auto it: GT[x])

        if (!seen[it])

            dfsT(it);

    fout << x << ' ';

}



int main () {

    int n, m;

    ios::sync_with_stdio(false);

    fin >> n >> m;



    int i, j;

    for (; m; m--) {

        fin >> i >> j;

        G[i].push_back(j);

        GT[j].push_back(i);

    }



    for (i=1; i<=n; i++)

        if (!seen[i])

            dfs(i);



    fout << "       \n";

    seen.reset();

    int ct=0;



    for (auto it=S.rbegin(); it!=S.rend(); ++it)

        if (!seen[*it]) {

            dfsT(*it);

            ++ct;

            fout << '\n';

        }



    fout.seekp(0);

    fout << ct;

    return 0;

}

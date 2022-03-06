#include <bits/stdc++.h>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



bitset <100000 +1> seen;

vector <int> G[100000 +1], GT[100000 +1], S, tmp;

vector <vector <int>> ans;



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

    tmp.push_back(x);

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

    seen.reset();



    int ct=0;

    for (auto it=S.rbegin(); it!=S.rend(); ++it)

        if (!seen[*it]) {

            ++ct;

            dfsT(*it);

            ans.push_back(tmp);

            tmp.clear();

        }



    fout << ans.size() << '\n';

    for (auto i: ans) {

        for (auto j: i)

            fout << j << ' ';

        fout << '\n';

    }

    return 0;

}

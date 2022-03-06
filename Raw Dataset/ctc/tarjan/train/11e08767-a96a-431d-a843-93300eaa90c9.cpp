#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m,nrOrd;

vector<vector<int>> ad;

vector<int> ord, low;



stack<int> st;

vector<bool> onStack;

vector<vector<int>> sccs;



void dfs(int node) {

    st.push(node);

    onStack[node] = true;

    ord[node] = low[node] = ++nrOrd;

    for (int vecin : ad[node])

        if (!ord[vecin]) {

            dfs(vecin);

            low[node] = min(low[node], low[vecin]);

        }

        else if (onStack[vecin])

            low[node] = min(low[node], low[vecin]);



    if (ord[node] == low[node]) {

        sccs.emplace_back();

        while (true) {

            int top = st.top();

            st.pop();

            onStack[top] = false;



            low[top] = ord[node];

            sccs.back().push_back(top);

            if (top == node)

                break;

        }

    }

}



int main() {

    fin >> n >> m;

    ad.resize(n + 1);

    for (int i = 0; i < m; i++) {

        int x, y;

        fin >> x >> y;

        ad[x].push_back(y);

    }



    ord.resize(n + 1);

    low.resize(n + 1);

    onStack.resize(n + 1);



    for (int i = 1; i <= n; i++)

        if (!ord[i])

            dfs(i);



    fout << sccs.size() << '\n';

    for (auto& scc : sccs) {

        for (int node : scc)

            fout << node << ' ';

        fout << '\n';

    }



    fout.close();

    return 0;

}

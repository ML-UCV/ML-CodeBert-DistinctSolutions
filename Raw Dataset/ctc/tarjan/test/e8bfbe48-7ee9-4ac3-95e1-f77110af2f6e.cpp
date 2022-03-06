#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");

const int MAXN = 100005;



bool inSt[MAXN];

int ll[MAXN], mark[MAXN], n, m, val, nr;

vector<int> graph[MAXN], comp[MAXN];

stack<int> st;



void read()

{

    fin >> n >> m;

    for (int i = 0; i < m; ++i) {

        int x, y;

        fin >> x >> y;

        graph[x].push_back(y);

    }

}



void tarjan(int node)

{

    st.push(node);

    inSt[node] = true;

    mark[node] = ll[node] = ++val;

    for (const auto& it: graph[node])

        if (mark[it] == 0) {

            tarjan(it);

            ll[node] = min(ll[node], ll[it]);

        }

        else if (inSt[it] == true)

            ll[node] = min(ll[node], mark[it]);

    if (ll[node] == mark[node]) {

        while (!st.empty()) {

            int top = st.top();

            st.pop();

            inSt[top] = false;

            comp[nr].push_back(top);

            if (top == node)

                break;

        }

        ++nr;

    }

}



void print()

{

    fout << nr << '\n';

    for (int i = 0; i < nr; ++i) {

        for (const auto &it: comp[i])

            fout << it << ' ';

        fout << '\n';

    }

}



int main()

{

    read();

    for (int i = 1; i <= n; ++i)

        if (mark[i] == 0)

            tarjan(i);

    print();

    return 0;

}

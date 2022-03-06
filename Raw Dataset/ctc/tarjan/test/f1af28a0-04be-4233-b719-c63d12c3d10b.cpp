#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



class Graph {

  private:

    int n;

    vector<vector<int>> ad;



    vector<int> ind, low;

    vector<vector<int>> sccs;



    void dfs(int node, int& id, stack<int>& st, vector<bool>& onStack) {

        ind[node] = low[node] = ++id;

        st.push(node); onStack[node] = true;



        for (int nghb : ad[node])

            if (!ind[nghb]) {

                dfs(nghb, id, st, onStack);

                low[node] = min(low[node], low[nghb]);

            }

            else if (onStack[nghb])

                low[node] = min(low[node], low[nghb]);



        if (ind[node] == low[node]) {

            sccs.emplace_back();

            while (true) {

                int top = st.top();

                st.pop(); onStack[top] = false;



                low[top] = ind[node];

                sccs.back().push_back(top);



                if (top == node)

                    break;

            }

        }

    }



  public:

    Graph(int n) :

        n(n), ad(n + 1),

        ind(n + 1), low(n + 1) { }



    void addEdge(int x, int y) {

        ad[x].push_back(y);

    }



    vector<vector<int>>& tarjan() {

        stack<int> st;

        vector<bool> onStack(n + 1);



        int id = 0;

        for (int i = 1; i <= n; i++)

            if (!ind[i])

                dfs(i, id, st, onStack);

        return sccs;

    }

};



int main() {

    int n, m;

    fin >> n >> m;



    Graph graph(n);

    for (int i = 0; i < m; i++) {

        int x, y; fin >> x >> y;

        graph.addEdge(x, y);

    }



    vector<vector<int>>& sccs = graph.tarjan();

    fout << sccs.size() << '\n';

    for (vector<int>& scc : sccs) {

        for (int node : scc)

            fout << node << ' ';

        fout << '\n';

    }



    fout.close();

    return 0;

}

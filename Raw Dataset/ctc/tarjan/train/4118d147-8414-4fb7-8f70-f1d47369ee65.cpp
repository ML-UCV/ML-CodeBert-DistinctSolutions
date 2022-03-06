#include <bits/stdc++.h>


using namespace std;



int n, m;

vector<vector<int>> edges;

vector<vector<int>> scc;

int nrScc = -1, currentIndex = 0;

vector<int> lowlink;

vector<bool> onStack;

vector<int> idx;

stack<int> st;

vector<int> comp;



void read() {

    cin >> n >> m;

    edges.resize(n);

    for(int i=0; i<m; i++) {

        int u, v;

        cin >> u >> v;

        edges[u-1].push_back(v-1);

    }

}



void dfs(int v) {

    lowlink[v] = idx[v] = currentIndex++;

    onStack[v] = true;

    st.push(v);

    for(int u : edges[v]) {

        if(idx[u] == -1) {

            dfs(u);

            lowlink[v] = min(lowlink[v], lowlink[u]);

        } else if(onStack[u] == true)

            lowlink[v] = min(lowlink[v], idx[u]);

    }



    if(lowlink[v] == idx[v]) {

        comp.clear();

        int node;

        do {

            node = st.top();

            comp.push_back(node);

            onStack[node] = false;

            st.pop();

        } while(node!=v);

        scc.push_back(comp);

    }

}



void tarjan() {

    for(int i=0; i<(int)edges.size(); i++)

        if(idx[i] == -1)

            dfs(i);

}



void show() {

    for(int v=0; v<edges.size(); v++) {

        cout << v << " : ";

        for(int u: edges[v])

            cout << u << " ";

        cout << "\n";

    }

}



void showScc() {

    cout << scc.size() << " ";

    for(int i=0; i<scc.size(); i++) {

        for(int node: scc[i])

            cout << node + 1 << " ";

        cout << "\n";

    }

}



int main() {

    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);

    read();

    idx.resize(n), lowlink.resize(n), onStack.resize(n);

    idx.assign(n, -1), onStack.assign(n, 0);



    tarjan();

    showScc();

    return 0;

}

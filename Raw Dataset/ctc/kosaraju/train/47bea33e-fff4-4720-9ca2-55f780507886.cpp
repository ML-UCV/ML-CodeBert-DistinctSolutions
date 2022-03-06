#include <bits/stdc++.h>
using namespace std;



class Task {
public:
    void solve() {
        read_input();
        get_result();
        print_output();
    }

private:
    int n, m;

    vector<int> adj[100009];


    vector<int> adjT[100009];





    vector<int> topsort;

    vector<vector<int>> scc;

    void read_input() {
        ifstream fin("ctc.in");
        fin >> n >> m;

        for (int i = 1; i <= m; ++i) {
            int x, y;

            fin >> x >> y;

            adj[x].push_back(y);


            adjT[y].push_back(x);
        }

        fin.close();
    }

    void print_output() {
        ofstream fout("ctc.out");

        fout << scc.size() << "\n";

        for (auto &vect : scc) {
            for (auto &it : vect) {
                fout << it << " ";
            }
            fout << "\n";
        }

        fout.close();
    }

    void get_result() {
       kosaraju();
    }

    void kosaraju() {
        vector<int> visited(n + 1, 0);

        topsort.push_back(-1);


        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, topsort);
            }
        }

        for (int i = n; i >= 1; --i) {





            if (visited[topsort[i]]) {
                vector<int> component;

                dfsT(topsort[i], visited, component);

                scc.push_back(component);
            }
        }
    }

    void dfs(int& node, vector<int>& visited, vector<int> &topsort) {
        visited[node] = 1;

        for (auto& it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, topsort);
            }
        }


        topsort.push_back(node);
    }

    void dfsT(int& node, vector<int>& visited, vector<int> &component) {
        visited[node] = 0;
        component.push_back(node);

        for (auto& it : adjT[node]) {
            if (visited[it]) {
                dfsT(it, visited, component);
            }
        }
    }
};

int main() {






    Task *task = new Task();
    task->solve();
    delete task;

    return 0;
}

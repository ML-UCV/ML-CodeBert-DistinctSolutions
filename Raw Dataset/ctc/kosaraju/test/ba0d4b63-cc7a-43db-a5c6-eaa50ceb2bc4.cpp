#include <bits/stdc++.h>
using namespace std;
class Task {

 public:

    void solve() {

        read_input();

        print_output(get_result());

    }



 private:

    int n, m;

    vector<int> lista_vecini[100001];

    vector<int> lista_vecini_graf_transpus[100001];



    void read_input() {

        ifstream in("ctc.in");

        in >> n >> m;



        for (int i = 1; i <= m; i++) {

            int x, y;

            in >> x >> y;

            lista_vecini[x].push_back(y);

            lista_vecini_graf_transpus[y].push_back(x);

        }



        in.close();

    }



    void dfs(int source, vector<bool> &visited, vector<int> &finish_sort) {

        visited[source] = 1;

        for (auto &vecin : lista_vecini[source]) {

            if (!visited[vecin]) {

                dfs(vecin, visited, finish_sort);

            }

        }



        finish_sort.push_back(source);

    }







    void dfs_transpus(int source, vector<bool> &visited, vector<int> &componenta_noua) {

        componenta_noua.push_back(source);

        visited[source] = 0;



        for (auto &vecin: lista_vecini_graf_transpus[source]) {

            if (visited[vecin]) {

                dfs_transpus(vecin, visited, componenta_noua);

            }

        }

    }



    vector<vector<int>> get_result() {

        vector<vector<int>> componente_biconexe;

        vector<int> finish_sort;

        vector<bool> visited(n + 1, 0);



        finish_sort.push_back(-1);



        for (int i = 1; i <= n; ++i) {

            if (!visited[i]) {

                dfs(i, visited, finish_sort);

            }

        }



        for (int i = n; i >= 1; --i) {

            if (visited[finish_sort[i]]) {

                vector<int> componenta_noua;

                dfs_transpus(finish_sort[i], visited, componenta_noua);

                componente_biconexe.push_back(componenta_noua);

            }

        }



        return componente_biconexe;

    }



    void print_output(vector<vector<int>> componente_biconexe) {

        ofstream out("ctc.out");

        out << componente_biconexe.size() << "\n";



        for (const auto &ctc : componente_biconexe) {

            for (auto &elem : ctc) {

                out << elem << " ";

            }

            out << "\n";

        }



        out.close();

    }

};





int main() {

    Task* task = new Task();

    task->solve();

    delete(task);

    return 0;

}

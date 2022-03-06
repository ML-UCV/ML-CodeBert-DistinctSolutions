#include <iostream>
#include <vector>
#include <fstream>
#include <queue>



using namespace std;
class Task {

    std::vector<int> matrix[100005];
    std::vector<int> adj_matrix[100005];
    std::vector<bool> visited;


    int N, M, S;


    void read_input() {

        std::ifstream in("ctc.in");

        in >> N;
        in >> M;

        for (int i = 0; i < M; i++) {

            int x;

            int y;

            in >> x;

            in >> y;

            matrix[x].push_back(y);
            adj_matrix[y].push_back(x);
        }

        in.close();

    }


    void dfs_util(int source, std::vector<int> &time_finish) {
        visited[source] = true;
        for (auto &x : matrix[source]) {
            if (visited[x] == false) {
                dfs_util(x, time_finish);
            }
        }

        time_finish.push_back(source);

    }

    void dfs_adjacent(int source, std::vector<int> &solution) {
        solution.push_back(source);
        visited[source] = true;
        for (auto &x: adj_matrix[source]) {
            if (visited[x] == false) {
                dfs_adjacent(x, solution);
            }
        }
    }


    std::vector<std::vector<int>> ctc_kosaraju() {

        std::vector<int> time_finish;
        time_finish.push_back(0);
        std::vector<std::vector<int>> connex_comp;
        visited = std::vector<bool>(N + 1, false);

        for (int i = 1; i <= N; i++) {
            if (visited[i] == false) {
                dfs_util(i, time_finish);
            }
        }

        visited.clear();
        visited = std::vector<bool>(N + 1, false);


        for (int i = N; i > 0; i--) {
            if (visited[time_finish[i]] == false) {
                std::vector<int> new_solution;
                dfs_adjacent(time_finish[i], new_solution);
                connex_comp.push_back(new_solution);
            }
        }


        return connex_comp;
    }


    void print(std::vector<std::vector<int>> connex_components) {

        std::ofstream out("ctc.out");

        out<<connex_components.size();

        out<<"\n";

        for (auto const &vect : connex_components) {
            for (auto const & elem: vect) {
                out<<elem<<" ";
            }
            out<<"\n";
        }

        out.close();

        return;

    }



 public:

    void solve() {

        read_input();
        print(ctc_kosaraju());

    }



};



int main() {

    Task* task = new Task();

    task->solve();

    delete(task);



    return 0;

}

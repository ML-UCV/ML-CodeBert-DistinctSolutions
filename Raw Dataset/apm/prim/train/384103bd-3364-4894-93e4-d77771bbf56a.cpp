#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

const int INF = 2e9;
const int NMAX = 2e5 + 1;

std::ifstream in("apm.in");
std::ofstream out("apm.out");

typedef std::pair <int, std::pair<int, int> > pip;
std::priority_queue <pip, std::vector<pip>, std::greater<> > heap;
std::vector<std::pair<int, int> > graf[NMAX];
std::vector<std::pair<int, int> > sol;
bool viz[NMAX];
int N, M;
int costTotal = 0;

void Dijkstra ();

int main() {
    in >> N >> M;
    int n1, n2, val;
    for (int i = 1; i <= M; i++) {
        in >> n1 >> n2 >> val;
        graf[n1].push_back({n2, val});
        graf[n2].push_back({n1, val});
    }

    Dijkstra();
    out << costTotal << " " << N - 1 << "\n";
    for (auto elem : sol)
        out << elem.first << " " << elem.second << "\n";
}

void Dijkstra () {

    int root = 1;
    viz[root] = true;
    for (auto elem : graf[root]) {
        heap.push({elem.second,{root, elem.first}});
    }

    while (!heap.empty()) {
        pip best = heap.top();
        heap.pop();

        int cost = best.first;
        int new_node = best.second.second;

        if (!viz[new_node]) {
            viz[new_node] = true;
            sol.push_back(best.second);
            costTotal += cost;

            for (auto edge : graf[new_node]) {
                if (!viz[edge.first])
                    heap.push({edge.second, {new_node, edge.first}});
            }
        }
    }
}

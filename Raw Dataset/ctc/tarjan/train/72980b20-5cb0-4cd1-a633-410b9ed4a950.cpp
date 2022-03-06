#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

ifstream cin ("ctc.in");
ofstream cout ("ctc.out");

const int NMAX = 1e5 + 14;

vector <int> gr[NMAX];
bitset <NMAX> inStack;

pair <int, int> info [NMAX];

int currentNodeLabel = 0;
vector <int> stack;

void dfs(int node, vector < vector <int> > &ctc) {
    ++ currentNodeLabel;
    info[node] = {currentNodeLabel, currentNodeLabel};
    stack.push_back(node);
    inStack[node] = 1;
    for (auto &neigh : gr[node]) {
        if (info[neigh].first == 0) {
            dfs(neigh, ctc);
            info[node].second = min(info[node].second, info[neigh].second);
        }
        else if (inStack[neigh] == 1) {
            info[node].second = min(info[node].second, info[neigh].first);
        }
    }
    if (info[node].first == info[node].second) {

        int current;
        vector <int> aux;
        do {
            current = stack.back();
            aux.push_back(current);
            inStack[current] = 0;
            stack.pop_back();
        }while (current != node);
        ctc.push_back(aux);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m --) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    vector < vector <int> > ctc;
    for (int i = 1; i <= n; ++ i) {
        if (info[i].first == 0) {
            dfs(i, ctc);
        }
    }



    cout << ctc.size() << '\n';
    for (auto &x : ctc) {
        for (auto &y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;
}

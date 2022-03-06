#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int N_MAX = 2e5 + 5;

struct Edges {
    int x, y, c;

    bool operator < (const Edges other) const {
        return c < other.c;
    }
};

int N, M;
int dad[N_MAX], rnk[N_MAX];

vector <Edges> edges, answer;

int root(int node) {
    if(node == dad[node])
        return node;
    return dad[node] = root(dad[node]);
}

void join(int x, int y) {
    x = root(x);
    y = root(y);

    if(rnk[x] == rnk[y]) {
        rnk[x] ++;
        dad[y] = x;
    }
    else
        if(rnk[x] > rnk[y])
            dad[y] = x;
        else
            dad[x] = y;
}


int main() {
    fin >> N >> M;

    for(int i = 1; i <= N; i++)
        dad[i] = i;

    for(int i = 1; i <= M; i++) {
        int x, y, c;
        fin >> x >> y >> c;
        edges.push_back({x, y, c});
    }

    sort(edges.begin(), edges.end());

    long long APM = 0;

    for(auto it : edges) {
        if(root(it.x) != root(it.y)) {
            join(it.x, it.y);
            APM += it.c;
            answer.push_back(it);
        }
    }

    fout << APM << '\n' << N - 1 << '\n';
    for(auto it : answer)
        fout << it.x << ' ' << it.y << '\n';

    return 0;
}

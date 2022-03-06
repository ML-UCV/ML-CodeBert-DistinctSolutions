# include <fstream>
# include <vector>
# include <queue>
# include <bitset>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int MAX = 30005;
const int INF = (1<<30);
int n, m, x, y;
int dist[MAX];
struct inf {
    int v, c;
};
vector<inf> L[MAX];
queue<int> q;
bitset<MAX> viz;

inf per(int a, int b) {
    inf X;
    X.v = a;
    X.c = b;
    return X;
}

void get_distance(int x) {

}

int main() {
    int px, py, pc, nod;
    fin >> n >> m >> x >> y;
    for (int i=1; i<=m; i++) {
        fin >> px >> py >> pc;
        L[px].push_back(per(py, pc));
        L[py].push_back(per(px, -pc));
    }

    viz[x] = 1;
    vector<inf>::iterator it;
    for (it=L[x].begin(); it!=L[x].end(); it++) {
        dist[it->v] = it->c;
        q.push(it->v);
        viz[it->v] = 1;
    }


    while (!q.empty()) {
        nod = q.front();
        for (it=L[nod].begin(); it!=L[nod].end(); it++) {
            if (viz[it->v] == 0) {
                dist[it->v] = dist[nod] + it->c;
                viz[it->v] = 1;
                q.push(it->v);
            }
        }
        q.pop();
    }

    fout << dist[y];

    return 0;
}

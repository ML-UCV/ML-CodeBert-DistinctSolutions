#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 30003;

int n,m,x,y;
vector<pair<int,int>> muchii[NMAX];

void bf(int nod) {
    ofstream fout("sate.out");

    int nodcrt;
    vector<bool> viz(NMAX, false);
    queue<int> q;
    vector<int> dist(NMAX);

    viz[nod] = true;
    q.push(nod);

    while (!q.empty()) {
        nodcrt = q.front();
        q.pop();

        for (auto &elem : muchii[nodcrt]) {
            int vecin = elem.first;
            int d = elem.second;

            if (!viz[vecin]) {
                viz[vecin] = true;
                q.push(vecin);
                dist[vecin] = dist[nodcrt] + d;

                if (vecin == y) {
                    fout << dist[y];
                    break;
                }
            }
        }
    }
    fout.close();
}

int main() {

    ifstream fin("sate.in");

    fin >> n >> m >> x >> y;

    for (int i = 0; i < m; i++) {
        int a,b,d;
        fin >> a >> b >> d;
        muchii[a].push_back(make_pair(b,d));
        muchii[b].push_back(make_pair(a,-d));
    }

    bf(x);

    fin.close();
    return 0;
}

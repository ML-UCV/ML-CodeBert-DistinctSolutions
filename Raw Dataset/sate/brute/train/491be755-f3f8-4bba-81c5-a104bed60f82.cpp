#include <fstream>
#include <vector>
#define DEF 100100

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int n, m, start, dest, p, u, viz[DEF];

pair < int, int > c[DEF];

vector < pair < int, int > > D[DEF];

int main () {
    fin >> n >> m >> start >> dest;

    if (start > dest)
        swap (start, dest);

    for (int i = 1; i <= m; ++ i) {
        int x, y, c;
        fin >> x >> y >> c;
        D[x].push_back (make_pair (y, c));
        D[y].push_back (make_pair (x, - c));
    }

    c[++ u] = make_pair (start, 0);
    viz[start] = 1;
    while (p <= u) {
        int nod = c[p].first;
        int cost = c[p].second;

        for (int i = 0; i < D[nod].size (); ++ i) {
            if (viz[D[nod][i].first] == 0) {
                viz[D[nod][i].first] = 1;
                int new_cost = cost + D[nod][i].second;

                c[++ u] = make_pair (D[nod][i].first, new_cost);

                if (D[nod][i].first == dest) {
                    fout << new_cost;
                    return 0;
                }
            }
        }
        ++ p;
    }

    return 0;
}

#include <fstream>
#include <vector>
#define DIM 30005

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int n, m, x, y, t, i, j, d, p, u, nod, vecin;
int c[DIM], v[DIM], l[DIM];

vector < pair <int, int> > L[DIM];

int main()
{
    fin >> n >> m >> x >> y;
    for (t=1; t<=m; t++){
        fin >> i >> j >> d;
        L[i].push_back({j, d});
        L[j].push_back({i, -d});
    }
    p = u = 1;
    c[1] = x;
    v[x] = 1;
    while (p <= u){
        nod = c[p];
        for (i=0; i<L[nod].size(); i++){
            vecin = L[nod][i].first;
            if (v[vecin] == 0){
                c[++u] = vecin;
                l[vecin] = l[nod] + L[nod][i].second;
                v[vecin] = 1;
            }
        }
        p++;
    }
    fout << l[y];
    return 0;
}

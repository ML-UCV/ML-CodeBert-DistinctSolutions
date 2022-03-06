#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int v[30005], c[30005], n, compconex, i, j, m, X, Y, x, y, d, f[30005];

vector<pair<int, int> > L[30005];

void bfs(int start, int componenta) {
    v[start] = componenta;
    c[1] = start;
    int p = 1, u = 1;
    while (p <= u) {
        int nod = c[p];
        for (i = 0; i < L[nod].size(); i++) {
            pair<int, int> vecin = L[nod][i];
            if(v[vecin.first] == 0){
                c[++u] = vecin.first;
                v[vecin.first] = componenta;
                if(vecin.first > nod){
                    f[vecin.first] = f[nod] + vecin.second;
                }
                else{
                    f[vecin.first] = f[nod] - vecin.second;
                }
            }
        }
        p++;
    }
}

int main()
{
    fin>>n>>m>>X>>Y;
    for(int i = 1; i <= m; i++){
        fin>>x>>y>>d;
        L[x].push_back(make_pair(y, d));
        L[y].push_back(make_pair(x, d));
    }
    bfs(X, 1);
    fout<<f[Y];
    return 0;
}

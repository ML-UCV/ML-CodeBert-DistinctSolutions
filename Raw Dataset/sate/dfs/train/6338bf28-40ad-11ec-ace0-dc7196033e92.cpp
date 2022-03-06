#include <fstream>
#include <vector>

using namespace std;

ifstream fin("sate.in") ;
ofstream fout("sate.out");

struct str {
    int x, y;
};

const int nmax=30000;
vector <str> g[nmax+1];
int sol[nmax+1];

void dfs (int x) {
    for (vector <str>::iterator it = g[x].begin(); it != g[x].end(); ++ it ) {
        if (sol[it->x]==0) {
            sol[it->x]=sol[x]+it->y;
            dfs(it->x);
        }
    }
}

int main () {
    int n, m, a, b;
    fin>>n>>m>>a>>b;

    for (int i=1; i<=m; i++) {
        int x, y, c;
        fin>>x>>y>>c;
        str aux;
        aux.x=y;
        aux.y=c;
        g[x].push_back(aux);
        aux.x=x;
        aux.y=-c;
        g[y].push_back(aux);
    }

    sol[a]=3e7;
    dfs(a);

    fout<<sol[b]-sol[a]<<"\n";

    return 0;
}

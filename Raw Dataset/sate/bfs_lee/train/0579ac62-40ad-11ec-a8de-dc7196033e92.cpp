#include <fstream>
#include <vector>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int m, X, Y, i, j, t, d, dist[30003];
short c[30003], crt, var, p, u, a, b, n;
char f[30003];
vector<pair <int, int> > v[30003];

int main(){
    fin>>n>>m>>X>>Y;
    for(i=1;i<=m;i++){
        fin>>a>>b>>d;
        v[a].push_back(make_pair(b, d));
        v[b].push_back(make_pair(a,d));
    }
    p = u = 1;
    c[1] = X;
    f[X] = 1;
    while(p<=u){
        crt = c[p];
        for(i=0;i<v[crt].size();i++){
            var = v[crt][i].first;
            if(f[var] == 0){
                f[var] = 1;
                c[++u] = var;
                if((crt < X && var < crt) || (crt > X && var > crt))
                    dist[var] = v[crt][i].second + dist[crt];
                else
                    if((var < X && crt < var) || (var > X && crt > var))
                        dist[var] = -v[crt][i].second + dist[crt];
                    else
                        dist[var] = v[crt][i].second - dist[crt];

                if(var == Y){
                    fout<<dist[var];
                    return 0;
                }
            }
        }
        p++;
    }
    return 0;
}

#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector< pair<int, int> >a[30010];
int n, m, c[900010], d[30010], v[30010], i, j, st, dr, x, y, z, p, u, sol, k;

int main(){
    fin>>n>>m>>st>>dr;
    for(i=1; i<=m; i++){
        fin>>x>>y>>z;
        a[x].push_back(pair<int, int>(y, z));
        a[y].push_back(pair<int, int>(x, z));
    }
    p=1;
    u=1;
    c[1]=st;
    v[1]=1;
    while(p<=u){
        int nod=c[p];
        if(nod==dr){
            break;
        }
        for(int ii=0; ii<a[nod].size(); ii++){
            int nod2=a[nod][ii].first;
            if(v[nod2]==0){
                v[nod2]=1;
                if(nod<nod2){
                    d[nod2]=d[nod]+a[nod][ii].second;
                }else{
                    d[nod2]=d[nod]-a[nod][ii].second;
                }
                u++;
                c[u]=nod2;
            }
        }
        p++;
    }
    fout<<d[dr];
}

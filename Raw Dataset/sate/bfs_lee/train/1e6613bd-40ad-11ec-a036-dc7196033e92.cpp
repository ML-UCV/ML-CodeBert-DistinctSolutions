#include <fstream>
#include <vector>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
const int N = 30002;
int d[N], c[N];
vector < pair <int,int> > v[N];
void bfs(int ns){
    int st = 1, dr = 1, sz, nc;
    d[ns] = 1;
    c[1] = ns;
    while(st <= dr){
        nc = c[st];
        sz = v[nc].size();
        for(int i=0;i<sz;i++)
            if(d[v[nc][i].first] == 0){
                c[++dr] = v[nc][i].first;
                if(nc < v[nc][i].first)
                    d[v[nc][i].first] = d[nc] + v[nc][i].second;
                else
                    d[v[nc][i].first] = d[nc] - v[nc][i].second;
            }
        st++;
    }
}
int main()
{
    int n,m,xi,yi,x,y,z;
    in>>n>>m>>xi>>yi;
    for(int i=1;i<=m;i++){
        in>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    in.close();
    bfs(xi);
    if(xi > yi)
        out<<1 - d[yi]<<"\n";
    else
        out<<d[yi] - 1<<"\n";
    out.close();
    return 0;
}

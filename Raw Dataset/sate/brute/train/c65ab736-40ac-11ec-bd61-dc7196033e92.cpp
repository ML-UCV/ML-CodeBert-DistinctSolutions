#include <bits/stdc++.h>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,x,y;
int nod1,nod2;
vector < int > knots[30005];
vector < int > dt[30005];
int viz[30005];
int dist[30005];
int distnc;

void graph(int nod, int distnc) {
    dist[nod]= distnc;
    viz[nod]=1;
    for (int k=0;k<knots[nod].size();k++) {
        int nodtoviz = knots[nod][k];
        if (viz[nodtoviz]==0) {
            if (nodtoviz<nod) {
                graph(nodtoviz,distnc-dt[nod][k]);
            }
            else {
                graph(nodtoviz,distnc+dt[nod][k]);
            }
        }
    }
}

int main()
{
    f >> n >> m >> nod1 >> nod2;
    for (int i=1;i<=m;i++) {
        f >> x >> y >> distnc;
        knots[x].push_back(y);
        knots[y].push_back(x);
        dt[x].push_back(distnc);
        dt[y].push_back(distnc);
    }
    graph(nod1,0);
    g << dist[nod2];
    return 0;
}

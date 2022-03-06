#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define DIM 30002
#define pr pair<int, int>
#define f first
#define s second

using namespace std;

ifstream in ("sate.in");
ofstream out("sate.out");

int n, viz[DIM], m, xi, xf, x, y, d[DIM], dist;

vector<pr > graf[DIM];

queue<int> q;

int main(int argc, const char * argv[]) {
    in>>n>>m>>xi>>xf;
    for(int i = 1; i <= m; ++ i){
        in>>x>>y>>dist;
        graf[x].push_back(make_pair(y, dist));
        graf[y].push_back(make_pair(x, dist));
    }
    
    q.push(xi);
    
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(int i = 0; i < graf[nod].size(); ++ i){
            int nodc = graf[nod][i].f;
            int dist = graf[nod][i].s;
            if(!viz[nodc]){
                if(nodc < nod)
                    d[nodc] = d[nod] - dist;
                else
                    d[nodc] = d[nod] + dist;
                q.push(nodc);
                viz[nodc] = 1;
            }
            if(nodc == xf){
                out<<d[nodc];
                return 0;
            }
        }
    }
    
    return 0;
}

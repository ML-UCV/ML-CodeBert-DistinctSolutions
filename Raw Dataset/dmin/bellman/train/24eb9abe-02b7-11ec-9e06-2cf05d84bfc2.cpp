#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int N, M, sol[1510], viz[1510];
double dmin[1510];
vector<pair<int, double> > G[1510];

void BellmanFord() {
    int i, p;
    queue<int> Q;
    bool InQueue[1510];
    for(i=1; i<=N; i++) {
         InQueue[i] = false;
         dmin[i] = 99999999;
    }
    InQueue[1] = true;
    Q.push(1);
    dmin[1] = 0; sol[1] = 1;
    while(!Q.empty()) {
         p = Q.front(); Q.pop();
         InQueue[p] = false;
         for(vector<pair<int, double> >::iterator it=G[p].begin(); it!=G[p].end(); it++) {
              if(0.00001 < dmin[(*it).first] - dmin[p] - (*it).second) {
                   dmin[(*it).first] = dmin[p] + (*it).second;
                   sol[(*it).first] = sol[p];
                   if(!InQueue[(*it).first]) {
                        InQueue[(*it).first] = 1;
                        Q.push((*it).first);
                   }
              }
              else if(dmin[p] + (*it).second - dmin[(*it).first] <= 0.00001) {
                   sol[(*it).first] += sol[p];
                   sol[(*it).first] %= 104659;
              }
         }
    }
}

int main() {
    FILE *f1=fopen("dmin.in", "r"), *f2=fopen("dmin.out", "w");
    int i, j, p, q;

    fscanf(f1, "%d %d\n", &N, &M);
    for(i=1; i<=M; i++) {
         fscanf(f1, "%d %d %d\n", &p, &q, &j);
         double cost = (double)log(j);

         G[p].push_back( make_pair(q, cost) );
         G[q].push_back( make_pair(p, cost) );
    }

    BellmanFord();

    for(i=2; i<=N; i++) {
         fprintf(f2, "%d ", sol[i]);
    }

    fclose(f1); fclose(f2);
    return 0;
}

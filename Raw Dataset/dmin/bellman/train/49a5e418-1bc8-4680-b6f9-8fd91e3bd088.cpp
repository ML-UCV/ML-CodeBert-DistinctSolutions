#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>





using namespace std;

FILE *f=fopen("dmin.in", "r");

FILE *g=fopen("dmin.out", "w");


int N, M, sol[1510];
double D[1510];
vector< pair < int, double > > G[1510];
queue<int> Q;
bool viz[1510];
void BellmanFord() {
    int i, x;

    for(i=1; i<=N; i++) {
         viz[i] = false;
  D[i] = 99999999;
    }
    viz[1] = true;
    Q.push(1);
    D[1] = 0;

 sol[1] = 1;
    while(!Q.empty()) {


  x=Q.front();

  Q.pop();
  viz[x] = false;
  for(vector< pair < int, double > >::iterator it=G[x].begin(); it!=G[x].end(); it++) {
   if(0.00000001 < D[(*it).first] -D[x] - (*it).second) {
    D[(*it).first] = D[x] + (*it).second;
    sol[(*it).first] = sol[x];
     if(!viz[(*it).first]) {
                        viz[(*it).first] = 1;
                        Q.push((*it).first);
     }
   }
   else

    if(D[x] + (*it).second - D[(*it).first] <= 0.00000001) {
                   sol[(*it).first] += sol[x];
                   sol[(*it).first] %= 104659;
    }
  }
    }
}

int main() {

    int i, j, x, y;

    fscanf(f, "%d %d\n", &N, &M);
    for(i=1; i<=M; i++) {
         fscanf(f, "%d %d %d\n", &x, &y, &j);
         double cost = (double)log(j);

         G[x].push_back( make_pair(y, cost) );
         G[y].push_back( make_pair(x, cost) );
    }

    BellmanFord();

    for(i=2; i<=N; i++) {
  fprintf(g, "%d ", sol[i]);
    }

    fclose(f);

 fclose(g);
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>





using namespace std;

vector<pair<int, double> > adList[2501];
int paths[2501], inQueue[2501];
queue<int> Q;
int n, m;
double distances[2501];

void dmin(){
 Q.push(1);
 inQueue[1] = 1;
 paths[1] = 1;

 while(!Q.empty()){
  int node = Q.front();
  Q.pop();

  vector<pair<int, double> >::iterator it = adList[node].begin();
  while(it != adList[node].end()){
   pair<int, double> neigh = *it;
   if(distances[neigh.first] - 0.0000001 > distances[node] + neigh.second){
    distances[neigh.first] = distances[node] + neigh.second;
    paths[neigh.first] = paths[node];
    if(inQueue[neigh.first] == 0){
     Q.push(neigh.first);
     inQueue[neigh.first] = 1;
   }
   }
   else{
    if(distances[neigh.first] + 0.0000001 >= distances[node] + neigh.second){
     paths[neigh.first] += paths[node];
     paths[neigh.first] %= 104659;
    }
   }

   it++;
  }

 }

}

int main(){
 ifstream f("dmin.in");
 ofstream g("dmin.out");

 int x, y, c;

 f >> n >> m;
 for(int i = 0; i < m; i++){
  f >> x >> y >> c;
  adList[x].push_back(make_pair(y, log(c)));
  adList[y].push_back(make_pair(x, log(c)));
 }
 f.close();

 for(int i = 2; i <= n; i++)
  distances[i] = 1000000000;

 dmin();

 for(int i = 2; i <= n; i++)
  g << paths[i] << " ";

 g.close();
 return 0;
}

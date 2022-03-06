#include <bits/stdc++.h>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

vector < vector < pair <int, int> > > adjList;
int V, E;

int main(){

 fin >> V >> E;

 adjList.resize(V + 1);

 for(int e = 0; e < E; ++e){

  int u, v, c;
  fin >> u >> v >> c;

  adjList[u].push_back({v, c});
  adjList[v].push_back({u, c});
 }

 vector < pair <int, int> > connEdge(V + 1, {0, INT_MAX});
 vector <bool> used(V + 1);

 set < pair <int, int> > RB;

 used[1] = true;
 for(pair <int, int> &edge : adjList[1])
  connEdge[edge.first] = {1, edge.second}, RB.insert({edge.second, edge.first});

 int mstCost = 0;
 for(int it = 1; it < V; ++it){


  pair <int, int> Find = *RB.begin();
  RB.erase(RB.begin());

  int minCost = Find.first;
  int addNode = Find.second;

  mstCost += minCost;
  used[addNode] = true;

  for(pair <int, int> &edge : adjList[addNode])
   if(!used[edge.first] and edge.second < connEdge[edge.first].second){

    if(RB.count({connEdge[edge.first].second, edge.first}))
     RB.erase({connEdge[edge.first].second, edge.first});

    connEdge[edge.first] = {addNode, edge.second};
    RB.insert({edge.second, edge.first});
   }
 }

 fout << mstCost << '\n' << V - 1 << '\n';

 for(int node = 2; node <= V; ++node)
  fout << node << ' ' << connEdge[node].first << '\n';
}

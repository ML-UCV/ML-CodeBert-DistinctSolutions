#include<bits/stdc++.h>
using namespace std;


ifstream in("apm.in");
ofstream out("apm.out");

int num_nodes,num_edges;


struct edge{
 int a,b,cost;
} edges[400000];

bool cmp(edge&a,edge&b){
 return a.cost<b.cost;
}


int father[200001];
int depth[200001];

int root(int a){
 while(father[a])
  a=father[a];

 return a;
}

void read(){
 in>>num_nodes>>num_edges;
 for(int i=0;i<num_edges;i++)
  in>>edges[i].a>>edges[i].b>>edges[i].cost;
 sort(edges,edges+num_edges,cmp);
}

void unite(int a,int b){
 if(depth[a]==depth[b]){
  father[b]=a;
  depth[a]++;
 }
 else if(depth[a]<depth[b]){
  father[a]=b;
 }
 else{
  father[b]=a;
 }
}




void kruskal(){
 int cost=0;
 vector<std::pair<int,int>> results;
 for(int i=0;i<num_edges;i++){
  int a=edges[i].a;
  int b=edges[i].b;

  if(root(a)!=root(b)){
   unite(root(a),root(b));
   cost+=edges[i].cost;
   results.push_back({a,b});
  }
 }

 out<<cost<<'\n';
 out<<results.size()<<'\n';
 for(int i=0;i<results.size();i++)
  out<<results[i].first<<" "<<results[i].second<<'\n';

}


int main(){
 read();
 kruskal();

 return 0;
}

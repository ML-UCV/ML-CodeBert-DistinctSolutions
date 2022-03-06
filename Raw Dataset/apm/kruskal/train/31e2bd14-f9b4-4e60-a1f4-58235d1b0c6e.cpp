#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");




int father[200000 +1],depth[200000 +1];
int num_nodes,num_edges;

struct edge{
 int a,b,cost;
} edges[400000];

bool compare(const edge&a,const edge&b){
 return a.cost<b.cost;
}

int unite(int first_root,int second_root){
 if(depth[first_root]==depth[second_root]){
  father[first_root]=second_root;
  depth[second_root]++;
 }
 else if(depth[first_root]<depth[second_root]){
  father[first_root]=second_root;
 }
 else{
  father[second_root]=first_root;
 }
}

int get_root(int node){
 while(father[node]){
  node=father[node];
 }
 return node;
}

void solve(){
 sort(edges,edges+num_edges,compare);

 int cost=0;
 vector<edge>result;
 for(int i=0;i<num_edges;i++){
  edge e=edges[i];
  int roota=get_root(e.a),rootb=get_root(e.b);
  if(roota!=rootb){
   unite(roota,rootb);
   result.push_back(e);
   cost+=e.cost;
  }
 }
 out<<cost<<'\n'<<result.size()<<'\n';
 for(const edge&e:result)
  out<<e.a<<' '<<e.b<<'\n';
}

void read(){
 in>>num_nodes>>num_edges;
 for(int i=0;i<num_edges;i++){
  in>>edges[i].a>>edges[i].b>>edges[i].cost;
 }
}


int main(){
 read();
 solve();
 return 0;

}

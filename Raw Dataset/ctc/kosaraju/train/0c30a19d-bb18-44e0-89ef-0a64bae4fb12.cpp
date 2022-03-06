#include<bits/stdc++.h>
using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

vector<int> graph[100000];
vector<int> transposed_graph[100000];
bool visited[100000];
vector<int> order;
int node_count;


void read(){
 int edge_count;
 int a,b;
 in>>node_count>>edge_count;
 for(int i=0;i<edge_count;i++){
  in>>a>>b;
  graph[a-1].push_back(b-1);
  transposed_graph[b-1].push_back(a-1);
 }
}


int dfs1(int node){
 visited[node]=true;
 for(int i=0;i<graph[node].size();i++){
  int there=graph[node][i];
  if (!visited[there])
   dfs1(there);
 }
 order.push_back(node);
}
int dfs2(int node,vector<int>&to_fill){
 visited[node]=true;
 to_fill.push_back(node);
 for(int i=0;i<transposed_graph[node].size();i++){
  int there=transposed_graph[node][i];
  if(!visited[there])
   dfs2(there,to_fill);
 }
}

void solve(){
 int cnt=0;
 for(int i=0;i<node_count;i++){
  if(!visited[i])
   dfs1(i);
 }
 for(int i=0;i<node_count;i++)
  visited[i]=false;

 vector<vector<int>> connected;

 for(int k=node_count-1;k>=0;k--){
  if(!visited[order[k]]){
   vector<int> result;
   dfs2(order[k],result);
   connected.push_back(result);
  }
 }

 out<<connected.size()<<endl;
 for(int i=0;i<connected.size();i++){
  for(int a:connected[i])
   out<<a+1<<" ";
  out<<'\n';
 }
}

int main(){
 read();
 solve();
 return 0;
}

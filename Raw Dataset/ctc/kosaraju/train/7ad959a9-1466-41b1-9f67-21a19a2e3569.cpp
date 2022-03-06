#include<bits/stdc++.h>
using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");


int num_nodes,num_edges;
vector<int> graph[100000];
vector<int> transposed[100000];
vector<int> order;
bool visited[100000];

void read(){
 in>>num_nodes>>num_edges;
 int a,b;

 for(int i=0;i<num_edges;i++){
  in>>a>>b;
  graph[a-1].push_back(b-1);
  transposed[b-1].push_back(a-1);
 }
}


void dfs1(int node){
 visited[node]=true;
 for(int i=0;i<graph[node].size();i++)
  if(!visited[graph[node][i]])
   dfs1(graph[node][i]);

 order.push_back(node);
}

void dfs2(int node,vector<int>&to_add){
 visited[node]=true;
 to_add.push_back(node);
 for(int i=0;i<transposed[node].size();i++)
  if(!visited[transposed[node][i]])
   dfs2(transposed[node][i],to_add);
}


void kosaraju(){
 for(int i=0;i<num_nodes;i++)
  if(!visited[i])
   dfs1(i);

 for(int i=0;i<num_nodes;i++)
  visited[i]=false;

 vector<vector<int>> result;
 for(int i=order.size()-1;i>=0;i--){
  int node=order[i];
  if(!visited[node]){
   vector<int> results;
   dfs2(node,results);
   result.push_back(results);
  }
 }
 out<<result.size()<<'\n';
 for(const vector<int>&a:result){
  for(int p:a)
   out<<p+1<<" ";
  out<<'\n';
 }

}


int main(){
 read();
 kosaraju();;
 return 0;
}

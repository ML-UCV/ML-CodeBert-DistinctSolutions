#include<string.h> // for memset
#include<iostream> 
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

ifstream in ("ctc.in");
ofstream out("ctc.out");


vector<int> transposed_graph[100000];
vector<int> graph[100000];
vector<int> order;
bool visited[100000];
int num_nodes,num_edges;


void read(){
 int a,b;
 in>>num_nodes>>num_edges;
 for(int i=0;i<num_edges;i++){
  in>>a>>b;
  graph[a-1].push_back(b-1);
  transposed_graph[b-1].push_back(a-1);

 }
}

void dfs1(int node){
 visited[node]=true;
 for(int neighbour:graph[node]){
  if(!visited[neighbour])
   dfs1(neighbour);
 }
 order.push_back(node);
}

void dfs2(int node,vector<int>&to_add){
 visited[node]=true;
 to_add.push_back(node);
 for(int neighbour:transposed_graph[node]){
  if(!visited[neighbour]){
   dfs2(neighbour,to_add);
  }
 }
}
void solve(){

 for(int i=0;i<num_nodes;i++){
  if(!visited[i]){
   dfs1(i);
  }
 }
 memset(visited,0,sizeof(visited));
 std::reverse(order.begin(),order.end());
 vector<vector<int>> components;

 for(int a:order){
  if(!visited[a]){
   vector<int> queue;
   dfs2(a,queue);
   components.push_back(queue);
  }
 }

 out<<components.size()<<endl;

 for(const vector<int>&queue:components){
  for(int a:queue)
   out<<a+1<<" ";
  out<<'\n';
 }
}

int main(){

 read();
 solve();
 return 0;
}

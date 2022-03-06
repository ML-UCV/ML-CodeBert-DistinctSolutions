#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<set>
#include<deque>
#include<queue>
using namespace std;

const int mx=1000;

ifstream in("party.in");
ofstream out("party.out");

vector<int> g[mx],gt[mx],q;
bool visited[mx],possible=true;
int n,m,result[mx],cnt[mx];

int node(int x){
 if(x<0){
  return n+abs(x);
 }
 return x;
}

int val(int node){
 if(node>n){
  return n-node;
 }
 return node;
}


void read(){
 in>>n>>m;
 int a,b,c;
 for(int i=0;i<m;i++){
  in>>a>>b>>c;
  if(c==3){
   a=-a;
   b=-b;
  }
  else if(c==1){
   b=-b;
  }
  else if(c==2){
   a=-a;
  }
  g[node(-a)].push_back(node(b));
  gt[node(b)].push_back(node(-a));
  g[node(-b)].push_back(node(a));
  gt[node(a)].push_back(node(-b));
 }
}

void dfs1(int x){
 visited[x]=true;
 for(int k:g[x]){
  if(!visited[k])
   dfs1(k);
 }
 q.push_back(x);
}

void dfs2(int x,int value,int comp){
 cnt[x]=comp;
 visited[x]=true;
 result[x]=value;
 result[node(-val(x))]=1-value;

 for(int k:gt[x]){
  if(!visited[k]){
   dfs2(k,value,comp);
  }
 }
}
void preprocess(){
 for(int i=1;i<=2*n;i++)
  result[i]=-1;
}

void solve(){

 for(int i=1;i<=2*n;i++){
  if(!visited[i]){
   dfs1(i);
  }
 }
 for(int i=1;i<mx;i++)
  visited[i]=false;

 int count=1;
 for(auto iter=q.rbegin();iter!=q.rend();iter++){
  if(!visited[*iter]){
   dfs2(*iter,1,count);
   count++;
  }
 }

 for(int i=1;i<=n;i++){
  if(cnt[i]==cnt[n+i]){
   out<<-1;
   return;
  }
 }
 vector<int> ans;

 for(int i=1;i<=n;i++)
  if(result[i])
   ans.push_back(i);

 out<<ans.size()<<endl;
 for(int k:ans)
  out<<k<<'\n';
}

int main(){
 read();
 solve();
 return 0;
}

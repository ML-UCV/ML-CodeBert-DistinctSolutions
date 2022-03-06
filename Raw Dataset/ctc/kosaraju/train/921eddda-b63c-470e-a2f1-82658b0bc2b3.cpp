#include <bits/stdc++.h>
using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m;

struct kosaraju{
 struct nod{
  bool viz, viz2;
  vector<int> in;
  vector<int> out;
 };
 vector<nod> g;
 struct comp{
  vector<int> v;
 };
 vector<comp> v;
 stack<int> s;
 void visit(int root){
  g[root].viz=1;
  for(auto it:g[root].out){
   if(!g[it].viz) visit(it);
  }
  s.push(root);
 }
 void build(int root){
    v.back().v.push_back(root);
    g[root].viz2=1;
    for(auto it:g[root].in){
      if(!g[it].viz2) build(it);
    }
  }
 bool get(){
  if(s.empty()) return 0;
  v.push_back({});
  while(!s.empty()&&g[s.top()].viz2) s.pop();
  if(s.empty()) return 0;
  build(s.top());
    return 1;
 }
};

int main(){
 fin>>n>>m;
 kosaraju x;
 x.g.resize(n+1);
 for(int i=1;i<=m;++i){
  int a, b;
  fin>>a>>b;
  x.g[a].out.push_back(b);
  x.g[b].in.push_back(a);
 }
 for(int i=1;i<=n;++i) if(!x.g[i].viz) x.visit(i);
  while(x.get());
  fout<<x.v.size()-1<<"\n";
  for(auto it:x.v){
    for(auto jt:it.v) fout<<jt<<" ";
    fout<<"\n";
  }
 return 0;
}

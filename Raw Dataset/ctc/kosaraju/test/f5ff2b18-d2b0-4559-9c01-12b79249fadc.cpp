#include <bits/stdc++.h>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

vector<int> graf[100005];
vector<int> ans[100005];
vector<int> graf1[100005];
int viz[100005],ans1;

stack<int> s;
int dfs(int nod,int ok,vector<int> x[100005])
{
 viz[nod]=1;
 if(ok<0)
  ans[ans1].push_back(nod);
 for(int i=0;i<x[nod].size();i++)
  if(viz[x[nod][i]]==0)
   dfs(x[nod][i],ok,x);
 if(ok>0)
  s.push(nod);
}


int main()
{
 int n,m;
 in>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int x,y;
  in>>x>>y;
  graf[x].push_back(y);
  graf1[y].push_back(x);
 }
 for(int i=1;i<=n;i++)
  if(viz[i]==0)
   dfs(i,1,graf);
 memset(viz,0,sizeof(viz));
 while(!s.empty())
 {
  if(viz[s.top()]==0)
  {
   ans1++;
   dfs(s.top(),-1,graf1);
  }
  s.pop();
 }
 out<<ans1<<"\n";
 for(int i=1;i<=ans1;i++)
 {
  for(int j=0;j<ans[i].size();j++)
   out<<ans[i][j]<<" ";
  out<<"\n";
 }
 return 0;
}

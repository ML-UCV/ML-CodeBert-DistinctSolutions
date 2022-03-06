#include <bits/stdc++.h>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

vector<int> graf[100005];
vector<int> ans[100005];

stack<int> st;
int a[100005],b[100005];
bool instack[100005];
int t,ans1;
void tarjan(int x)
{
 t++;
 a[x]=t;
 b[x]=t;
 st.push(x);
 instack[x]=1;
 for(auto k:graf[x])
 {
  if(a[k]==0)
  {
   tarjan(k);
   b[x]=min(b[x],b[k]);
  }
  else if(instack[k])
   b[x]=min(b[x],b[k]);
 }
 if(b[x]==a[x])
 {
  while(!st.empty() && b[x]<=b[st.top()])
  {
   ans[ans1].push_back(st.top());
   instack[st.top()]=0;
   st.pop();
  }
  ans1++;
 }
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
 }
 for(int i=1;i<=n;i++)
  if(a[i]==0)
   tarjan(i);
 out<<ans1<<"\n";
 for(int i=0;i<ans1;i++)
 {
  for(int j=0;j<ans[i].size();j++)
   out<<ans[i][j]<<" ";
  out<<"\n";
 }
 return 0;
}

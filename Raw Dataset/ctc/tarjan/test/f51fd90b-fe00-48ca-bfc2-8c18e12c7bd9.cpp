#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,m,a,b,cnt;

bitset<100010> ok;

int x[100010],y[100010];

vector<int> v[100010];

vector<vector<int> > C;

stack<int> St;



void dfs(int poz){

 x[poz]=y[poz]=++cnt;

 St.push(poz);ok[poz]=1;

 for(auto it:v[poz])

  if(!x[it]){

   dfs(it);

   y[poz]=min(y[poz],y[it]);

  }else

   if(ok[it])

    y[poz]=min(y[poz],x[it]);

 if(x[poz]!=y[poz])return;

 vector<int> c;

 while(1){

  int aux=St.top();St.pop();ok[aux]=0;

  c.push_back(aux);

  if(aux==poz)break;

 }

 C.push_back(c);

}



int main(){

 f>>n>>m;

 for(int i=1;i<=m;i++){

  f>>a>>b;

  v[a].push_back(b);

 }

 for(int i=1;i<=n;i++)

  if(!x[i]){

   dfs(i);

  }

 g<<C.size()<<'\n';

 for(auto it:C){

  for(auto that:it)

   g<<that<<' ';

  g<<'\n';

 }

}

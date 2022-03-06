#include <bits/stdc++.h>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,x,y;
int sol[30005];
bool fost[30005];
vector< pair<int,int> > v[100030];
queue<int>coada;

void bfs(){
  coada.push(x);
  fost[x]=1;
  while( !coada.empty() ){
    int i,j,s;
    i=coada.front();
    coada.pop();
    for(int z=0;z<v[i].size();z++){
      j=v[i][z].first;
      s=v[i][z].second;
      if( !fost[j] ){
        fost[j]=1;
        if(i<j){
         sol[j]=sol[i]+s;
        }
        else sol[j]=sol[i]-s;
        coada.push(j);
      }
    }
  }
}

int main()
{
  f>>n>>m>>x>>y;
  for(int i=1;i<=m;i++){
    int a,b,c;
    f>>a>>b>>c;
    v[a].push_back(make_pair(b,c));
    v[b].push_back(make_pair(a,c));
  }
  bfs();
  g<<sol[y];

}

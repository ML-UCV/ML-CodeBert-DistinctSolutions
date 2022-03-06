#include <bits/stdc++.h>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



vector < pair<double,int> > mv[1505];

priority_queue < pair<double,int>, vector< pair<double,int> >, greater< pair<double,int> > > q;

double cost[1505];

int viz[1505];

int answer[1505];

double EPS=1e-10;



void dijkstra(int s){

 int i,x;



 answer[s]=1;

 q.push(make_pair(0.0,s));



 while(!q.empty()){

  x=q.top().second;

  q.pop();



  if(viz[x])

   continue;



  viz[x]=1;



  for(i=0;i<mv[x].size();i++){

   if(cost[mv[x][i].second]-(cost[x]+mv[x][i].first)>=EPS){

    cost[mv[x][i].second]=cost[x]+mv[x][i].first;

    answer[mv[x][i].second]=answer[x];

    q.push(make_pair(cost[mv[x][i].second],mv[x][i].second));

   }

   else if(abs(cost[mv[x][i].second]-(cost[x]+mv[x][i].first))<EPS){

    answer[mv[x][i].second]+=answer[x];

    answer[mv[x][i].second]%=104659;

    q.push(make_pair(cost[mv[x][i].second],mv[x][i].second));

   }

  }

 }

}



int main(){

 int n,m,x,y,c,i;

 double c1;



 fin>>n>>m;



 for(i=2;i<=n;i++)

  cost[i]=1000000;



 for(i=1;i<=m;i++){

  fin>>x>>y>>c;



  c1=log2(1.0*c);



  mv[x].push_back(make_pair(c1,y));

  mv[y].push_back(make_pair(c1,x));

 }



 dijkstra(1);



 for(i=2;i<=n;i++)

  fout<<answer[i]<<" ";



    return 0;

}

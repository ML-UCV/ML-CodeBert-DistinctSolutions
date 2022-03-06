#include <bits/stdc++.h>
#include <fstream>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int nmax=400005;

int n,m,k,total,tt[nmax],rg[nmax];

pair<int,int> p[nmax];



struct edge{

 int x,y,c;

}v[nmax];



bool compare(edge a,edge b){

 return a.c<b.c;

}

int find(int nod){

 while(tt[nod] !=nod){

  nod=tt[nod];

 }

 return nod;

}

int unite(int x,int y){

 if(rg[x]<rg[y]){

  tt[x]=y;

 }

 if(rg[y]<rg[x]){

  tt[y]=x;

 }

 if(rg[x]==rg[y]){

  tt[x]=y;

  rg[y]++;

 }

}



void rez(){

 for(int i=1;i<=m;i++){

  if(find(v[i].x) !=find(v[i].y)){

   unite(find(v[i].x),find(v[i].y));

   p[++k].first=v[i].x;

   p[k].second=v[i].y;

   total += v[i].c;

  }



 }

}



int main(){

in >>n>>m;

for(int i=1;i<=m;i++){

 in >>v[i].x>>v[i].y>>v[i].c;

}

sort(v+1, v+m+1,compare);



for(int i=1;i<=m;i++){

 tt[i]=i;

 rg[i]=1;

}

rez();

out <<total<<"\n";

out <<n-1<<"\n";



for(int i=1;i<=k;i++){

 out <<p[i].first <<" "<<p[i].second<<"\n";

}



}

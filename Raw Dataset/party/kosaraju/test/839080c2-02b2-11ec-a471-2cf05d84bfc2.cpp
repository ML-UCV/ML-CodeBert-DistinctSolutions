#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;





int N,M;
bool st[105];
vector <int> edge[105];

void read_data()
{
 short int u,v,type;
 scanf("%d %d",&N,&M);
 for(int i=0;i<M;i++)
 {
  scanf("%hd %hd %hd",&u,&v,&type);
  edge[u].push_back((v<<2)|type);
  switch(type)
  {
   case 1: type=2;
    break;
   case 2: type=1;
    break;
  }
  edge[v].push_back((u<<2)|type);
 }
 for(int i=1;i<=N;i++)
  sort(edge[i].begin(),edge[i].end());
}

void back(int k)
{
 if(k==N+1)
 {

  int cnt=0;
  for(int i=1;i<=N;i++)
   if(st[i])
    cnt++;
  printf("%d\n",cnt);
  for(int i=1;i<=N;i++)
   if(st[i])
    printf("%d\n",i);
  exit(0);
 }

 short int state=-1,new_state;
 for(unsigned int i=0;(i<edge[k].size())&&(edge[k][i]<(k<<2));i++)
 {
  new_state=-1;
  switch(edge[k][i]&3)
  {
   case 0: if(!st[edge[k][i]>>2])
     new_state=1;
    break;
   case 1: if(st[edge[k][i]>>2])
     new_state=1;
    break;
   case 2: if(!st[edge[k][i]>>2])
     new_state=0;
    break;
   case 3: if(st[edge[k][i]>>2])
     new_state=0;
    break;
  }
  if(state==-1)
   state=new_state;
  else
   if(state==0)
   {
    if(new_state==1)
     return;
   }
   else
   {
    if(new_state==0)
     return;
   }
 }

 if(state==0)
 {
  st[k]=false;
  back(k+1);
  return;
 }
 else
  if(state==1)
  {
   st[k]=true;
   back(k+1);
   return;
  }
  else
  {
   st[k]=(bool)(rand()%2);
   back(k+1);
   st[k]=!st[k];
   back(k+1);
  }
}


int main()
{
 srand(N*10000+M);
 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);
 read_data();
 back(1);
 return 0;
}

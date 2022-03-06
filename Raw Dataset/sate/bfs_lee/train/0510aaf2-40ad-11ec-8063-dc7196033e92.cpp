#include <iostream>
#include <fstream>
#include <vector>
#define dim 30001
using namespace std;
ifstream fin ("sate.in");
ofstream fout("sate.out");
vector <pair <int,int> > L[dim];
int x,y,n,m,v[dim],c[dim],nod,p,u,t[dim],i,num,q,r,aux,k,sum[dim];
unsigned short cost[dim][dim];

void bfs (int a)
{
    p=1;
    u=1;
    v[a]=1;
    c[1]=a;
    while(v[r]==0&&p<=u){
        for(i=0;i<L[c[p]].size();i++)
        {
            nod=L[c[p]][i].first;
            if(v[nod]==0)
            {
                v[nod]=1;
                t[nod]=c[p];
                sum[nod]=sum[c[p]]+L[c[p]][i].second;
                u++;
                c[u]=nod;
            }
        }

p++;
    }
}
int main()
{
  fin>>n>>m>>q>>r;

  for(i=1;i<=m;i++)
  {
      fin>>x>>y>>num;
      L[x].push_back(make_pair(y,num));
      L[y].push_back(make_pair(x,0-num));
      ++k;
  }

  bfs(q);

fout<<sum[r];


}


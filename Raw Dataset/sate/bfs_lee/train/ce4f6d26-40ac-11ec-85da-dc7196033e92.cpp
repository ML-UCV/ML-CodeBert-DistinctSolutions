#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector <pair<int,int> > a[30001];
queue <int>Q;
int n,m,x,y,i,j,d,viz[30001],dist[30001];
void bfs()
{ Q.push(x);
  viz[x]=1;
  while(!Q.empty())
    { int k=Q.front();
       for(int i=0;i<a[k].size();i++)
       { int j=a[k][i].first,d=a[k][i].second;
         if(!viz[j])
         { viz[j]=1;
           if(k<j) dist[j]=dist[k]+d;
           else dist[j]=dist[k]-d;
           Q.push(j);
         }
       }
      Q.pop();
    }
}
int main()
{ f>>n>>m>>x>>y;
for(int k=1;k<=m;k++)
    {f>>i>>j>>d;
     a[i].push_back(make_pair(j,d));
     a[j].push_back(make_pair(i,d));
    }
bfs();
g<<dist[y];
    return 0;
}

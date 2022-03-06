#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
int n,m,x,y,s1,s2,k,d[30001];
bool ok[30001];
queue <int> q;
vector < pair <int,int> > a[30001];
int main()
{ in>>n>>m>>x>>y;
  for(int i=1;i<=m;i++)
  { in>>s1>>s2>>k;
    a[s1].push_back({s2,k});
    a[s2].push_back({s1,-k});
  }
  q.push(x);
  ok[x]=1;
  while(!q.empty())
  { k=q.front();
    for(int i=0;i<a[k].size();i++)
    { pair <int,int> v=a[k][i];
      if(!d[v.first])
      { d[v.first]=d[k]+v.second;
        q.push(v.first);
      }
    }
    q.pop();
  }
  out<<d[y];
  in.close();
  out.close();
  return 0;
}

#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const int maxim = 30007;
int n,m,vaz[maxim],x,y;
long long d[maxim];
vector<pair<int,long long> > drum[maxim];
queue<int> q;
void bfs()
{
vaz[x]=true;
q.push(x);
while(!q.empty())
{
x=q.front();
q.pop();
if(x==y)
{
break;
}
for(int i=0;i<drum[x].size();++i)
{
if(!vaz[drum[x][i].first])
{
vaz[drum[x][i].first]=true;
d[drum[x][i].first]=d[x]+drum[x][i].second;
q.push(drum[x][i].first);
}
else if(d[drum[x][i].first]>d[x]+drum[x][i].second)
{
vaz[drum[x][i].first]=true;
d[drum[x][i].first]=d[x]+drum[x][i].second;
q.push(drum[x][i].first);
}
}
}
}
int main()
{
int sat1,sat2,l;
ifstream fin ("sate.in");
ofstream fout ("sate.out");
fin>>n>>m>>x>>y;
if(x>y) swap(x,y);
for(int i=1;i<=m;++i)
{
fin>>sat1>>sat2>>l;
drum[sat1].push_back(make_pair(sat2, l));
l*= -1;
drum[sat2].push_back(make_pair(sat1, l));
}
bfs();
fout<<d[y];
}

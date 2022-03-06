#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct Op{int x;int y;int c;};

vector<Op> edge,sol;

bool mycmp(Op s,Op t)

{return s.c<t.c;}

const int lim=2e5+3;

int link[lim],dim[lim];

int tata(int x)

{int cpy=x,aux;

while(x!=link[x])x=link[x];

while(cpy!=link[cpy])aux=cpy,cpy=link[cpy],link[aux]=x;

return x;}

void unite(int x,int y)

{x=tata(x);y=tata(y);

if(dim[x]<dim[y])swap(x,y);

link[y]=x;dim[x]+=dim[y];}

int main()

{int n,m,x,y,c,s=0;

cin>>n>>m;

for(int i=0;i<m;++i)

cin>>x>>y>>c,edge.push_back({x,y,c});

sort(edge.begin(),edge.end(),mycmp);

for(int i=1;i<=n;++i)link[i]=i,dim[i]=1;

for(auto t:edge)if(tata(t.x)!=tata(t.y))

unite(t.x,t.y),sol.push_back(t),s+=t.c;

cout<<s<<'\n'<<sol.size()<<'\n';

for(auto t:sol)cout<<t.x<<' '<<t.y<<'\n';

return 0;}

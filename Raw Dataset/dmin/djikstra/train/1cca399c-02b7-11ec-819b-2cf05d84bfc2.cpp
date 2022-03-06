#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

FILE *fin,*fout;

vector < pair<short,double> > G[1505];

int n,k,apar[1505];

double d[1505];

priority_queue< pair<double,short>, vector<pair<double,short> >, greater<pair<double,short> > > HEAP;

bool use[1505];

void dijkstra(short nod)

{

short vec;

double cost;

for(int i=1;i<=n;i++)

d[i]=(1<<30);

d[nod]=0;

apar[1]=1;

HEAP.push(make_pair(0,nod));

while(!HEAP.empty())

{

nod=HEAP.top().second;

HEAP.pop();

if(use[nod])

continue;

use[nod]=1;

for(size_t i=0;i<G[nod].size();i++)

{

vec=G[nod][i].first;

cost=G[nod][i].second;

if(use[vec])

continue;

if(d[vec]>d[nod]+cost+0.000001)

{

d[vec]=d[nod]+cost;

apar[vec]=apar[nod];

HEAP.push(make_pair(d[vec],vec));

continue;

}

if(abs(d[vec]-d[nod]-cost)<=0.000001)

{

apar[vec]+=apar[nod];

apar[vec]%=104659;

}

}

}

}

void read()

{

fin=fopen("dmin.in","r");

int x,y,m;

double z;

fscanf(fin,"%d %d",&n,&m);

while(m--)

{

fscanf(fin,"%d %d %lf",&x,&y,&z);

z=log(z);

G[x].push_back(make_pair(y,z));

G[y].push_back(make_pair(x,z));

}

fclose(fin);

}

void print()

{

fout=fopen("dmin.out","w");

for(int i=2;i<=n;i++)

fprintf(fout,"%d ",apar[i]);

fclose(fout);

}

int main()

{

read();

dijkstra(1);

print();

return 0;

}

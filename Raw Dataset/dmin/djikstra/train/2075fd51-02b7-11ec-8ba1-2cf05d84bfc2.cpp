#include <fstream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int MOD = 104659;

const double INF = 160000000;

vector< pair<int,double > > G[1502];

int N , M , drumuri[1502];

double D[1502];



void djikstra()

{

 for(int i=1;i<=N;++i) D[i] = INF;

 D[1] = 0;

 drumuri[1] = 1;

 set<pair<double,int> > h;

 pair<double,int> v;

 h.insert(make_pair(0,1));

 while(!h.empty())

 {

  v = (*h.begin()) , h.erase(*h.begin());

  for(vector<pair<int,double > >::const_iterator w = G[v.second].begin();w!=G[v.second].end();++w)

   if(fabs(D[w->first] - v.first - w->second) < 1e-9)

    drumuri[w->first]= (drumuri[w->first] + drumuri[v.second])%MOD;

   else

  if(D[w->first] > v.first + w->second)

  {

   D[w->first] = v.first + w->second;

   drumuri[w->first] = drumuri[v.second];

   h.insert(make_pair(D[w->first],w->first));

  }

 }

}



void read_data()

{

 int x , y;

 double c;

 for(fin>>N>>M;M;M--)

 {

  fin>>x>>y>>c;

  G[x].push_back(make_pair(y,log(c)));

  G[y].push_back(make_pair(x,log(c)));

 }



}



int main()

{

 read_data();

 djikstra();

 for(int i=2;i<=N;++i)

  fout<<drumuri[i]<<" ";

 return 0;

}

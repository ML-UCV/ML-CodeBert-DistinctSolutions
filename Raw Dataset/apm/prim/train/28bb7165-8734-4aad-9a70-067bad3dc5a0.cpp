#include<fstream>
#include<vector>
#include<queue>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

vector<pair<int, pair<int,int> > > v[200020];

priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;

queue<pair<int,int> > q;

pair<int, pair<int,int> > elem;

int n, m, viz[200020], cost, nrm;

void citire ()

{

    fin>>n>>m;

    int i, x, y, co;

    for (i=1; i<=m; i++)

    {

        fin>>x>>y>>co;

        v[x].push_back(make_pair(co,make_pair(x, y)));

        v[y].push_back(make_pair(co,make_pair(y, x)));

    }

}

void prim ()

{

   cost=0; nrm=0;

   int i, j;

   for (i=0; i<v[1].size(); i++)

      pq.push(make_pair(v[1][i].first, make_pair(1, v[1][i].second.second)));

   viz[1]=1;

   i=1;

   while (i<n && !pq.empty())

   {

       while(!pq.empty() && viz[pq.top().second.second]==1)

        pq.pop();

       if (pq.empty())break;

       elem=pq.top();

       cost+=elem.first;

       nrm++;

       viz[elem.second.second]=1;

       int x=elem.second.second;

       for (j=0; j<v[x].size(); j++)

         pq.push(make_pair(v[x][j].first, make_pair(v[x][j].second.first, v[x][j].second.second)));

       q.push(make_pair(elem.second.first, elem.second.second));

   }

}

void afisare ()

{

    fout<<cost<<'\n'<<nrm<<'\n';

    while(!q.empty())

    {

        fout<<q.front().first<<' '<<q.front().second<<'\n';

        q.pop();

    }

}

int main ()

{

    citire();

    prim();

    afisare();

}

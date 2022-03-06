#include <fstream>
#include <queue>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");



vector <pair<int,int>> v[400001];

vector<pair<int,int>> vrez;

int used[200001],cost[200001],cor[200001];

priority_queue <pair<int,int>> pq;

int intro_apm(int nod){

  int i,l=v[nod].size();

  for(i=0;i<l;i++)

  {

    if(cost[v[nod][i].second]>-(v[nod][i].first))

    {

      pq.push({v[nod][i]});

      cost[v[nod][i].second]=-(v[nod][i].first);

      cor[v[nod][i].second]=nod;

    }

  }

}

int main()

{

    int n,m,i,a,b,c,costf=0,l,x;

    cin>>n>>m;

    for(i=1;i<=m;i++)

    {

      cin>>a>>b>>c;

      v[a].push_back({-c,b});

      v[b].push_back({-c,a});

    }

    for(i=2;i<=n;i++)

    {

      cost[i]=1e9;

      pq.push({-cost[i],i});

      x=pq.top().second;

    }

    intro_apm(1);

    used[1]=1;

    for(i=1;i<n;i++)

    {

      l=pq.size();

      while(used[pq.top().second]){

        pq.pop();

      }

      x=pq.top().second;

      pq.pop();

      used[x]=1;

      intro_apm(x);

      costf+=cost[x];

      vrez.push_back({x,cor[x]});

    }

    cout<<costf<<'\n'<<n-1<<'\n';

    for(i=0;i<n-1;i++)

      cout<<vrez[i].first<<" "<<vrez[i].second<<'\n';

    return 0;

}

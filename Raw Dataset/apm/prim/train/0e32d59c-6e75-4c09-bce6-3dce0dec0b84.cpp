#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M;
vector< pair<int,int> > V[200002];
auto compare = [](pair<int,int> a, pair<int,int> b) { return a.second > b.second; };

priority_queue < pair<int,int>, vector<pair<int,int> >, decltype(compare) > pq(compare);
int p[200002], d[200002];
bool visited[200002];
vector <pair <int, int> > ANS;
priority_queue <int> pq2;
int cost = 0;
int main()
{
 ifstream f1("apm.in");
 ofstream f2("apm.out");
 f1>>N>>M;
 int x,y,z;
 for (int i=0; i<M; i++)
 {
  f1>>x>>y>>z;
  V[x].push_back(make_pair(y,z));
  V[y].push_back(make_pair(x,z));
 }
 for (int i=1; i<=N; i++)
  d[i] = 1<<20;
 d[1] = 0;
 pq.push(make_pair(1,0));
 while (!pq.empty())
 {
  int nod = pq.top().first;

  if (visited[nod])
  {
   pq.pop();
   continue;
  }
  visited[nod] = 1;
  cost+= pq.top().second;

  pq.pop();
  if (nod != 1)
   ANS.push_back(make_pair(p[nod], nod));
  for (int i=0; i<V[nod].size(); i++)
  {
   if (visited[V[nod][i].first] == 0 && d[V[nod][i].first] > V[nod][i].second)
   {
     d[V[nod][i].first] = V[nod][i].second;
     p[V[nod][i].first] = nod;
     pq.push(make_pair(V[nod][i].first,d[V[nod][i].first]));

   }
  }
 }
 f2<<cost<<"\n";
 f2<<N-1<<"\n";
 for (int i=0; i<ANS.size(); i++)
  f2<<ANS[i].first<<" "<<ANS[i].second<<"\n";
 return 0;
}

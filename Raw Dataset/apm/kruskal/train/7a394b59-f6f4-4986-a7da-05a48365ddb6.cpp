#include  <fstream>
#include  <iostream>
#include  <vector>
#include  <algorithm>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");

const int Nmax = 2e5 + 5;
int n, m, cnt;
vector<pair<int, int>>G[Nmax];
vector<pair<int, int>>G_min;
int T[Nmax];
struct muchie{
  int x, y, c;
}V[2*Nmax];
struct cmp{
  bool operator()(muchie x, muchie y)
  {
    return x.c < y.c;
  }
};

void read()
{
  in>>n>>m;
  for(int i = 1; i <= m; i++)
  {
    in>>V[i].x>>V[i].y>>V[i].c;
    G[V[i].x].push_back({V[i].y, V[i].c});
    G[V[i].y].push_back({V[i].x, V[i].c});
  }
}

void unire(int x, int y)
{
  T[x] = y;

}

int radacina(int nod)
{
  while(T[nod] != nod)
    nod = T[nod];
  return nod;
}

void compresie(int x, int rad)
{
  int y = T[x];
  while(T[x] != rad)
  {
    unire(x, rad);
    x = y;
  }
}

void solve()
{
    int cost_min = 0;
    sort(V + 1, V + m + 1, cmp());
    for(int i = 1; i <= n; i++)
      T[i] = i;
    for(int i = 1; i <= m; i++)
    {
      int x = V[i].x,
          y = V[i].y,
          c = V[i].c;
      int X = radacina(x);
      int Y = radacina(y);
      compresie(x, X);
      compresie(y, Y);
      if(X != Y)
        unire(X, Y), cost_min += c, cnt++, G_min.push_back({x,y});
    }
  out<<cost_min<<'\n'<<cnt<<'\n';
    for(auto it : G_min)
      out<<it.first<<' '<<it.second<<'\n';
}

int main()
{
  read();
  solve();
}

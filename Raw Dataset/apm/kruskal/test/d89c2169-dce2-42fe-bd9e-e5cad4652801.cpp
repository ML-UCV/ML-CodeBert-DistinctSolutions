#include <stdio.h>
#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const int Nmax = 2e5+7;

int TT[Nmax];
struct edge {
  int a,b,c;
} e[Nmax];

inline bool cmp(const edge &u, const edge &v) { return u.c < v.c; }

ifstream fin ("apm.in");
ofstream fout ("apm.out");

int root(int a) {
  if (a == TT[a]) { return a; }
  return TT[a] = root(TT[a]);
}

int main(void) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  fin >> n >> m;
  for(int i = 0; i < (int)(m); i++) {
    fin >> e[i].a >> e[i].b >> e[i].c;
  }
  sort(e, e+m, cmp);
  for(int i = 0; i < (int)(n+1); i++) { TT[i] = i;}

  int cost = 0;
  vi res;
  for(int i = 0; i < (int)(m); i++) {
    if (root(e[i].a) != root(e[i].b)) {
      TT[root(e[i].b)] = root(e[i].a);
      cost += e[i].c;
      res.push_back(i);
    }
  }
  fout << cost << '\n';
  fout << res.size() << '\n';
  for(auto i: res) {
    fout << e[i].a << " " << e[i].b << '\n';
  }

  return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
const int nmax = 2e5 + 5;



int tata[nmax], sz[nmax];

std::vector<std::pair<int,int> >ans_pairs;



int extreme(int node) {

 int t = node;

 while (tata[t] != t) t = tata[t];

 tata[node] = t;

 while (tata[node] != node) node = tata[node], tata[node] = t;

 return t;

}



void connect(int u, int v) {

 int su = extreme(u), sv = extreme(v);

 if (sz[su] < sz[sv]) std::swap(su, sv);

 tata[sv] = su, sz[su] += sz[sv];

}



bool is_connected(int u, int v) {

 return extreme(u) == extreme(v);

}



int main() {

 std::ifstream fin("apm.in");

 std::ofstream fout("apm.out");

 int n, m, ans = 0;

 fin >> n >> m;

 std::vector<std::pair<int, std::pair<int,int> > >l(m);

 for (int i = 0; i < m; i++) fin >> l[i].second.first >> l[i].second.second >> l[i].first;

 for (int i = 1; i <= n; i++) sz[i] = 1, tata[i] = i;

 std::sort(l.begin(), l.end());

 for(auto a:l)

  if (!is_connected(a.second.first, a.second.second)) {

   ans += a.first;

   connect(a.second.first, a.second.second);

   ans_pairs.push_back(a.second);

  }

 fout << ans << "\n";

 fout << ans_pairs.size() << "\n";

 for (auto a : ans_pairs) fout << a.first << " " << a.second << "\n";

}

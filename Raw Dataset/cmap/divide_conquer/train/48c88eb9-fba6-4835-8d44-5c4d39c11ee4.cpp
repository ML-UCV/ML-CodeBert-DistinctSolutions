#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

const long long INF = 4e18;

int n;
vector<pair<long long, long long> > v, w;
vector<pair<long long, long long> > m, aux;

long long get_dist(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long dei(int lt, int rt) {
  if (lt == rt) {
    return INF;
  } else if (rt - lt == 1) {
    return get_dist(v[lt], v[rt]);
  } else if (rt - lt == 2) {
    return min(get_dist(v[lt], v[rt]), min(get_dist(v[lt], v[lt + 1]), get_dist(v[lt + 1], v[rt])));
  }

  int mid = (lt + rt) >> 1;
  long long sol = min(dei(lt, mid), dei(mid, rt));

  m.clear();
  m.resize(rt + 1 - lt + 1);
  aux.clear();
  merge(w.begin() + lt, w.begin() + mid, w.begin() + mid, w.begin() + rt + 1, m.begin());

  for (vector<pair<long long, long long> >::iterator it = m.begin(); it != m.end(); ++it) {
    if (abs(it->second - v[mid].first) <= sol) {
      aux.push_back(make_pair(it->second, it->first));
    }
  }

  for (int i = 0; i < aux.size(); ++i) {
    for (int j = i + 1; j < aux.size() && j - i < 8; ++j) {
      sol = min(sol, get_dist(aux[i], aux[j]));
    }
  }

  return sol;
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    long long x, y;
    fin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  for (int i = 1; i <= n; ++i) {
    w.push_back(make_pair(v[i - 1].second, v[i - 1].first));
  }

  sort(v.begin(), v.end());
  w.push_back(make_pair(INF, INF));
  sort(w.begin(), w.end());

  long long sol = dei(0, v.size() - 1);
  fout << fixed << setprecision(6) << sqrt((double)sol);

  fout << "\n";
  return 0;
}

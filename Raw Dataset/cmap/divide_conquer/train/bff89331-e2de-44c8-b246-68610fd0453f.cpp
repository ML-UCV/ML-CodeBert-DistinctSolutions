#include <bits/stdc++.h>


using namespace std;



const int nmax = 100005;



const long long inf = numeric_limits<long long>::max();



vector<pair<int, int>> x;

vector<pair<int, int>> y;

int n;



long long dist(pair<int, int>& a, pair<int, int>& b) {

  return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);

}



vector<pair<int, int> > v;



long long calc(int l, int r, vector<pair<int, int>>& x, vector<pair<int, int>>& y) {

  if (l >= r - 1) {

    return inf;

  }

  if (l == r - 2) {

    if (y[l].first > y[l + 1].first) {

      swap(y[l], y[l + 1]);

    }

    return dist(y[l], y[l + 1]);

  }



  int mid = (l + r) / 2;

  long long best = min(calc(l, mid, x, y), calc(mid, r, x, y));

  merge(y.begin() + l, y.begin() + mid, y.begin() + mid, y.begin() + r, v.begin());

  copy(v.begin(), v.begin() + (r - l), y.begin() + l);



  int cnt = 0;

  for (int i = l; i < r; i++) {

    if (abs(y[i].second - x[mid].first) <= best) {

      v[cnt++] = y[i];

    }

  }



  for (int i = 0; i < cnt; i++) {

    for (int j = i + 1; j < cnt && j - i < 8; j++) {

      best = min(best, dist(v[i], v[j]));

    }

  }



  return best;

}



int main() {

  freopen("cmap.in", "r", stdin);

  freopen("cmap.out", "w", stdout);

  scanf("%d", &n);

  x.resize(n);

  y.resize(n);

  v.resize(n);

  for (int i = 0; i < n; i++) {

    scanf("%d %d", &x[i].first, &x[i].second);

  }



  sort(x.begin(), x.end());

  for (int i = 0; i < n; i++) {

    y[i] = make_pair(x[i].second, x[i].first);

  }



  printf("%.6lf\n", sqrt(calc(0, n, x, y)));



  return 0;

}

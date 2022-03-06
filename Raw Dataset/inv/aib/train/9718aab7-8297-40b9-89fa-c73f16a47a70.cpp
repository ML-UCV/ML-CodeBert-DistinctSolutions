#include <bits/stdc++.h>



using namespace std;

struct Fenwick {
  int n;
  vector<int> t;
  Fenwick(int n_) : n(n_), t(n + 1) {}
  void Update(int pos, int val) {
    for (++pos; pos <= n; pos += pos & -pos) t[pos] += val;
  }
  int Query(int pos) {
    int ans = 0;
    for (++pos; pos; pos -= pos & -pos) ans += t[pos];
    return ans;
  }
};

int main() {
  ifstream cin("inv.in");
  ofstream cout("inv.out");

  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  auto all = v;
  all.emplace_back(-(int)1e9);
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (int i = 0; i < n; ++i) {
    v[i] = lower_bound(all.begin(), all.end(), v[i]) - all.begin();
  }

  Fenwick fw(n);
  int64_t ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += fw.Query(v[i] - 1);
    fw.Update(v[i], 1);
  }
  cout << ans % 9917 << endl;
}

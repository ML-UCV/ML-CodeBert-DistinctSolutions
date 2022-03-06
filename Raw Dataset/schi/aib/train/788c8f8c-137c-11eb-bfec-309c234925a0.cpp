#include <bits/stdc++.h>


using namespace std;

struct Fenwick {
  int n;
  vector<int> tree;
  Fenwick(int n_) : n(n_), tree(n + 1) {}
  inline int lsb(int x) {
    return -x & x;
  }
  void Update(int pos, int val) {
    for (++pos; pos <= n; pos += lsb(pos))
      tree[pos] += val;
  }
  int Query(int pos) {
    int ans = 0;
    for (++pos; pos > 0; pos -= lsb(pos))
      ans += tree[pos];
    return ans;
  }
};

int main() {
  ifstream cin("schi.in");
  ofstream cout("schi.out");

  int n; cin >> n;
  vector<int> v(n);
  for (int &x : v) {
    cin >> x; --x;
  }
  Fenwick tree(n);
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    int pos = -1, lo = 0, hi = n - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (mid - tree.Query(mid) >= v[i]) {
        pos = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    assert(pos != -1 && ans[pos] == 0);
    ans[pos] = i + 1;
    tree.Update(pos, 1);
  }
  for (int x : ans) {
    cout << x << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

class FenTree {
  private:
    int n;
    vector<int> bit;

  public:
    FenTree(int n) :
        n(n), bit(n + 1) { }

    void update(int pos, int val) {
        for (int i = pos; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int pos) {
        int sum = 0;
        for (int i = pos; i >= 1; i -= i & -i)
            sum += bit[i];
        return sum;
    }
};

int main() {
    int n; fin >> n;
    vector<pair<int, int>> val(n);

    for (int i = 0; i < n; i++) {
        fin >> val[i].first;
        val[i].second = i;
    }
    sort(val.begin(), val.end());

    int cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (!i || val[i - 1].first != val[i].first)
            cnt++;
        v[val[i].second] = cnt;
    }

    int sol = 0;
    const int MOD = 9917;

    FenTree bit(cnt);
    for (int i = n - 1; i >= 0; i--) {
        sol = (sol + bit.query(v[i] - 1)) % MOD;
        bit.update(v[i], +1);
    }
    fout << sol << '\n';

    fout.close();
    return 0;
}

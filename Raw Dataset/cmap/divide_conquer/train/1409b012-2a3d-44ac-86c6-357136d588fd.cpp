#include <bits/stdc++.h>
using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



typedef long long ll;



const ll INF = 4e18;

const int MAX_N = 1e5 + 5;



int n;



pair <long long, long long> v[MAX_N];



ll sq(ll val) {

  return 1LL * val * val;

}



ll dist(pair <long long, long long> a, pair <long long, long long> b) {

  return (1LL * sq(a.first - b.first) + sq(a.second - b.second));

}



ll dei(int lo, int ri) {

  int mid;

  ll ans;

  vector <pair <long long, long long> > arr;

  ans = INF;

  if (ri - lo + 1 <= 3) {

    for (int i = lo; i <= ri; ++i) {

      arr.push_back(v[i]);

    }

    for (int i = 0; i < arr.size(); ++i) {

      for (int j = i + 1; j < arr.size(); ++j) {

        ans = min(ans, dist(arr[i], arr[j]));

      }

    }

    return ans;

  }

  mid = (lo + ri) / 2;

  ans = min(dei(lo, mid), dei(mid + 1, ri));

  for (int i = lo; i <= ri; ++i) {

    if (abs(v[i].first - v[mid].first) <= ans) {

      arr.push_back({v[i].second, v[i].first});

    }

  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); ++i) {

    for (int j = i + 1; j < arr.size() && j - i < 10; ++j) {

      ans = min(ans, dist(arr[i], arr[j]));

    }

  }

  return ans;

}



int main() {

  fin >> n;

  for (int i = 1; i <= n; ++i) {

    fin >> v[i].first >> v[i].second;

  }

  sort(v + 1, v + n + 1);

  fout << fixed << setprecision(6) << 1.0 * sqrt(1.0 * dei(1, n));

  return 0;

}

#include <bits/stdc++.h>






const int MAX_N = 100005;

const long long INF = 2e18;



int n;



std::vector <std::pair <long long, long long>> arr;



long long square(long long value) {

  return 1LL * value * value;

}



long long distance(std::pair <long long, long long> a,

                   std::pair <long long, long long> b) {

  return (square(a.first - b.first) + square(a.second - b.second));

}



long long solve(long long lo, long long ri) {

  long long ans = INF, mid = (lo + ri) >> 1;

  std::vector <std::pair <long long, long long>> points;

  if (ri - lo + 1 <= 3) {

    for (int i = lo; i <= ri; ++i) {

      points.push_back(arr[i]);

    }

    for (int i = 0; i < points.size(); ++i) {

      for (int j = 1 + i; j < points.size(); ++j) {

        ans = std::min(ans, distance(points[i], points[j]));

      }

    }

    return ans;

  }

  ans = std::min(solve(lo, mid), solve(mid + 1, ri));

  for (int i = lo; i <= ri; ++i) {

    if (abs(arr[i].first - arr[mid].first) <= ans) {

      points.push_back(std::make_pair(arr[i].second, arr[i].first));

    }

  }

  std::sort(points.begin(), points.end());

  for (int i = 0; i < points.size(); ++i) {

    for (int j = 1 + i; j < points.size() && j - i < 8; ++j) {

      ans = std::min(ans, distance(points[i], points[j]));

    }

  }

  return ans;

}



int main() {

  long long x, y;

  freopen("cmap.in", "r", stdin);

  freopen("cmap.out", "w", stdout);

  std::cin >> n;

  for (int i = 0; i < n; ++i) {

    scanf("%lld %lld", &x, &y);

    arr.push_back(std::make_pair(x, y));

  }

  std::sort(arr.begin(), arr.end());

  std::cout << std::fixed << std::setprecision(6) << sqrt(1.0 * solve(0, n - 1));

  return 0;

}

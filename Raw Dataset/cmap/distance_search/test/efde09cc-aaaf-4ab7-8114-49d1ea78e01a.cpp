#include <bits/stdc++.h>
using namespace std;



typedef pair <int, int> pii;

typedef vector <int> vi;

typedef long long ll;

typedef unsigned long long ull;



template <class T> void uin (T &a, T b) {a = min (a, b);}



struct Point {

  int x, y;

  bool operator < (const Point &other) const {

    return (y == other.y) ? (x < other.x) : (y < other.y);

  }

};



const int NMAX = 1e5 + 5;



Point points[NMAX];



int main() {

  ios::sync_with_stdio(0);

  cin.tie(0);
  freopen ("cmap.in", "r", stdin);

  freopen ("cmap.out", "w", stdout);



  int n;

  scanf ("%d\n", &n);

  for (int i = 1; i <= n; ++i) {

    scanf ("%d %d\n", &points[i].x, &points[i].y);

  }



  sort (points + 1, points + n + 1, [&] (const Point &a, const Point &b) {

    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);

  });



  set <Point> s;

  int l = 1, r = 0;

  ll ans = 1e18;

  while (++r <= n) {

    while (points[r].x - points[l].x >= ans) {

      s.erase (points[l++]);

    }



    int dist = ceil (sqrt (ans));

    auto lo = s.lower_bound ({points[r].x, points[r].y - dist});

    auto hi = s.lower_bound ({points[r].x, points[r].y + dist});



    for (auto it = lo; it != hi; ++it) {

      uin (ans, 1LL * (points[r].x - it->x) * (points[r].x - it->x) +

                1LL * (points[r].y - it->y) * (points[r].y - it->y));

    }

    s.insert (points[r]);

  }



  printf ("%.6f\n", sqrt (ans));



  fclose (stdin);

  fclose (stdout);
  return 0;

}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sqr(ll x) {

 return x * x;

}

struct point {

 int x, y;

 ll sqrdist(const point &that) {

  return sqr(x - that.x) + sqr(y - that.y);

 }

};

const ll INF = 1e16;

vector<point>p;

int n;

bool xcmp(const point &a, const point &b) {

 return a.x < b.x;

}

bool ycmp(const point &a, const point &b) {

 return a.y < b.y;

}

ll closest_pair(int st, int dr) {

 ll res = INF;

 if (dr - st + 1 <= 3) {

  for (int i = st; i <= dr; ++i) {

   for (int j = i + 1; j <= dr; ++j) {

    res = min(res, p[i].sqrdist(p[j]));

   }

  }

  return res;

 }

 int mid = (st + dr) / 2;

 res = min(closest_pair(st, mid), closest_pair(mid + 1, dr));

 vector<point>useful;

 for (int i = st; i <= dr; ++i) {

  ll horizontal = sqr(abs(p[mid].x - p[i].x));

  if (horizontal < res) {

   useful.push_back(p[i]);

  }

 }

 sort(useful.begin(), useful.end(), ycmp);

 for (int i = 0; i < useful.size(); ++i) {

  auto a = useful[i];

  for (int j = i + 1; j < useful.size() && j - i + 1 <= 8; ++j) {

   auto b = useful[j];

   res = min(res, a.sqrdist(b));

  }

 }

 return res;

}



int main() {

 freopen("cmap.in", "r", stdin);

 freopen("cmap.out", "w", stdout);



 cin >> n;

 p = vector<point>(n);

 for (int i = 0; i < n; ++i)

  cin >> p[i].x >> p[i].y;

 sort(p.begin(), p.end(), xcmp);

 long double answer = sqrt((long double)closest_pair(0, n - 1));

 cout << fixed << setprecision(7) << answer;

 return 0;

}

#include <bits/stdc++.h>




using namespace std;

typedef long long ll;
typedef pair< int , int > PII;

int n, m, cnt;
PII a[100100];

double dist(PII a, PII b) {
 return sqrt(1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second));
}

double divide(int st, int dr) {
 if (dr - st <= 2) {
  double d = 1e18;
  for (int i = st; i < dr; i++){
   for (int j = i + 1; j <= dr; j++){
    d = min(d, dist(a[i], a[j]));
   }
  }
  return d;
 }

 int mid = (st + dr) >> 1;
 double d = min(divide(st, mid), divide(mid + 1, dr));

 vector < PII > V;
 for (int i = st; i <= dr; i++) {
  if (abs(a[i].first - a[mid].first) < d) V.push_back(a[i]);
 }

 sort(V.begin(), V.end(), [&](PII a, PII b){ return a.second > b.second; });

 for (int i = 0; i < V.size(); i++)
  for (int j = i + 1; j < V.size() && j - i <= 7; j++)
   d = min(d, dist(V[i], V[j]));

 return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

 ifstream cin("cmap.in");
 ofstream cout("cmap.out");

 cin >> n;
 for (int i = 1; i <= n; i++) {
  cin >> a[i].first >> a[i].second;
 }

 sort(a + 1, a + n + 1);
 cout << setprecision(6) << fixed << divide(1, n);

 return 0;
}

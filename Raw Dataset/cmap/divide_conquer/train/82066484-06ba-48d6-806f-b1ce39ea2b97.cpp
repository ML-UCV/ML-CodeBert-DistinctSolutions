#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>


using namespace std;

typedef long long ll;

ifstream f("cmap.in");
ofstream g("cmap.out");

int n;
pair<int, int> V[100010];

ll dist(pair <int, int> a, pair <int, int> b){
 return (ll)(1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second));
}

bool cmp(pair <int, int> a, pair <int, int> b){
 return (a.second < b.second);
}

ll solve(int l, int r){
 if (r - l == 1)
  return dist(V[l], V[l + 1]);
 else if (r - l == 2)
  return min(dist(V[l], V[l + 1]), min(dist(V[l], V[l + 2]), dist(V[l + 1], V[l + 2])));

 int mid = ((l + r) >> 1);
 ll res = min(solve(l, mid), solve(mid + 1, r));
 vector <pair<int, int> > W;
 int Dist = (int)(sqrt(res) + 1);

 for (int i = l; i <= r; ++i)
  if (abs(V[mid].first - V[i].first) <= Dist)
   W.push_back(V[i]);

 sort(W.begin(), W.end(), cmp);

 for (int i = 0; i < W.size(); ++i)
  for (int j = i + 1; j < i + 8 && j < W.size(); ++j)
   res = min(res, dist(W[i], W[j]));

 return res;
}

int main(){
 f >> n;
 for (int i = 1; i <= n; ++i){
  f >> V[i].first >> V[i].second;
 }

 sort(V + 1, V + n + 1);

 g << fixed << setprecision(6) << double(sqrt(solve(1, n)));
 return 0;
}

#include<bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll INF = 4e18;


vector <pll> x,y,v;

ll dist(pll a, pll b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}


ll solve(int st, int dr) {
  if (st >= dr - 1) return INF;
  if (dr - st == 2) {
    if (y[st] > y[st + 1]) {
      swap(y[st], y[st + 1]);
    }
    return dist(y[st], y[st + 1]);
  }
  int mij = (st + dr) / 2;
  long long ret = min(solve(st, mij), solve(mij, dr));


  merge(y.begin() + st, y.begin() + mij, y.begin() + mij, y.begin() + dr, v.begin());
  copy(v.begin(), v.begin() + (dr - st), y.begin() + st);


  int nr = 0;
  for (int i=st; i<dr; ++i) {
    if (abs(y[i].second - x[mij].first) <= ret) {
      v[nr++] = y[i];
    }
  }


  for (int i=0; i<nr; ++i) {
    for (int j=i+1; j<nr && j<=i+7; ++j) {
      ret = min(ret, dist(v[i], v[j]));
    }
  }
  return ret;
}

double closest_points(vector<pll> &a) {
  int N = a.size();
  x = a;
  v.resize(N);
  sort(x.begin(), x.end());
  for(int i=0;i<N;++i) {
    y.push_back(make_pair(x[i].second, x[i].first));
  }
  return sqrt(solve(0,N));
}

int main() {
    freopen("cmap.in","r",stdin);
    freopen("cmap.out","w",stdout);
    int N;
    vector<pll> a;
    scanf("%d",&N);
    a.resize(N);
    for (int i = 0; i < N; ++ i) {
      scanf("%lld%lld",&a[i].first,&a[i].second);
    }
    printf("%.10lf\n",closest_points(a));
    return 0;
}

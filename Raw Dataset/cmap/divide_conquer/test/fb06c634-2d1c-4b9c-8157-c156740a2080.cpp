#include<bits/stdc++.h>
using namespace std;





typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector<pair<pll,int> > v,x,y;
ll INF = 4e18;
int N;

ll dist(pll a, pll b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

pair<ll,pii> solve(int st, int dr) {
  if (st >= dr - 1) return make_pair(INF,make_pair(0,0));
  if (dr - st == 2) {
    if (y[st] > y[st + 1]) {
      swap(y[st], y[st + 1]);
    }
    return make_pair(dist(x[st].first, x[st + 1].first),make_pair(x[st].second, x[st+1].second));
  }

  int mij = (st + dr) / 2;
  pair<ll,pii > ret = min(solve(st,mij),solve(mij,dr));

  merge(y.begin() + st, y.begin() + mij, y.begin() + mij, y.begin() + dr, v.begin());
  copy(v.begin(), v.begin() + (dr - st), y.begin() + st);

  int nr = 0;
  for (int i=st; i<dr; ++i) {
    if (abs(y[i].first.second - x[mij].first.first) < ret.first) {
      v[nr++] = y[i];
    }
  }
  for(int i=0;i<nr;++i) {
    for (int j=i+1; j<nr && j<=i+7; ++j) {
      ll d = dist(v[i].first,v[j].first);
      if(d < ret.first) {
        ret = make_pair(d,make_pair(v[i].second,v[j].second));
      }
    }
  }
  return ret;
}

double closest_points() {
  int N = x.size();
  sort(x.begin(), x.end());
  v.resize(N);
  for(ll i=0;i<N;++i) {
    y.push_back( make_pair(make_pair(x[i].first.second, x[i].first.first), x[i].second));
  }
  return sqrt(solve(0,N).first);
}

int main() {
  freopen("cmap.in","r",stdin);
  freopen("cmap.out","w",stdout);
  scanf("%d",&N);
  x.resize(N);
  for(int i=0;i<N;++i) {
    scanf("%lld%lld",&x[i].first.first,&x[i].first.second);
  }
  printf("%.10lf\n",closest_points());
}

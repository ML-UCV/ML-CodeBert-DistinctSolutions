#include <bits/stdc++.h>




using namespace std;



void solve() {

 int n;

 cin >> n;



 vector< int > v(n);



 for(int i = 0; i < n; ++i) cin >> v[i];





 vector< int > actual = v;

 sort(actual.begin(), actual.end());



 actual.erase(unique(actual.begin(), actual.end()), actual.end());



 for(auto &x : v) {

  int l = 0, r = actual.size() - 1;

  int idx = 0;

  while(l <= r) {

   int m = l + r >> 1;

   if(actual[m] == x) {

    idx = m;

    break;

   }

   if(actual[m] < x) {

    l = m + 1;

   } else r = m - 1;

  }





  x = idx + 1;

 }



 vector< int > aib(actual.size() + 1);



 auto update = [&](int p) {

  for(; p < aib.size(); p += p&-p) ++aib[p];

 };



 auto query = [&](int p) {

  int ret = 0;

  for(;p;p-=p&-p) ret += aib[p];

  return ret;

 };



 long long ans = 0;



 for(int i = 0; i < n; ++i) {

  ans += i - query(v[i]);

  update(v[i]);

 }



 cout << ans % 9917<< '\n';

}

int main() {

 freopen("inv.in", "r", stdin);

 freopen("inv.out", "w", stdout);



 ios::sync_with_stdio(false);

 cin.tie(0);

 cout.tie(0);





 solve();

}

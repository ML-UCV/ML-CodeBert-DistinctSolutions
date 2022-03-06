#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
ll ceildiv(ll one, ll two) {
 if (one % two == 0) {return one / two;}
 else {return one / two + 1;}
} ll power(ll n, ll pow, ll m) {
 if (pow == 0) return 1;
 if (pow % 2 == 0) {
  ll x = power(n, pow / 2, m);
  return (x * x) % m;
 }
 else return (power(n, pow - 1, m) * n) % m;
} ll gcd(ll a, ll b) {
 if (!b)return a;
 return gcd(b, a % b);
} ll factorial(ll n, ll mod) {
 if (n > 1)
  return (n * factorial(n - 1, mod)) % mod;
 else
  return 1;
} ll lcm(ll a, ll b) {
 return (a * b) / gcd(a, b);
} vector<ll> read(ll n) {vector<ll> a; for (ll i = 0; i < n; i++) { ll x; cin >> x; a.push_back(x);} return a;}vector<vector<ll>> adj;void init(ll n) {for (ll i = 0; i <= n; i++) { vector<ll> a; adj.push_back(a);}}


int32_t main() {
 ios_base::sync_with_stdio(false);cin.tie(0);;
 freopen("strmatch.in", "r", stdin);
 freopen("strmatch.out", "w", stdout);
 string s, t;
 cin >> s >> t;
 if(s.size() > t.size())
 {
  cout << 0 << '\n';
  return 0;
 }
 t = (s+'#'+t);
 ll pi[t.size()+1];
 pi[0] = 0;
 for (ll i = 1; i < t.size(); i++)
 {
  ll j = pi[i-1];
  while (j > 0 && t[i] != t[j])
  {
   j = pi[j-1];
  }
  if(t[i] == t[j])
  {
   j++;
  }
  pi[i] = j;
 }
 vector<ll> a;
 ll size = 0;
 for(ll i = s.size(); i < t.size(); i++)
 {
  if(pi[i] == s.size() && a.size() <= 1000)
  {
   a.push_back(i);
  }
  if(pi[i] == s.size())
  {
   size++;
  }
 }
 ll k = a.size();
 ll x = min(k, 1000LL);
 cout << size << '\n';
 for(ll i = 0; i < x; i++)
 {
  cout << a[i]-2*s.size() << " ";
 }
}

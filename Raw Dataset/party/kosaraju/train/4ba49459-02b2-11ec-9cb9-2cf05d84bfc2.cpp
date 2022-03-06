#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

ifstream iredirect;
ofstream oredirect;
const string file = "party";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[] = {0, 0, 1, -1, 1, -1, 1, -1}, inf = 2147483647, nmax = 10015, offset = 10005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r)
{
 return uniform_int_distribution<int>(l, r)(rng);
}

void prepare_IO()
{

  iredirect.open(file+".in");
  cin.rdbuf(iredirect.rdbuf());
  oredirect.open(file+".out");
  cout.rdbuf(oredirect.rdbuf());






}

int n, m, ordine[nmax*2], p, p2, belong[nmax*2];
bool val[nmax], vis[nmax*2], ok[nmax*2];
unordered_set<int> v[nmax*2], vt[nmax*2], has[nmax*2];

void dfs(int x)
{
    vis[x+offset] = 1;
    for (auto y : v[x+offset])
        if(!vis[y+offset])
            dfs(y);
    ordine[++p] = x;
}

void dfst(int x)
{
    vis[x+offset] = 0;
    belong[x+offset] = p2;
    has[p2].insert(x);
    for (auto y : vt[x+offset])
        if(vis[y+offset])
            dfst(y);
}

void solve()
{
 cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, t;
        cin >> x >> y >> t;
        switch(t) {
         case 1: {
          y *= -1;
          break;
         }
         case 2: {
          x *= -1;
          break;
         }
         case 3: {
          x *= -1;
          y *= -1;
          break;
         }
        }
        v[-x+offset].insert(y);
        v[-y+offset].insert(x);
        vt[y+offset].insert(-x);
        vt[x+offset].insert(-y);
    }
    for (int i = -n; i <= n; ++i)
        if(i != 0 && !vis[i+offset])
            dfs(i);
    vector<int> r;
    for (int i = p; i >= 1; --i)
        if(vis[ordine[i]+offset]){
            ++p2;
            r.push_back(ordine[i]);
            dfst(ordine[i]);
        }
    for (auto x : r)
        if(!ok[belong[x+offset]]){
            int now = belong[x+offset], now2 = belong[-x+offset];
            ok[now] = ok[now2] = 1;
            for (auto y : has[now])
                if(y > 0)
                    val[y] |= 0;
                else val[-y] |= 1;
            for (auto y : has[now2])
                if(y > 0)
                    val[y] |= 1;
                else val[-y] |= 0;
        }
    vector<int> sol;
    for (int i = 1; i <= n; ++i)
     if (val[i])
      sol.push_back(i);
    cout << sol.size() << "\n";
    for (auto x : sol)
     cout << x << " ";
    cout << "\n";
}

signed main()
{
 prepare_IO();
 int number_of_tests = 1;

 for (int testcase = 1; testcase <= number_of_tests; ++testcase)
  solve();
 return 0;
}

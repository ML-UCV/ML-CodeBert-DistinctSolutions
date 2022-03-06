#include <bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



typedef long long ll;

typedef long double ld;

typedef double db;

typedef string str;



typedef pair<int, int> pi;

typedef pair<ll,ll> pl;

typedef pair<ld,ld> pd;



typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<ld> vd;

typedef vector<str> vs;

typedef vector<pi> vpi;

typedef vector<pl> vpl;
const int MOD = 1e9+7;

const int NMAX = 2e5+5;

const ll INF = 1e18;

const ld PI = 4*atan((ld)1);



namespace input {

 template<class T> void re(complex<T>& x);

 template<class T1, class T2> void re(pair<T1,T2>& p);

 template<class T> void re(vector<T>& a);

 template<class T, size_t SZ> void re(array<T,SZ>& a);



 template<class T> void re(T& x) { cin >> x; }

 template<class T, class... Ts> void re(T& t, Ts&... ts) {

  re(t); re(ts...);

 }



 template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }

 template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.first,p.second); }

 template<class T> void re(vector<T>& a) { for (int i = (0); i < ((int)a.size()); ++i) re(a[i]); }

 template<class T, size_t SZ> void re(array<T,SZ>& a) { for (int i = (0); i < (SZ); ++i) re(a[i]); }

}



using namespace input;



namespace output {

 void pr(int x) { cout << x; }

 void pr(long x) { cout << x; }

 void pr(ll x) { cout << x; }

 void pr(unsigned x) { cout << x; }

 void pr(unsigned long x) { cout << x; }

 void pr(unsigned long long x) { cout << x; }

 void pr(float x) { cout << x; }

 void pr(double x) { cout << x; }

 void pr(ld x) { cout << x; }

 void pr(char x) { cout << x; }

 void pr(const char* x) { cout << x; }

 void pr(const string& x) { cout << x; }

 void pr(bool x) { pr(x ? "true" : "false"); }

 template<class T> void pr(const complex<T>& x) { cout << x; }



 template<class T1, class T2> void pr(const pair<T1,T2>& x);

 template<class T> void pr(const T& x);



 template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {

  pr(t); pr(ts...);

 }

 template<class T1, class T2> void pr(const pair<T1,T2>& x) {

  pr("{",x.first,", ",x.second,"}");

 }

 template<class T> void pr(const T& x) {

  pr("{");

  bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;

  pr("}");

 }



 void ps() { pr("\n"); }

 template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {

  pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);

 }



 void pc() { pr("]\n"); }

 template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {

  pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);

 }



}

using namespace output;



int n,m;

struct tip{

int nod,cost,tata;

};

bool operator<(tip x,tip y)

{

    return x.cost>y.cost;

}

priority_queue<tip>coada;

vector<tip>G[NMAX];

vector<pi>mu;

bool uz[NMAX];

int ans;

void solve() {

fin>>n>>m;

for (int i = (1); i < (m+1); ++i)

  {int x,y,c;

   fin>>x>>y>>c;

   G[x].push_back({y,c,x});

   G[y].push_back({x,c,y});

  }

for (int i = (0); i < (G[1].size()); ++i)

  coada.push({G[1][i].nod,G[1][i].cost,1});

 uz[1]=1;

 while(!coada.empty())

      {tip x;

       x=coada.top();

       coada.pop();

       if(!uz[x.nod])

         {ans+=x.cost;

          uz[x.nod]=1;

          mu.push_back({x.tata,x.nod});

          for (int i = (0); i < (G[x.nod].size()); ++i)

            coada.push({G[x.nod][i].nod,G[x.nod][i].cost,x.nod});

         }

      }

fout<<ans<<'\n';

fout<<n-1<<'\n';

for (int i = (0); i < (mu.size()); ++i)

   fout<<mu[i].first<<' '<<mu[i].second<<'\n';

}



int main() {

 ios_base::sync_with_stdio(false); cin.tie(0);

 int t=1;



   while(t--)

         solve();

    return 0;



}

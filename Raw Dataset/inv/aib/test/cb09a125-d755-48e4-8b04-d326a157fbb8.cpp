#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int n,i,f[100010],w[100010],cnt,sol;

pair<int,int> v[100010];

void update(int x) {

 for (;x<=n;x+=(x&-x))

  f[x]++;

}

int query(int x) {

 int val=0;

 for (;x;x-=(x&-x))

  val+=f[x];

 return val;

}

int main() {

 fin>>n;

 for (i=1;i<=n;i++) {

  fin>>v[i].first;

  v[i].second=i;

 }

 sort(v+1,v+n+1);

 for (i=1;i<=n;i++) {

  if (v[i].first==v[i-1].first) {

   w[v[i].second]=w[v[i-1].second];

   cnt++;

  }

  else

   w[v[i].second]=i-cnt;

 }

 for (i=1;i<=n;i++) {

  sol=(sol+query(n-cnt)-query(w[i]))%9917;

  update(w[i]);

 }

 fout<<sol%9917;

 return 0;

}

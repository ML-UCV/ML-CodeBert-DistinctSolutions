#include <fstream>
#include <cstring>




using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

long long n,m,i,s[125][50010],fa[125],fb[125],f[50010],k,sol;

char a[50010],b[50010];

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

 fin>>a+1>>b+1;

 n=strlen(a+1), m=strlen(b+1);

 if (n!=m) {

  fout<<"-1";

  return 0;

 }

 for (i=1;i<=n;i++) {

  s[a[i]][++fa[a[i]]]=i;

  fb[b[i]]++;

 }

 for (i='a';i<='z';i++) {

  if (fa[i]!=fb[i]) {

   fout<<"-1";

   return 0;

  }

  fb[i]=0;

 }

 for (i=1;i<=n;i++) {

  k=query(s[b[i]][++fb[b[i]]]);

  sol+=(i-1-k);

  update(s[b[i]][fb[b[i]]]);

 }

 fout<<sol;

 return 0;

}

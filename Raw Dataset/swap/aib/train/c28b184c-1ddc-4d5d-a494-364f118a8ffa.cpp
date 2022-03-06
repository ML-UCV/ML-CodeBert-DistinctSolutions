#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;





char s[50010];

int a[50010], b[50010], v[50010], d[30], n, aib[50010], sol;

vector <int> c[30];



void update(int p)

{

 do

 {

  aib[p]++;

  p += (p&(p-1))^p;

 }

 while (p<=n);

}



int query(int p)

{

 int s=0;

 do

 {

  s+=aib[p];

  p=p&(p-1);

 }

 while (p);

 return s;

}



int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 fgets(s,50010,stdin);

 n=strlen(s);

 n--;

 int i, ok=0;

 for (i=0; i<n; i++) a[i+1]=s[i]-'a'+1;

 fgets(s,50010,stdin);

 for (i=0; i<n; i++) b[i+1]=s[i]-'a'+1;

 for (i=1; i<=n; i++)

  c[a[i]].push_back(i);

 for (i=1; i<=n; i++)

 {

  if (d[b[i]]==c[b[i]].size())

  {

   ok=1;

   break;

  }

  v[c[b[i]][d[b[i]]]]=i;

  d[b[i]]++;

 }

 if (ok)

 {

  printf("-1\n");

  return 0;

 }

 for (i=1; i<=n; i++)

 {

  update(v[i]);

  sol+=i-query(v[i]);

 }

 printf("%d\n",sol);

}

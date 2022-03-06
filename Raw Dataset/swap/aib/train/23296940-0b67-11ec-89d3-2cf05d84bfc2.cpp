#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;







char a[50100],b[50100];

vector<int> p[26];

int x[26], v[50100], n;



void update(int x,int val)

 {

  for(;x<=n;x+=x^(x-1)&x)

   v[x] += val;

 }



int query(int x)

 {

  int r = 0;

  for(;x;x-=x^(x-1)&x)

   r += v[x];

  return r;

 }



int main()

 {

  freopen("swap.in","r",stdin);

  freopen("swap.out","w",stdout);



  int i, tmp, S = 0;



  fgets(a,50100,stdin);

  fgets(b,50100,stdin);



  for(i=0;a[i]!='\n';++i)

   p[a[i]-'a'].push_back(i+1);

  n = i;



  for(i=1;i<=n;++i)

   update(i,1);



  for(i=0;b[i]!='\n';++i)

   {

    if(x[b[i]-'a'] == p[b[i]-'a'].size())

     {

      printf("-1\n");

      return 0;

     }

    tmp = p[b[i]-'a'][x[b[i]-'a']];

    ++x[b[i]-'a'];

    S += query(tmp-1);

    update(tmp,-1);

   }



  printf("%d\n",S);



  return 0;

 }

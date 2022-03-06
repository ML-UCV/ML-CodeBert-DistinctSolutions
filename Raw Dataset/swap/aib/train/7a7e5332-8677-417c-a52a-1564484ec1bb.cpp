#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>


using namespace std;
list <int> v[51001];

char a[51001],b[51001];

int p[51001],aib[51001];

int n;



void citire()

{

 int i,j;

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);



 scanf("%s\n", a+1);

 n=strlen(a+1);

 scanf("%s\n", b+1);

}



void add(int x, int val)

{

    for (;x<=n;x+=((x^(x-1))&x))

      aib[x]+=val;

}



int compute(int x)

{

    int ret=0;

    for (;x>0;x-=((x^(x-1))&x))

      ret+=aib[x];

    return ret;

}



bool verif()

{

 int i;

 int v1[26];

 memset(v1,0,sizeof(v1));

 for (i=1;i<=n;++i)

   v1[a[i]-'a']++;

 for (i=1;i<=n;++i)

   v1[b[i]-'a']--;

 for (i=0;i<26;++i)

   if (v1[i]!=0)

    return false;

 return true;

}



void solve()

{

 int i,rez=0,j,ok;



 for (i=1;i<=n;++i)

      a[i]=a[i]-'a';

 for (i=1;i<=n;++i)

   b[i]=b[i]-'a';

 memset(p,0,sizeof(p));

 int nr=0;

  for (i=1;i<=n;++i)

       v[a[i]].push_back(i);

    for (i=1;i<=n;++i)

    {

  p[i]=*(v[b[i]].begin());

        v[b[i]].pop_front();

 }

 for (i=1;i<=n;++i)

   add(i,1);

 for (i=1;i<=n;++i)

 {

  rez+=compute(p[i]);

  rez-=1;

  add(p[i],-1);

 }



 printf("%d", rez);

}





int main()

{

 citire();

 if (!verif())

  printf("-1\n");

 else

     solve();



 fclose(stdin);

 fclose(stdout);



 return 0;

}

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int nmax=5e4+3;

int n,v[nmax],p[nmax],sol,q[30][nmax],poz[30];

char a[nmax],b[nmax];

inline int usu(int x)

{

      return x&(-x);

}

void update(int x)

{

      while(x<=n)

      {

            ++v[x];

            x+=usu(x);

      }

}

int query(int x)

{

      int sol=0;

      while(x)

      {

            sol+=v[x];

            x-=usu(x);

      }

      return sol;

}

int main()

{

      freopen("swap.in","r",stdin);

      freopen("swap.out","w",stdout);

      scanf("%s",(a+1));

      scanf("%s",(b+1));

    n=strlen(a+1);

    for(int i=1;i<=n;++i) q[a[i]-'a'][++q[a[i]-'a'][0]]=i;

    for(int i=0;i<=26;++i) poz[i]=1;

    for(int i=1;i<=n;++i)

    {

          if(q[b[i]-'a'][0]+1==poz[b[i]-'a'])

          {

                printf("-1");

                return 0;

          }

          p[i]=q[b[i]-'a'][poz[b[i]-'a']];

          ++poz[b[i]-'a'];

    }

    for(int i=1;i<=n;++i)

    {

          sol=sol+i-query(p[i])-1;

          update(p[i]);

    }

    printf("%d",sol);

    return 0;

}

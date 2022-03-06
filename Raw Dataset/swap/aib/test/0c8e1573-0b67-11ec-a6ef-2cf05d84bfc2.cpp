#include <cstdio>
#include <cstring>


using namespace std;

char a[50010],b[50010];

int i,x,AIB[50010],n,c[50010];

int inv,nxt[50010],crt[30],lst[30];

int sum(int p)

{

    int s=0;

    int i;

    for(i=p; i; i-=(i&(-i)))

        s+=AIB[i];

    return s;

}



void add(int p)

{

    int i;

    for(i=p; i<=n; i+=(i&(-i)))

        ++AIB[i];

}



int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    fgets(a, 50001, stdin);

    fgets(b, 50001, stdin);

    n=strlen(a);

    for(i=0; i<n; ++i)

    {

        x=b[i]-'a';

        if(!lst[x])

            crt[x]=i+1;

        nxt[lst[x]]=i+1;

        lst[x]=i+1;

    }

    for(i=0; i<n; ++i)

    {

        x=a[i]-'a';

        if(crt[x])

        {

            c[i+1]=crt[x];

            crt[x]=nxt[crt[x]];

        }

        else

        {

            printf("-1\n");

            return 0;

        }

    }

    for(i=n; i>=1; --i)

    {

        x=c[i];

        inv+=sum(x);

        add(x);

    }

    printf("%d\n",inv);

    return 0;

}

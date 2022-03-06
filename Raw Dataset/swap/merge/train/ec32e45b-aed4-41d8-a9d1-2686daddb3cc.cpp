#include <bits/stdc++.h>




using namespace std;

int aib[50005];

char a[50005],b[50005];

int n,i,j,aux;

int x[50005],y[50005];

int cat1[150][50005];

int cat2[150][50005];

int A[150][50005];

pair<int,int> v[50005];

long long sol;

bool ok;

void interclas(int st,int m,int dr)

{

    int k=0,i=st,j=m+1;

    while(i<=m &&j<=dr)

        if(x[i]<=x[j])y[++k]=x[i++];

        else {y[++k]=x[j++];sol=(sol+m-i+1);}

    while(i<=m)y[++k]=x[i++];

    while(j<=dr)y[++k]=x[j++];

    for(k=1,i=st;i<=dr;i++,k++)x[i]=y[k];

}

void sortt(int st,int dr)

{

    int m;

    if(st<dr)

    {

        m=(dr+st)/2;

        sortt(st,m);

        sortt(m+1,dr);

        interclas(st,m,dr);

    }

}

inline void add(int x)

{

    for(;x<=n;x+=( (x) & ((x)-1)^(x))) aib[x]++;

}

inline int query(int x)

{

    int s=0;

    for(;x;x-=( (x) & ((x)-1)^(x))) s+=aib[x];

    return s;

}

int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    fgets(a+1, 50001, stdin);

    fgets(b+1, 50001, stdin);

    n=strlen(a+1);

    for(i=1;i<=n;i++)

    {

        cat1[a[i]][0]++;



        A[a[i]][cat1[a[i]][0]]=i;

    }

    for(i=1;i<=n;i++)

    {

        cat2[b[i]][0]++;

        aux=cat2[b[i]][0];

        x[i]=v[i].first=A[b[i]][aux];

        v[i].second=i;

        if(!v[i].first)

        {

            printf("-1");

            return 0;

        }

    }
    sortt(1,n);

    printf("%lld",sol);

    return 0;

}

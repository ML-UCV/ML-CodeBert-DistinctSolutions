#include <bits/stdc++.h>


using namespace std;

int s[100001],n,z[100001];

pair <int,int> v[100001];



int zeros(int i)

{

    return (i^(i-1))&i;

}

void add(int p,int x)

{

    for(int i=p; i<=n; i+=zeros(i))

        s[i]+=x;

}

long long sum(int p)

{

    long long rez=0LL;

    for(int i=p; i>0; i-=zeros(i))

        rez+=s[i];

    return rez;

}

int main()

{

    int i,x;

    long long rez=0LL;

    freopen("inv.in","r",stdin);

    freopen("inv.out","w",stdout);

    scanf("%d",&n);

    for(i=1; i<=n; i++)

    {

        scanf("%d",&z[i]);

        v[i].first=z[i];

        v[i].second=i;

    }

    sort(v+1,v+1+n);

    for(i=1; i<=n; i++)

        z[v[i].second]=i;

    for(i=1; i<=n; i++)

    {

        x=z[i];

        rez+=i-1-sum(x-1);

        add(x,1);

    }

    printf("%d",rez%9917);

    return 0;



}

#include <bits/stdc++.h>





using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int v[100001];

pair <int,int> ss[100001];

int AIB[100001];

int n;

void update(int i, int val)

{

    while(i<=n)

    {

        AIB[i]+=val;

        i+=(i&(-i));

    }

}

int query(int i)

{

    int s=0;

    while(i>0)

    {

        s+=AIB[i];

        i-=(i&(-i));

    }

    return s;

}

int main()

{

    ios_base::sync_with_stdio(false);

    int i;

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>ss[i].first;

        ss[i].second=i;

    }

    sort(ss+1,ss+n+1);

    for(i=1;i<=n;i++)

        v[ss[i].second]=i;

    for(i=1;i<=n;i++)

        update(v[i],1);

    int ans=0;

    for(i=1;i<=n;i++)

    {

        ans=(ans+query(v[i])-1+9917)%9917;

        update(v[i],-1);

    }

    g<<ans;



    return 0;

}

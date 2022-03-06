#include<bits/stdc++.h>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int n, v[200005], aib[200005], q, tip, a[200005], p;

long long ans;

unordered_map<int, int>mp;

void update(int nod)

{

    for(int i=nod; i<=n; i+=(i&(-i)))

        aib[i]++;

}

int query(int nod)

{

    int sum=0;

    for(int i=nod; i; i-=(i&(-i)))

        sum+=aib[i];

    return sum;

}

int main()

{

    f>>n;

    for(int i=1; i<=n; i++)

    {

        f>>v[i];

        a[i]=v[i];

    }

    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++)

        if(mp.find(a[i])==mp.end()) mp[a[i]]=++p;

    for(int i=n; i>=1; i--)

    {

        ans=(ans+query(mp[v[i]]-1))%9917;

        update(mp[v[i]]);

    }

    g<<ans%9917;

    return 0;

}

#include <bits/stdc++.h>
using namespace std;

ifstream f("schi.in"); ofstream g("schi.out");



int aib[30001],v[30001],sol[30001],n;

void update(int x)

{ for(int i=x;i<=n;i+=(i&(-i))) aib[i]--; }

int query(int poz)

{ int T=0;

    for(int i=poz;i;i-=(i&(-i))) T+=aib[i];

    return T;

}

int cautbin(int x)

{ int S=1,D=n,T=0,Minim=INT_MAX;

    while(S<=D)

    { int mid=(S+D)/2;

        T=query(mid);

        if(T==x && mid<Minim) Minim=mid;

        else if(T>=x) D=mid-1;

        else S=mid+1;

    }

    return Minim;

}

int main()

{ f>>n;

    for(int i=1;i<=n;i++) f>>v[i];

    for(int i=1;i<=n;i++) aib[i]=(i&(-i));

    for(int x,i=n;i;--i)

    { x=cautbin(v[i]);

        sol[x]=i;

        update(x);

    }

    for(int i=1;i<=n;i++) g<<sol[i]<<'\n';

    g.close();

    return 0;

}
